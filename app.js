var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const jwt = require('jsonwebtoken');

var app = express();


app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, function(err, user) {
  
      if (err) return res.sendStatus(403)

      req.user = user
  
      next()
    })
  }



const loginRouter = require('./routes/login');
app.use('/login', loginRouter);

app.use(authenticateToken);

var userRouter = require('./routes/user');
app.use('/user', userRouter);

const bookRouter = require('./routes/book');
app.use('/book', bookRouter);

app.use(express.json());

app.use(express.urlencoded({ extended: false }));


module.exports = app;