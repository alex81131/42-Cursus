YML	= srcs/docker-compose.yml
WEB	= ${HOME}/data/web
DB	= ${HOME}/data/database

build:
	mkdir -p ${WEB}			# -p: Build necessary parent directories.
	mkdir -p ${DB}
	docker compose -f ${YML} up --build
# -f <file name>:
#	Specifies the FAML file to use.
# up:
#	Creates the containers, networks, and volumes specified 
#	in the YAML file.
# --build:
#	(Re)build images before starting containers.

down:
	docker volume prune --force
	docker builder prune --force			# clear build cache
	docker image prune --force				# clear dangling images
	docker system prune --force --volmues	# clean up unused resources
	docker compose -f ${YML} down -v --remove-orphans
	sudo rm -rf ${WEB}
	sudo rm -rf ${DB}
# build cache:
#	Space saved for building docker images.
# -v = --volumes: 
#	Remove not only containers and networks, but also volumes.
# orphan container:
#	A container not defined in docker-compose.yml but still running.