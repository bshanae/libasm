#ifndef ASSERT_H
#define ASSERT_H

#include "tools_list.h"

void assert_integers_are_equal(int expected, int actual);
void assert_strings_are_equal(const char *expected, const char *actual);
void assert_list_has_elements(t_list *node, int count, ...);

#endif