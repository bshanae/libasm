# libasm

This is a project for learning assembler. I've recoded some functions from the C Piscine using NASM: 
* ft_read
* ft_write
* ft_strcmp
* ft_strcpy
* ft_strdup
* ft_strlen
* ft_atoi_base
* ft_list_push_front
* ft_list_remove_if
* ft_list_size
* ft_list_sort

## requirements

* macOS
* clang
* NASM

## build

```shell
cd main
make bonus
```

`libasm.a` will be built in `main` directory.

## test

```shell
cd test
make
./test_libasm --auto
```

## resources

* [NASM tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)
* [NASM Assembly Language Tutorials](https://asmtutor.com)
