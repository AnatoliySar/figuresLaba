#include "list.h"

Stack* initiate_stack()
{
	Stack* stack;
	stack = malloc(sizeof(struct Stack));
	stack->curr = 0;
	return stack;
}

void push(Stack* stack, Triangle value)
{
	stack->data[stack->curr] = value;
	stack->curr++;
}

Triangle pop(Stack* stack)
{
	stack->curr--;
	return stack->data[stack->curr];
}

double perimetr(Triangle tr)
{
	return tr.a + tr.b + tr.c;
}

double ploshad(Triangle tr)
{
	double pp = (tr.a + tr.b + tr.c) / 2;
	return sqrt(pp * (pp - tr.a) * (pp - tr.b) * (pp - tr.c));
}

