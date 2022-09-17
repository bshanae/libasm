#include "test.h"
#include <string.h>

int ft_strcmp(const char *a, const char *b);

static void do_test(const int test_number, const char *a, const char *b)
{

	print_header("ft_strcmp", test_number);

	const int expected = strcmp(a, b);
	const int actual = ft_strcmp(a, b);

	assert_integers_are_equal(expected, actual);

	print_ok();
}

void test_ft_strcmp()
{
	do_test(1, "", "");
	do_test(2, "1", "1");
	do_test(3, "1", "2");
	do_test(4, "1", "11");
	do_test(5, "1", "");
	do_test(6, "1", "111");
	do_test(7, "", "111");
	do_test(8, "1", "9");
	do_test(9, "9", "1");
	do_test(10, "1234", "1235");
	do_test(11, "00000001", "00000002");
	do_test(12, "hello world", "hello world");
}