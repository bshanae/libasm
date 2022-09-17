#include "test.h"

#include <stddef.h>
#include <stdlib.h>

void ft_list_sort(t_list **head, int (*cmp)());

void test_ft_list_sort()
{
	print_header("ft_list_sort", 1);
	{
		t_list *list = NULL;
		ft_list_sort(&list, &compare_int);
		if (list != NULL)
		{
			print_ko();
			exit(1);
		}
	}
	print_ok();

	print_header("ft_list_sort", 2);
	{
		t_list *list = list_build(1, 1);
		ft_list_sort(&list, &compare_int);
		assert_list_has_elements(list, 1, 1);
		list_free(list);
	}
	print_ok();

	print_header("ft_list_sort", 3);
	{
		t_list *list = list_build(2, 1, 2);
		ft_list_sort(&list, &compare_int);
		assert_list_has_elements(list, 2, 1, 2);
		list_free(list);
	}
	print_ok();

	print_header("ft_list_sort", 4);
	{
		t_list *list = list_build(2, 2, 1);
		ft_list_sort(&list, &compare_int);
		assert_list_has_elements(list, 2, 1, 2);
		list_free(list);
	}
	print_ok();

	print_header("ft_list_sort", 5);
	{
		t_list *list = list_build(3, 3, 2, 1);
		ft_list_sort(&list, &compare_int);
		assert_list_has_elements(list, 3, 1, 2, 3);
		list_free(list);
	}
	print_ok();

	print_header("ft_list_sort", 6);
	{
		t_list *list = list_build(3, 2, 3, 1);
		ft_list_sort(&list, &compare_int);
		assert_list_has_elements(list, 3, 1, 2, 3);
		list_free(list);
	}
	print_ok();
}