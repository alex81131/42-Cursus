FROM       debian:bullseye

ENV        DEBIAN_FRONTEND=noninteractive

RUN        apt update && apt upgrade -y && apt install -y \
           mariadb-server \
           gosu

RUN        mkdir -p var/run/mysqld && \
           chown -R mysql:mysql /var/run/mysqld

RUN        sed -i 's/^bind-address\s*=.*$/bind-address = 0.0.0.0/' /etc/mysql/mariadb.conf.d/50-server.cnf

COPY       entrypoint.sh /usr/local/bin/
RUN        chmod +x /usr/local/bin/entrypoint.sh

WORKDIR    /var/lib/mysql

EXPOSE     3306

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
CMD        ["mysqld"]