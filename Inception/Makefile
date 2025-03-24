all: up

# Setup /etc/hosts before starting containers
setup-hosts:
	@if ! grep -qE '^127\.0\.0\.1[[:space:]]+kyeh\.42\.fr[[:space:]]+adminer\.kyeh\.42\.fr[[:space:]]+prometheus\.kyeh\.42\.fr[[:space:]]+grafana\.kyeh\.42\.fr' /etc/hosts; then \
		echo "127.0.0.1 kyeh.42.fr adminer.kyeh.42.fr prometheus.kyeh.42.fr grafana.kyeh.42.fr" | sudo tee -a /etc/hosts; \
		echo "Updated /etc/hosts"; \
	else \
		echo "/etc/hosts already updated."; \
	fi

up:	setup-hosts
	@mkdir -p ${HOME}/data/mariadb_data
	@mkdir -p ${HOME}/data/wordpress_data
	@mkdir -p ${HOME}/data/monitoring_data/prometheus
	@docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	@docker compose -f ./srcs/docker-compose.yml down

stop:
	@docker compose -f ./srcs/docker-compose.yml stop

start:
	@docker compose -f ./srcs/docker-compose.yml start

status:
	@docker compose -f ./srcs/docker-compose.yml ps

clean: down
	@docker compose -f ./srcs/docker-compose.yml down -v
	@sudo rm -rf ${HOME}/data/mariadb_data
	@sudo rm -rf ${HOME}/data/wordpress_data
	@sudo rm -rf ${HOME}/data/monitoring_data
	@docker system prune -f
re:	clean up

# Adminer:
#	https://adminer.kyeh.42.fr/
# Grafana: (need to wait a bit to start)
#	https://grafana.kyeh.42.fr/
# Prometheus:
#	https://prometheus.kyeh.42.fr/status

# docker-compose ps:
#	make status
# DNS Fixes:
#	echo "127.0.0.1 kyeh.42.fr adminer.kyeh.42.fr prometheus.kyeh.42.fr grafana.kyeh.42.fr" | sudo tee -a /etc/hosts
# log in MariaDB:
#	docker exec -it mariadb bash
#	mysql -u root
#	(mysql -u root -pmariadb_root)
# Select the WordPress database and check it's not empty:
#	USE wordpress;
#	SELECT COUNT(*) FROM wp_posts;

# Docker:
# 	A tool to make containers.
# container:
# 	A box that holds a service/applicatioin.
# docker-compose:
# 	Container management sheet.
# 	Without it, we need to build each container with all the parameters by hand.
# Container vs. VM
# 	Container's built with their own dependencies/environment,
# 	so it's a lot lighter, faster and more convenient than VMs, where the whole OS is pacted.