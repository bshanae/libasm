#include "test.h"

#include <stddef.h>

int ft_list_size(t_list *head);

void do_test(const int test_number, t_list *list, const int expected_length)
{
	print_header("ft_list_size", test_number);

	const int expected = ft_list_size(list);
	const int actual = list_size(list);

	assert_integers_are_equal(expected, actual);

	print_ok();
}

void test_ft_list_size()
{
	do_test(1, NULL, 0);
	do_test(2, list_build(1), 1);
	do_test(3, list_build(1, 292), 2);
	do_test(4, list_build(2, 292, 282), 3);
	do_test(5, list_build(5, 292, 282, 2, 5, 5), 6);
}