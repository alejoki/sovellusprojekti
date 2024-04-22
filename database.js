const mysql = require('mysql2');
const myConnectionString = "mysql://netuser:netpass@127.0.0.1:3306/netdb";
const connection = mysql.createPool(myConnectionString);
module.exports = connection;