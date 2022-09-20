#include "test.h"
#include <stdlib.h>

int ft_strlen(const char *);
char *ft_strdup(const char *str);

static void do_test_silenlty(const char *str)
{
	char *duplicate = ft_strdup(str);
	assert_strings_are_equal(str, duplicate);
	free(duplicate);
}

static void do_test(const int test_number, const char *str)
{
	print_header("ft_strdup", test_number);

	do_test_silenlty(str);

	print_ok();
}

void test_ft_strdup()
{
	do_test(1, "");
	do_test(2, "1");
	do_test(3, "12345");
	do_test(4, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	do_test(5, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

	print_header("ft_strdup", 6);

	for (int i = 0; i < 100; i++)
		do_test_silenlty("djnsdlcjnsnckjsnckncjnskjncksjncksjnckjnsd");

	print_ok();
}