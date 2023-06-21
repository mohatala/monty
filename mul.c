#include "monty.h"
/**
 * f_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *p;
	int len = 0, aux;
	p = *head;
	while (p)
	{
		p = p->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	aux = p->next->n * p->n;
	p->next->n = aux;
	*head = p->next;
	free(p);
}
