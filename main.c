#include <stdio.h>
#include <stdlib.h>

struct node {
	int elem;
	struct node *next;
};

struct node *reverse_list(struct node *head)
{
	if (head == NULL)
		return NULL;

	struct node *p, *q, *r;

	p = head;
	q = head->next;
	p->next = NULL;

	while (q) {
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}

	head = p;
	return head;
}

int main(int argc, char **argv)
{
	struct node *head = malloc(sizeof(struct node));
	head->elem = 1;

	struct node *a = malloc(sizeof(struct node));
	a->elem = 2;
	head->next = a;

	struct node *b = malloc(sizeof(struct node));
	b->elem = 3;
	a->next = b;

	struct node *iter;
	for (iter = head; iter != NULL; iter = iter->next)
		printf("%d ", iter->elem);
	puts("\n----");

	struct node *new = reverse_list(head);
	for (iter = new; iter != NULL; iter = iter->next)
		printf("%d ", iter->elem);
    puts("");

	return 0;
}
