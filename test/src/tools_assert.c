#include "tools_assert.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "tools_list.h"

void assert_integers_are_equal(int expected, int actual)
{
	if (expected != actual)
	{
		printf("Assertion fail. Expected %i, got %i.\n", expected, actual);
		exit(1);
	}
}

void assert_strings_are_equal(const char *expected, const char *actual)
{
	if (strcmp(expected, actual))
	{
		printf("Assertion fail. Expected '%s', got '%s'.\n", expected, actual);
		exit(1);
	}
}

void assert_list_has_elements(t_list *node, int count, ...)
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