test:
	nasm -felf64 main/ft_strlen.nasm
	nasm -felf64 main/ft_strcpy.nasm
	gcc main/main.c main/ft_strlen.o main/ft_strcpy.o -o test -no-pie

clean:
	rm -f **/*.o
	rm -f test

re: clean test

env_init: FORCE
	docker rmi -f libasm
	docker image build -t libasm -f env/Dockerfile .

env_exec: FORCE
	docker run -it --rm -e COLUMNS= -e LINES= -v $$PWD:/libasm libasm bash

FORCE: ;