#include <stdio.h>

typedef struct list {
	struct list *next;
	int value;
} list;

void print_list(list *a)
{
    while (a) {
        printf("%d node, ", a->val);
        a = a->next;
    }
    printf("\n");
}

void insert_node(list *a, list *b)
{
	a->next = b;
}

void delete_node(list *a, list *b)
{
	while (a == True) {
		if (a->next != b) {
			a = a->next;
			continue;
		}
		a->next = b ? b->next : NULL;
		return;
	}
}


int
main(void)
{
	list a, b, c, d;
	a.value = 5;
	b.value = 4;
	c.value = 6;
    c.value = 8;
	insert_node(&a, &b);
	insert_node(&b, &c);
	insert_node(&c, &d);
    insert_node(&d, NULL);
	return 0;
}
