#include <stdio.h>
 
typedef struct node_t *node, node_t;
struct node_t { int v; node next; };
typedef struct { node head, tail; } slist;
 
void push(slist *l, node e) {
	if (!l->head) l->head = e;
	if (l->tail)  l->tail->next = e;
	l->tail = e;
}
 
node removehead(slist *l) {
	node e = l->head;
	if (e) {
		l->head = e->next;
		e->next = 0;
	}
	return e;
}
 
void join(slist *a, slist *b) {
	push(a, b->head);
	a->tail = b->tail;
}
 
void merge(slist *a, slist *b) {
	slist r = {0};
	while (a->head && b->head)
		push(&r, removehead(a->head->v <= b->head->v ? a : b));
 
	join(&r, a->head ? a : b);
	*a = r;
	b->head = b->tail = 0;
}
 
void sort(int *ar, int len)
{
	node_t all[len];
 
	// array to list
	for (int i = 0; i < len; i++)
		all[i].v = ar[i], all[i].next = i < len - 1 ? all + i + 1 : 0;
 
	slist list = {all, all + len - 1}, rem, strand = {0},  res = {0};
 
	for (node e = 0; list.head; list = rem) {
		rem.head = rem.tail = 0;
		while ((e = removehead(&list)))
			push((!strand.head || e->v >= strand.tail->v) ? &strand : &rem, e);
 
		merge(&res, &strand);
	}
 
	// list to array
	for (int i = 0; res.head; i++, res.head = res.head->next)
		ar[i] = res.head->v;
}
 
void show(const char *title, int *x, int len)
{
	printf("%s ", title);
	for (int i = 0; i < len; i++)
		printf("%3d ", x[i]);
	putchar('\n');
}
 
int main(void)
{
	int x[] = {-2,0,-2,5,5,3,-1,-3,5,5,0,2,-4,4,2};
#	define SIZE sizeof(x)/sizeof(int)
 
	show("before sort:", x, SIZE);
	sort(x, sizeof(x)/sizeof(int));
	show("after sort: ", x, SIZE);
 
	return 0;
}