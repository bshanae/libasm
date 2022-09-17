#include "tools_print.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ANSI_BOLD    "\e[1m"
#define ANSI_ITALIC  "\e[3m"
#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_YELLOW  "\x1b[33m"
#define ANSI_BLUE    "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN    "\x1b[36m"
#define ANSI_RESET   "\x1b[0m"

void print_header(const char *function_name, int number)
{
	printf("%s no. %d: ", function_name, number);
	fflush(stdout);
}

void print_ok()
{
	printf(ANSI_GREEN "OK\n" ANSI_RESET);
}

void print_ko()
{
	printf(ANSI_RED "KO\n" ANSI_RESET);
}

void print_end()
{
	printf("\n");
}