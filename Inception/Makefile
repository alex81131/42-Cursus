all : up

up :
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

clean:
	@docker compose -f ./srcs/docker-compose.yml down -v
	@sudo rm -rf ${HOME}/data/mariadb_data
	@sudo rm -rf ${HOME}/data/wordpress_data
	@sudo rm -rf ${HOME}/data/monitoring_data
re:	clean up

# docker-compose ps:
#	make status

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