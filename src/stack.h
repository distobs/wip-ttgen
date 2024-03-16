#ifndef STACK_H
#define STACK_H
/* Quase tudo aqui é roubado do Mastering Algorithms with C. */

#include <stdlib.h>

/* Um item na stack. Val é o valor daquele item. Next aponta para o próximo
 * item, ou é igual a NULL caso seja o último item na stack. */
struct stack_item {
	int val;
	struct stack_item *next;
};

/* A stack. Size é o tamanho, e o começo e o final da stack são,
 * respectivamente, head e tail. */
struct stack {
	size_t size;
	struct stack_item *head;
	struct stack_item *tail;
};

/* Inicializa a stack */
void stack_init(struct stack *s);

/* Destrói a stack */
void stack_destroy(struct stack *s);

/* Função push. Põe um valor val em cima do primeiro elemento da stack. Retorna:
 0: sucesso
 -1: erro na memória
 */
int stack_push(struct stack *s, int val);

/* Função pop. Tira o primeiro elemento da stack e armazena em val. Retorna:
 TODO: valores de retorno.
 */
int stack_pop(struct stack *s, int *val);


#endif /* ndef STACK_H */
