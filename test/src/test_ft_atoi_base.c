#include "test.h"

int ft_atoi_base(const char *str, int base);

static void do_test(int test_number, const char *str, int base, int expected)
{
	print_header("ft_atoi_base", test_number);

	int actual = ft_atoi_base(str, base);
	assert_integers_are_equal(expected, actual);

	print_ok();
}

void test_ft_atoi_base()
{
	do_test(1, "0", 10, 0);
	do_test(2, "1", 10, 1);
	do_test(3, "2", 10, 2);
	do_test(4, "10", 10, 10);
	do_test(5, "a", 16, 10);
	do_test(6, "A", 16, 10);
	do_test(7, "abcdef", 16, 11259375);
	do_test(8, "10", 8, 8);

	do_test(9, "", 10, 0);
	do_test(10, "123", 0, 0);
	do_test(11, "123", 17, 0);
	do_test(12, "123", 100, 0);
	do_test(13, "123..", 10, 0);
	do_test(14, "12.3..", 10, 0);
	do_test(15, "12_3", 10, 0);
	do_test(16, "p123", 10, 0);
}