void print(char *, int);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int ft_strlen(const char *str);
char *ft_strcpy(char *dest, const char *src);
char ft_strcmp(const char *a, const char *b);
char *ft_strdup(const char *str);

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

int main()
{
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

	test_ft_strcpy("");
	test_ft_strcpy("1");
	test_ft_strcpy("2");
	test_ft_strcpy("hello world");
	test_ft_strcpy("hello world hello world hello world hello world");

	test_ft_strdup("");
	test_ft_strdup("1");
	test_ft_strdup("2");
	test_ft_strdup("hello world");
	test_ft_strdup("hello world hello world hello world hello world");
}