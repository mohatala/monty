#include "monty.h"

/**
* f_opcode - find opcode
* @stack: stack pointer
* @opcode: user input opcode
* @counter: line number
* Return: Always 1 (Success) or stderr
**/
int f_opcode(stack_t **stack, char *opcode, int counter)
{
instruction_t opcodes[] = {
{"pall", f_pall},
{"pop", f_pop},
{"swap", f_swap},
{"pint", f_pint},
{NULL, NULL}
};

int j;

for (j = 0; opcodes[j].opcode; j++)
{
if (strcmp(opcode, opcodes[j].opcode) == 0)
{
(opcodes[j].f)(stack, counter);
return (EXIT_SUCCESS);
}
}
fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
exit(EXIT_FAILURE);
}
