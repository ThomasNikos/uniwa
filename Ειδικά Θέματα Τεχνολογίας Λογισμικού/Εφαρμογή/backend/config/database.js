const { Sequelize } = require('sequelize');

const sequelize = new Sequelize('barbershop', 'comb', '_rm-)C!HJxa(4mi0', {
    host: 'localhost', 
    dialect: 'mysql', 
});

module.exports = sequelize;
