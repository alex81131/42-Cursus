#!/bin/bash
set -eo pipefail

# Initialize MariaDB data directory only if empty
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB data directory..."
    mysqld --initialize-insecure --user=mysql --datadir=/var/lib/mysql
fi

# Start MariaDB in the background
mysqld_safe --datadir=/var/lib/mysql &

# Wait for MariaDB to start
until mysqladmin ping -h"localhost" --silent; do
    echo "Waiting for MariaDB to be ready..."
    sleep 1
done

# Check if database exists
if [ ! -d "/var/lib/mysql/$MYSQL_DATABASE" ]; then
    echo "Setting up MariaDB..."
    
    # Directly set up root user and secure the installation
    mysql -uroot <<EOSQL
    -- Set root password and disable remote root login
    ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASS}';
    DELETE FROM mysql.user WHERE User=''; -- Remove anonymous users
    DROP DATABASE IF EXISTS test; -- Remove test database
    FLUSH PRIVILEGES;

    -- Create initial database and user with privileges
    CREATE USER IF NOT EXISTS 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASS}';
    ALTER USER 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASS}';
    CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
    CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASS}';
    GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
    GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;
    GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' WITH GRANT OPTION;
    FLUSH PRIVILEGES;
EOSQL
    if [ -f /usr/local/bin/wordpress.sql ]; then
        mysql -uroot -p"${MYSQL_ROOT_PASS}" ${MYSQL_DATABASE} < /usr/local/bin/wordpress.sql
    fi
fi

mysqladmin -uroot -p"${MYSQL_ROOT_PASS}" shutdown
exec gosu mysql "$@"