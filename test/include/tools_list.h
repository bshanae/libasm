#ifndef LIST_H
#define LIST_H

typedef struct s_list
{
	void *data;
	struct s_list *next;
} t_list;

t_list *list_allocate_node(void *data, int data_size);
void list_free_node(t_list *node);
void list_free(t_list *node);
void list_print(const char *prefix, t_list *node);
t_list *list_find_tail(t_list *node);
void list_push_node(t_list *head, t_list *new);
t_list *list_build(int count, ...);
int list_size(t_list *head);

int compare_int(int *a, int *b);

#endif