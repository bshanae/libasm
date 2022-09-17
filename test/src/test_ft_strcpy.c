#include "test.h"
#include <string.h>

int ft_strcpy(char *destination, const char *source);

static void do_test(int test_number, const char *str)
{
	print_header("ft_strcpy", test_number);

	char buffer[1024];
	bzero(buffer, 1024);

	ft_strcpy(buffer, str);
	assert_strings_are_equal(buffer, str);

	print_ok();
}

void test_ft_strcpy()
{
	do_test(1, "");
	do_test(2, "1");
	do_test(3, "2");
	do_test(4, "hello world");
	do_test(5, "hello world hello world hello world hello world");
}