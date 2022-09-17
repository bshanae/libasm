#include "test.h"
#include <stdio.h>

int ft_read(int fd, const char *buffer, int buffer_size);
void ft_write(int fd, const char *str, int size);

void test_ft_read_and_ft_read_write()
{
	printf("Test on ft_read and ft_write. Write something and press enter:\n");

	char buffer[128];
	int read;
	while ((read = ft_read(0, buffer, 128)) != 0)
	{
		ft_write(1, "$", 1);
		ft_write(1, buffer, read);
	}
}