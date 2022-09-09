void print(char *, int);

#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(const char *str);

void test_ft_strpy()
{
	char *s2 = ft_strdup("hello world");
	printf("%p: %s\n", s2, s2);
	free(s2);
}

int main()
{
	for (int i = 0; i < 1000; i++)
		test_ft_strpy();
}