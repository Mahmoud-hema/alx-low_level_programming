#include "lists.h"
#include <stdio.h>
size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);
/**
* looped_listint_len - Count the number of unique nodes
* in a looped listint_t linked list.
* @head: A pointer to the head of the listint_t to check.
* Return: If the list is not looped - 0.
* Or - the number of unique nodes in the list.
*/
size_t looped_listint_len(const listint_t *head)
{
const listint_t *t, *h;
size_t no = 1;
if (head == NULL || head->next == NULL)
return (0);
t = head->next;
h = (head->next)->next;
while (h)
{
if (t == h)
{
t = head;
while (t != h)
{
no++;
t = t->next;
h = h->next;
}
t = t->next;
while (t != h)
{
no++;
t = t->next;
}
return (no);
}
t = t->next;
h = (h->next)->next;
}
return (0);
}
/**
* print_listint_safe - Prints a listint_t list safely.
* @head: A pointer to the head of the listint_t list.
* Return: The number of nodes in the list.
*/
size_t print_listint_safe(const listint_t *head)
{
size_t no, index = 0;
no = looped_listint_len(head);
if (no == 0)
{
for (; head != NULL; no++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
}
else
{
for (index = 0; index < no; index++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
printf("-> [%p] %d\n", (void *)head, head->n);
}
return (no);
}
