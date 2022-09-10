void print(char *, int);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdarg.h>

int ft_strlen(const char *str);
char *ft_strcpy(char *dest, const char *src);
char ft_strcmp(const char *a, const char *b);
char *ft_strdup(const char *str);
int ft_read(int fd, const char *buffer, int buffer_size);
void ft_write(int fd, const char *str, int size);

void asset_strings_are_equal(const char *a, const char *b)
{
	const char *a_begin = a;	
	const char *b_begin = b;

	while (*a != 0 && *b != 0)
	{
		if (*a != *b)
		{
			printf("Assertion fail. Strings are not equal: '%s', '%s'\n", a_begin, b_begin);
			exit(1);
		}

		if (*a == 0 || *b == 0)
			break;

		a++;
		b++;
	}
}

void test_ft_strcpy(const char *str)
{
	static int id = 1;
	printf("Test on ft_strcpy %d:\n", id++);

	char buffer[1024];
	bzero(buffer, 1024);

	ft_strcpy(buffer, str);
	asset_strings_are_equal(buffer, str);

	printf("OK\n");
}


void test_ft_strcmp(const char *a, const char *b)
{
	static int id = 1;
	printf("Test on ft_strcmp %d:\n", id++);

	const int result = strcmp(a, b);
	const int ft_result = ft_strcmp(a, b);

	if (result != ft_result)
	{
		printf("Error! Expected %d, got %d\n", result, ft_result);
		exit(1);
	}

	printf("OK\n");
}


void test_ft_strdup(const char *str)
{
	static int id = 1;
	printf("Test on ft_strdup %d:\n", id++);

	char *dup = ft_strdup(str);
	asset_strings_are_equal(str, dup);
	free(dup);

	printf("OK\n");
}

typedef struct s_list
{
	void *data;
	struct s_list *next;
} t_list;

void ft_list_push_front(t_list **head_ptr, void *data);
int ft_list_size(t_list *head_ptr);
void ft_list_sort(t_list **head_ptr, int (*cmp)());
void ft_list_remove_if(t_list **head_ptr, void *data_ref, int (*cmp)());

void _ft_list_sort(t_list **head_ptr, int (*cmp)())
{
	ft_list_sort(head_ptr, cmp);
	return;

	if (head_ptr == NULL)
		return;

	t_list *ceiling = NULL;
	while (*head_ptr != ceiling)
	{
		t_list *node = *head_ptr;
		while (node->next != ceiling)
		{
			if (cmp(node->data, node->next->data) > 0) 
			{
				void *temp = node->data;

				node->data = node->next->data;
				node->next->data = temp;
			}

			node = node->next;
		}

		ceiling = node;
	}
}

t_list *alloc_list_node(void *data, size_t data_size)
{
	t_list *node = malloc(sizeof(t_list));
	node->data = malloc(data_size);
	node->next = NULL;
	memcpy(node->data, data, data_size);

	return node;
}

void free_list_node(t_list *node)
{
	free(node->data);
	free(node);
}

void free_list(t_list *node)
{
	while (node != NULL)
	{
		t_list *next = node->next;

		free_list_node(node);
		node = next;
	}
}

void print_list(const char *prefix, t_list *node)
{
	printf("%s: ", prefix);

	while (node != NULL)
	{
		printf("%d ", *(int *)node->data);
		node = node->next;
	}

	printf("\n");
}

t_list *find_list_tail(t_list *node)
{
	while (node->next != NULL)
		node = node->next;

	return node;
}

void list_push_node(t_list *head, t_list *new)
{
	t_list *tail = find_list_tail(head);
	tail->next = new;
}

t_list *build_list(int count, ...)
{
	t_list *head = NULL;

	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++)
	{
		int item = va_arg(args, int);	
		t_list *node = alloc_list_node(&item, sizeof(int));

		if (head == NULL)
			head = node;
		else
			list_push_node(head, node);
	}
	

	va_end(args);

	return head;
}

void compare_list(t_list *node, int count, ...)
{
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++)
	{
		if (node == NULL)
		{
			printf("Unexpected end of the list!\n");
			exit(1);
		}

		int ref = va_arg(args, int);
		int *real = node->data;

		if (ref != *real)
		{
			printf("Expected value %d at index %d, got %d!\n", ref, i, *real);
			exit(1);
		}

		node = node->next;
	}
	

	va_end(args);
}

void asset_list_has_size(t_list *node, int expected)
{
	int actual = ft_list_size(node);
	if (actual != expected)
	{
		printf("Expected list size to be %d, but was %d!\n", expected, actual);
		exit(1);
	}
}

int *allocate_int(int value)
{
	int *ptr = malloc(sizeof(int));
	*ptr = value;

	return ptr;
}

int int_buffer;
int *allocate_int_static(int value)
{
	int_buffer = value;
	return &int_buffer;
}

int compare_int(int *a, int *b)
{
	return *a - *b;
}

void mark(int id)
{
	printf("M%d\n", id);
}

