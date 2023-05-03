#include "lists.h"
/**
* sum_listint - calculates the sum of the data in a listint_t list
* @head: first node in the linked list
* Return: result sum
*/
int sum_listint(listint_t *head)
{
int s = 0;
listint_t *tempr = head;
while (tempr)
{
s += tempr->n;
tempr = tempr->next;
}
return (s);
}
