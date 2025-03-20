FROM debian:bullseye

RUN apt update -y && apt upgrade -y && apt install -y \
	openssl \
	nginx

RUN mkdir -p /etc/nginx/ssl && \
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
		-keyout /etc/nginx/ssl/server.key \
		-out /etc/nginx/ssl/server.crt \
		-subj "/CN=kyeh.42.fr"
# -x509: Generates a self-signed certificate (not a certificate signing request).
# -nodes: Skips passphrase protection for the private key.
# -days 365: Sets the certificate validity to 1 year.
# -newkey rsa:2048: Generates a new 2048-bit RSA private key.
# -keyout /etc/nginx/ssl/server.key: Saves the private key to this file.
# -out /etc/nginx/ssl/server.crt: Saves the certificate to this file.
# -subj "/CN=kyeh.42.fr": Sets the Common Name (CN) to kyeh.42.fr.
RUN mkdir -p /var/www/html && \
	chmod -R 777 /var/www/html && \
	chown -R www-data:www-data /var/www/html

COPY ./nginx.conf /etc/nginx/nginx.conf

WORKDIR /var/www/html

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]