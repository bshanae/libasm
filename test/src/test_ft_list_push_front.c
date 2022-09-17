#include "test.h"

#include <stddef.h>

void ft_list_push_front(t_list **head_ptr, const void *data);

void test_ft_list_push_front()
{
	const int i0 = 21;

	print_header("ft_list_push_front", 1);
	{
		t_list *list = NULL;
		ft_list_push_front(&list, &i0);
		assert_list_has_elements(list, 1, i0);
		list_free(list);
	}
	print_ok();

	print_header("ft_list_push_front", 2);
	{
		t_list *list = list_build(1, 1);
		ft_list_push_front(&list, &i0);
		assert_list_has_elements(list, 2, i0, 1);
		list_free(list);
	}
	print_ok();

	print_header("ft_list_push_front", 3);
	{
		t_list *list = list_build(2, 1, 2);
		ft_list_push_front(&list, &i0);
		assert_list_has_elements(list, 3, i0, 1, 2);
		list_free(list);
	}
	print_ok();
}