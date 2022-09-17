#include "test.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void print_usage()
{
	printf("./test_libasm [--auto|--manual]\n");
	printf("\n");
	printf("--auto    :  Run automatic tests.\n");
	printf("--manual  :  Run manual tests.\n");
}

void run_automatic_tests()
{
	test_ft_strlen();
	print_end();
	test_ft_strcpy();
	print_end();
	test_ft_strcmp();
	print_end();
	test_ft_strdup();
	print_end();
	test_ft_atoi_base();
	print_end();
	test_ft_list_push_front();
	print_end();
	test_ft_list_size();
	print_end();
	test_ft_list_sort();
	print_end();
	test_ft_list_remove_if();
}

void run_manual_tests()
{
	test_ft_read_and_ft_read_write();
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		print_usage();
		exit(1);
	}

	if (strcmp(argv[1], "--auto") == 0)
	{
		run_automatic_tests();
	}
	else if (strcmp(argv[1], "--manual") == 0)
	{
		run_manual_tests();
	}
	else
	{
		print_usage();
		exit(1);
	}

	return 0;
}