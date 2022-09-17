#include "test.h"

#include <stdlib.h>

void ft_list_remove_if(t_list **head_ptr, void *data_ref, int (*cmp)());

void test_ft_list_remove_if()
{
	int i0 = 0;

	print_header("ft_list_remove_if", 1);
	{
		i0 = 1;

		t_list *list = NULL;
		ft_list_remove_if(&list, &i0, &compare_int);
		if (list != NULL)
		{
			print_ko();
			exit(1);
		}
	}
	print_ok();

	print_header("ft_list_remove_if", 2);
	{
		i0 = 21;

		t_list *list = list_build(1, 21);
		ft_list_remove_if(&list, &i0, &compare_int);
		if (list != NULL)
		{
			print_ko();
			exit(1);
		}
		list_free(list);
	}
	print_ok();

	print_header("ft_list_remove_if", 3);
	{
		i0 = 1;

		t_list *list = list_build(2, 1, 21);
		ft_list_remove_if(&list, &i0, &compare_int);
		assert_list_has_elements(list, 1, 21);
		list_free(list);
	}
	print_ok();

	print_header("ft_list_remove_if", 4);
	{
		i0 = 21;

		t_list *list = list_build(2, 1, 21);
		ft_list_remove_if(&list, &i0, &compare_int);
		assert_list_has_elements(list, 1, 1);
		list_free(list);
	}
	print_ok();

	print_header("ft_list_remove_if", 5);
	{
		i0 = 2;

		t_list *list = list_build(3, 1, 2, 3);
		ft_list_remove_if(&list, &i0, &compare_int);
		assert_list_has_elements(list, 2, 1, 3);
		list_free(list);
	}
	print_ok();

	print_header("ft_list_remove_if", 6);
	{
		i0 = 3;

		t_list *list = list_build(3, 1, 2, 3);
		ft_list_remove_if(&list, &i0, &compare_int);
		assert_list_has_elements(list, 2, 1, 2);
		list_free(list);
	}
	print_ok();

	print_header("ft_list_remove_if", 7);
	{
		i0 = 8;

		t_list *list = list_build(3, 1, 2, 3);
		ft_list_remove_if(&list, &i0, &compare_int);
		assert_list_has_elements(list, 3, 1, 2, 3);
		list_free(list);
	}
	print_ok();
}