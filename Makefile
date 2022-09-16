test:
	nasm -felf64 main/ft_strlen.nasm
	nasm -felf64 main/ft_strcmp.nasm
	nasm -felf64 main/ft_strcpy.nasm
	nasm -felf64 main/ft_strdup.nasm
	nasm -felf64 main/ft_read.nasm
	nasm -felf64 main/ft_write.nasm
	nasm -felf64 main/ft_list_push_front.nasm
	nasm -felf64 main/ft_list_sort.nasm
	nasm -felf64 main/ft_list_remove_if.nasm
	nasm -felf64 main/ft_list_size.nasm
	nasm -felf64 main/ft_atoi_base.nasm

	gcc main/main.c 				\
		main/ft_strlen.o			\
		main/ft_strcpy.o 			\
		main/ft_strcmp.o 			\
		main/ft_strdup.o 			\
		main/ft_read.o 		    	\
		main/ft_write.o 			\
		main/ft_list_push_front.o	\
		main/ft_list_sort.o	        \
		main/ft_list_remove_if.o    \
		main/ft_list_size.o	        \
		main/ft_atoi_base.o			\
		-o test 					\
		-no-pie

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