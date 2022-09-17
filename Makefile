env_init: FORCE
	docker rmi -f libasm
	docker image build -t libasm -f env/Dockerfile .

env_start: FORCE
	docker run -it --rm -e COLUMNS= -e LINES= -v $$PWD:/libasm libasm bash

FORCE: ;