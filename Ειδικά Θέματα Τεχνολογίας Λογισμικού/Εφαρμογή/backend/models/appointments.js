const { DataTypes } = require('sequelize');
const sequelize = require('../config/database');
const Users = require('./users');

const Appointments = sequelize.define('Appointments', {
    id: {
        type: DataTypes.INTEGER,
        autoIncrement: true,
        primaryKey: true,
    },
    username: {
        type: DataTypes.STRING,
        allowNull: false,
        references: {
            model: Users,
            key: 'username'
        }
    },
    date: {
        type: DataTypes.DATE,
        allowNull: false,
    },
    employee: {
        type: DataTypes.STRING,
        allowNull: false,
    },
    type: {
        type: DataTypes.STRING,
        allowNull: false,
    }
}, {
    tableName: 'appointments',
    timestamps: false,
    indexes: [
        {
            unique: true,
            fields: ['date', 'employee']
        }
    ]
});

Appointments.belongsTo(Users, {
    foreignKey: 'username',
    targetKey: 'username'
});

module.exports = Appointments;