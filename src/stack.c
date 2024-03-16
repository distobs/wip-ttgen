#include <string.h>
#include "stack.h" /* Inclui a header stdlib.h */

void stack_init(struct stack *s)
{
	s->size = 0;
	s->head = NULL;
	s->tail = NULL;
}

void stack_destroy(struct stack *s)
{
	while (s->size > 0)
		stack_pop(s, NULL);

	/* No livro, o autor seta tudo pra 0 no fim da função, por precaução: */
	memset(s, 0, sizeof(struct stack));
}

int stack_push(struct stack *s, int val)
{
	struct stack_item *new_item;

	/* Aloca espaço para o novo elemento */
	new_item = malloc(sizeof(struct stack_item));

	/* errorcheck */
	if (new_item == NULL)
		return -1;

	new_item->val = val;

	/**** Insere o elemento na head ****/

	if (s->size == 0)
		s->tail = new_item;

	new_item->next = s->head;
	s->head = new_item;

	s->size++;

	return 0;
}

int stack_pop(struct stack *s, int *val)
{
	struct stack_item *old;

	if (s->size == 0)
		return -1;

	/**** Remove o elemento da head ****/

	if (val != NULL)
		*val = s->head->val;

	old = s->head; /* para o free() */
	s->head = s->head->next;

	if (s->size == 1)
		s->tail = NULL; /* O primeiro elemento também é o último. */

	s->size--;

	free(old);

	return 0;
}
