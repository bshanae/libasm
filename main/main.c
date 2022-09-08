void print(char *, int);

#include <stdio.h>

int ft_strlen(const char *str);

void test_str(const char *str)
{
	printf("%s : %d\n", str, ft_strlen(str));
}

int main()
{
	test_str("");
	test_str("bla");
	test_str("hello");
	test_str("hello world");
}