#include <stdio.h>
#include "stack.h"

int main(void)
{
	int val;
	struct stack *s;

	stack_init(s);

	for (int i = 0; i < 10; ++i)
		stack_push(s, i);

	while (s->size != 0) {
		stack_pop(s, &val);
		printf("%d\n", val);
	}

	stack_destroy(s);

	return 0;
}
