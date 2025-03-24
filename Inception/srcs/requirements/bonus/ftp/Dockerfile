FROM debian:bullseye

ARG FTP_USER
ARG FTP_PASS

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y vsftpd

RUN mkdir -p /var/run/vsftpd/empty && \
    chmod 755 /var/run/vsftpd/empty && \
    mkdir -p /var/www/html && \
    chmod 775 /var/www/html

# Add FTP user and set permissions
RUN useradd -m -d /var/www/html -G www-data ${FTP_USER} && \
    chown -R www-data:www-data /var/www/html && \
    echo "${FTP_USER}:${FTP_PASS}" | chpasswd && \
    chmod 755 /var/www/html

COPY vsftpd.conf /etc/vsftpd.conf
RUN chmod 644 /etc/vsftpd.conf

# Create user list file for vsftpd
RUN echo "$FTP_USER" > /etc/vsftpd.userlist && \
    chmod 644 /etc/vsftpd.userlist

EXPOSE 20 21 30000-30100

CMD ["/usr/sbin/vsftpd", "/etc/vsftpd.conf"]