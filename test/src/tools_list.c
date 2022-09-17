#include "tools_list.h"

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

t_list *list_allocate_node(void *data, int data_size)
{
	t_list *node = malloc(sizeof(t_list));
	node->data = malloc(data_size);
	node->next = NULL;
	memcpy(node->data, data, data_size);

	return node;
}

void list_free_node(t_list *node)
{
	free(node);
}

void list_free(t_list *node)
{
	while (node != NULL)
	{
		t_list *next = node->next;

		list_free_node(node);
		node = next;
	}
}

void list_print(const char *prefix, t_list *node)
{
	printf("%s:\n", prefix);

	while (node != NULL)
	{
		printf("%p: %d\n", node, *(int *)node->data);
		node = node->next;
	}

	printf("\n");
}

t_list *list_find_tail(t_list *node)
{
	while (node->next != NULL)
		node = node->next;

	return node;
}

void list_push_node(t_list *head, t_list *new)
{
	t_list *tail = list_find_tail(head);
	tail->next = new;
}

t_list *list_build(int count, ...)
{
	t_list *head = NULL;

	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++)
	{
		int item = va_arg(args, int);	
		t_list *node = list_allocate_node(&item, sizeof(int));

		if (head == NULL)
			head = node;
		else
			list_push_node(head, node);
	}
	

	va_end(args);

	return head;
}

int list_size(t_list *head)
{
	int count = 0;

	while (head != NULL)
	{
		head = head->next;
		count++;
	}

	return count;
}

int compare_int(int *a, int *b)
{
	return *a - *b;
}