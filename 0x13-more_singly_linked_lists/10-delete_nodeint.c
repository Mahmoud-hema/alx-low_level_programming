#include "lists.h"
/**
* delete_nodeint_at_index - remove a node in a linked list at a certain index
* @head: pointer to the first element in the list
* @index: index of the node to delete
* Return: 1 (Success), or -1 (Fail)
*/
int delete_nodeint_at_index(listint_t **head,unsigned  int index)
{
listint_t *tempr = *head;
listint_t *c = NULL;
unsigned int a = 0;
if (*head == NULL)
return (-1);
if (index == 0)
{
*head = (*head)->next;
free(tempr);
return (1);
}
while (a < index - 1)
{
if (!tempr || !(tempr->next))
return (-1);
tempr = tempr->next;
a++;
}
c = tempr->next;
tempr->next = c->next;
free(c);
return (1);
}