int main()
{
	// ft_strcmp

	test_ft_strcmp("", "");
	test_ft_strcmp("1", "1");
	test_ft_strcmp("1", "2");
	test_ft_strcmp("1", "11");
	test_ft_strcmp("1", "");
	test_ft_strcmp("1", "111");
	test_ft_strcmp("", "111");
	test_ft_strcmp("1", "9");
	test_ft_strcmp("9", "1");
	test_ft_strcmp("1234", "1235");
	test_ft_strcmp("00000001", "00000002");
	test_ft_strcmp("hello world", "hello world");

	// ft_strcpy

	test_ft_strcpy("");
	test_ft_strcpy("1");
	test_ft_strcpy("2");
	test_ft_strcpy("hello world");
	test_ft_strcpy("hello world hello world hello world hello world");

	// ft_list_push_front

	printf("Test on ft_list_push_front 1\n");

	t_list *l1 = NULL;
	ft_list_push_front(&l1, allocate_int(21));
	compare_list(l1, 1, 21);
	free_list(l1);

	printf("Test on ft_list_push_front 2\n");

	t_list *l2 = build_list(1, 1);
	compare_list(l2, 1, 1);
	ft_list_push_front(&l2, allocate_int(21));
	compare_list(l2, 2, 21, 1);
	free_list(l2);

	// ft_list_size

	printf("Test on ft_list_size 1\n");

	t_list *l3 = NULL;
	asset_list_has_size(l3, 0);

	printf("Test on ft_list_size 2\n");

	t_list *l4 = build_list(1, 292);
	asset_list_has_size(l4, 1);
	free_list(l4);

	printf("Test on ft_list_size 3\n");

	t_list *l5 = build_list(2, 292, 282);
	asset_list_has_size(l5, 2);
	free_list(l5);

	printf("Test on ft_list_size 4\n");

	t_list *l6 = build_list(5, 292, 282, 2, 5, 5);
	asset_list_has_size(l6, 5);
	free_list(l6);

	// ft_list_remove_if

	printf("Test on ft_list_remove_if 1\n");

	t_list *l7 = NULL;
	ft_list_remove_if(&l7, allocate_int_static(1), &compare_int);
	if (l7 == NULL)
	{
		printf("OK\n");
	}
	else
	{
		printf("FAILED\n");
		exit(1);
	}

	printf("Test on ft_list_remove_if 2\n");

	t_list *l8 = build_list(1, 21);
	ft_list_remove_if(&l8, allocate_int_static(21), &compare_int);
	if (l8 == NULL)
	{
		printf("OK\n");
	}
	else
	{
		printf("FAILED\n");
		exit(1);
	}
	free_list(l8);

	printf("Test on ft_list_remove_if 3\n");

	t_list *l9 = build_list(2, 1, 21);
	ft_list_remove_if(&l9, allocate_int_static(1), &compare_int);
	compare_list(l9, 1, 21);
	free_list(l9);

	printf("OK\n");

	printf("Test on ft_list_remove_if 4\n");

	t_list *l10 = build_list(2, 1, 21);
	ft_list_remove_if(&l10, allocate_int_static(21), &compare_int);
	compare_list(l10, 1, 1);
	free_list(l10);

	printf("OK\n");

	printf("Test on ft_list_remove_if 5\n");

	t_list *l11 = build_list(3, 1, 2, 3);
	ft_list_remove_if(&l11, allocate_int_static(2), &compare_int);
	compare_list(l11, 2, 1, 3);
	free_list(l11);

	printf("OK\n");

	printf("Test on ft_list_remove_if 6\n");

	t_list *l12 = build_list(3, 1, 2, 3);
	ft_list_remove_if(&l12, allocate_int_static(3), &compare_int);
	compare_list(l12, 2, 1, 2);
	free_list(l12);

	printf("OK\n");

	printf("Test on ft_list_remove_if 7\n");

	t_list *l13 = build_list(3, 1, 2, 3);
	ft_list_remove_if(&l13, allocate_int_static(8), &compare_int);
	compare_list(l13, 3, 1, 2, 3);
	free_list(l13);

	printf("OK\n");

	// ft_list_sort

	printf("Test on ft_list_sort 1\n");

	t_list *l14 = NULL;
	_ft_list_sort(&l14, &compare_int);
	if (l14 == NULL)
	{
		printf("OK\n");
	}
	else
	{
		printf("FAILED\n");
		exit(1);
	}

	printf("Test on ft_list_sort 2\n");

	t_list *l15 = build_list(1, 1);
	_ft_list_sort(&l15, &compare_int);
	compare_list(l15, 1, 1);
	free_list(l15);

	printf("OK\n");

	printf("Test on ft_list_sort 3\n");

	t_list *l16 = build_list(2, 1, 2);
	_ft_list_sort(&l16, &compare_int);
	compare_list(l16, 2, 1, 2);
	free_list(l16);

	printf("OK\n");

	printf("Test on ft_list_sort 4\n");

	t_list *l17 = build_list(2, 2, 1);
	_ft_list_sort(&l17, &compare_int);
	compare_list(l17, 2, 1, 2);
	free_list(l17);

	printf("OK\n");

	printf("Test on ft_list_sort 5\n");

	t_list *l18 = build_list(3, 3, 2, 1);
	print_list("l18", l18);
	_ft_list_sort(&l18, &compare_int);
	compare_list(l18, 3, 1, 2, 3);
	free_list(l18);

	printf("OK\n");

	printf("Test on ft_list_sort 6\n");

	t_list *l19 = build_list(3, 2, 3, 1);
	_ft_list_sort(&l19, &compare_int);
	compare_list(l19, 3, 1, 2, 3);
	free_list(l19);

	printf("OK\n");

	// ft_read, ft_write

	printf("Test on ft_read and ft_write\n");

	char buffer[128];
	int read;
	while ((read = ft_read(0, buffer, 128)) != 0)
	{
		ft_write(1, "$", 1);
		ft_write(1, buffer, read);
	}
}