#include "lists.h"
/**
* pop_listint - deletes the head of a linked list
* @head: pointer to the first element in the linked list
* Return: the value inside the elements that was deleted,
* or 0 if the list is empty
*/
int pop_listint(listint_t **head)
{
listint_t *tempr;
int me;
if (!head || !*head)
return (0);
me = (*head)->n;
tempr = (*head)->next;
free(*head);
*head = tempr;
return (me);
}
