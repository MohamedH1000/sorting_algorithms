#include "sort.h"

/**
 * swap - in a doubly linked list a two nodes
 * to be swapped
 * @i: the first node address
 * @j: the second node address
 * Return: nothing
 */
 void swap(listint_t *i, listint_t *j)
 {
     if(i->prev)
     {
         i->prev->next = j;
     }
     if(j->next)
     {
         j->next->prev = i;
     }
     i->next = j->next;
     j->prev = i->prev;
     i->prev = j;
     j->next = i;

 }
 /**
 * insertion_sort_list - a doubly linked list to be
 * sorted by insertion
 * @list: head node pointer address
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *a, *b;

	if(!list || !*list || !(*list)->next)
    {
        return;
    }
    a = (*list)->next;
    while(a)
    {
        b = a;
        a = a->next;
        while(b && b->prev)
        {
            if(b->prev->n > b->n)
            {
                swap(b->prev, b);
                if(!b->prev)
                {
                    *list = b;
                }
                print_list((const listint_t *)*list);
            }
            else
            {
                b = b->prev;
            }
        }
    }
}
