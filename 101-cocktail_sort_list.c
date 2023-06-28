#include "sort.h"
/**
*swap - in a doubly linked list a
* two nodes to be swapped
*@a: first node address
*@b: second node address
*Return: Nothing
*/
void swap(listint_t *i, listint_t *j)
{
if (i->prev)
{
i->prev->next = j;
}
if (j->next)
{
j->next->prev = i;
}
i->next = j->next;
j->prev = i->prev;
i->prev = j;
j->next = i;
}
/**
 *tail_traverse- a function that from t a sort is done
 *@h: list head
 *@t: list t
 *@qaima: head of the list that is original
 *Return: of the list new head
 */
listint_t *tail_traverse(listint_t *h, listint_t *t, listint_t *qaima)
{
while (t && t->prev)
{
if (t->n < t->prev->n)
{
swap(t->prev, t);
if (t->prev == NULL)
qaima = t;
print_list(qaima);
}
else
t = t->prev;
if (t->prev == NULL)
h = t;
}
return (h);
}

/**
 *cocktail_sort_list - a function that using cocktail shaker sort
 * to sort the list
 *@list: sort the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *t, *h, *length;
int a = 0, b = 0, tabdel = 1;

if (!list || !*list)
{
return;
}
length = *list;
for (a = 0; length; a++)
{
length = length->next;
}
if (a < 2)
{
return;
}
h = *list;
while (b < a)
{
tabdel = 0;
while (h && h->next)
{
if (h->n > h->next->n)
{
swap(h, h->next);
tabdel++;
if (h->prev->prev == NULL)
{
*list = h->prev;
}
print_list(*list);
}
else
h = h->next;
if (h->next == NULL)
{
t = h;
}
}
h = tail_traverse(h, t, *list);
*list = h;
b++;
}
}
