#include "lists.h"
/**
* add_nodeint_end - adds a node at the end of a linked list
* @head: pointer to the first element in the list
* @n: data to insert in the new element
* Return: pointer to the new node, or NULL if it fails
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *me;
listint_t *tempr = *head;
me = malloc(sizeof(listint_t));
if (!me)
return (NULL);
me->n = n;
me->next = NULL;
if (*head == NULL)
{
*head = me;
return (me);
}
while (tempr->next)
tempr = tempr->next;
tempr->next = me;
return (me);
}
