#include "monty.h"
/**
 * f_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	if (p->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = p->next->n / p->n;
	p->next->n = aux;
	*head = p->next;
	free(p);
}
