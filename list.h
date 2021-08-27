#ifndef _LIST_H
#define _LIST_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define MAX_STACK 100

typedef struct Triangle
{
	double a;
	double b;
	double c;
} Triangle;

typedef struct Stack
{
	Triangle data[MAX_STACK];
	int curr;
} Stack;

Stack* initiate_stack();
void push(Stack* stack, Triangle value);
Triangle pop(Stack* stack);
double perimetr(Triangle tr);
double ploshad(Triangle tr);

#endif // !_LIST_H