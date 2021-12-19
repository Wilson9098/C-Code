#define _CRT_SECURE_NO_WARNINGS 1

#include "StackPractice.h"


void InitStack(SK* ps)
{

	StackDataType* tmp = (StackDataType*)malloc(10 * sizeof(StackDataType));
	if (!tmp)
		return;

	ps->base = tmp;
	ps->top = ps->base;
	ps->stacksize = 2;
	puts("Intialized");
}

void CheckStack(SK* ps)
{
	assert(ps);

	while (ps->top - ps->base >= ps->stacksize)
	{
		StackDataType* tmp = (StackDataType*)realloc(ps->base,
			2 * sizeof(StackDataType) * ps->stacksize);
		if (!tmp)
			return;
	
		ps->base = tmp;
		ps->top = ps->base + ps->stacksize;
		ps->stacksize = 2 * ps->stacksize;
		puts("Expanded");
	}
}

void Push(SK* ps, StackDataType val)
{
	assert(ps);
	CheckStack(ps);

	*((ps->top)++) = val;
}

StackDataType Pop(SK* ps)
{
	assert(ps);
	if (ps->top == ps->base)
		return -1;

	return *(--ps->top);
}

