#include "lists.h"
/**
* insert_nodeint_at_index - enter a new node in a linked list,
* at a given position
* @head: pointer to the first node in the list
* @idx: index where the new node is added
* @n: data to insert in the new node
* Return: pointer to the new node, or NULL
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int a;
listint_t *me;
listint_t *tempr = *head;
me = malloc(sizeof(listint_t));
if (!me || !head)
return (NULL);
me->n = n;
me->next = NULL;
if (idx == 0)
{
me->next = *head;
*head = me;
return (me);
}
for (a = 0; tempr && a < idx; a++)
{
if (a == idx - 1)
{
me->next = tempr->next;
tempr->next = me;
return (me);
}
else
tempr = tempr->next;
}
return (NULL);
}
