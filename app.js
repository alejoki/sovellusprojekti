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

const loginRouter = require('./routes/login');
app.use('/login', loginRouter);

var userRouter = require('./routes/user');
app.use('/user', userRouter);

const bookRouter = require('./routes/book');
app.use('/book', bookRouter);

const carRouter = require('./routes/car');
app.use('/car', carRouter);

app.use(express.json());

app.use(express.urlencoded({ extended: false }));


module.exports = app;
