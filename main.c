#include "monty.h"
#define MAX_LINE_LENGTH 256
#define DELIMITER " \t\n"

/**
* main - Process Monty byte codes
* @argc: size of argv
* @argv: A double pointer contain the arguments
* Return: EXIT_SUCCESS if no errors or EXIT_FAILURE
**/

int main(__attribute__((unused)) int argc, char const *argv[])
{
FILE *mf;
char *buff = NULL, *opcode, *n;
int count = 0;
stack_t *stack = NULL, *current;
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return EXIT_FAILURE;
}

mf = fopen(argv[1], "r");
if (mf == NULL) {
fprintf(stderr, "Error: can't open file %s\n", argv[1]);
exit(1);
}

buff = malloc(MAX_LINE_LENGTH);
if (buff == NULL) {
fprintf(stderr, "Error: memory allocation failed\n");
exit(1);
}

while (fgets(buff, MAX_LINE_LENGTH, mf) != NULL) {
count++;
opcode = strtok(buff, DELIMITER);
if (opcode == NULL || opcode[0] == '#')
continue;
if (!strcmp(opcode, "nop"))
continue;
else if (!strcmp(opcode, "push")) {
n = strtok(NULL, DELIMITER);
push(&stack, n, count);
} else {
find_opcode(&stack, opcode, count);
}
}

fclose(mf);
free(buff);
while (stack != NULL) {
current = stack;
stack = stack->next;
free(current);
}
return 0;
}
