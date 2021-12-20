#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree practice.h"


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
		StackDataType* tmp = (StackDataType*)realloc(ps->base, 2 * sizeof(StackDataType) * ps->stacksize);
		if (!tmp)
			return;

		ps->base = tmp;
		ps->top = ps->base + ps->stacksize;
		ps->stacksize = 2 * ps->stacksize;
		/*puts("Expanded");*/
	}
}

void Push(SK* ps, StackDataType p)
{
	assert(ps);
	CheckStack(ps);

	*((ps->top)++) = p;
}

StackDataType Pop(SK* ps)
{
	assert(ps);
	if (ps->top == ps->base)
		return NULL;

	return *(--(ps->top));
}

SK* IsEmpty(SK* ps)
{
	assert(ps);

	if (ps->top == ps->base)
		return NULL;
	else
		return ps;
}

void preOrderRecur(BTree* head)
{
	if (!head)
		return;

	printf("%d ", head->val);
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}

void inOrderRecur(BTree* head)
{
	if (!head)
		return;

	inOrderRecur(head->left);
	printf("%d ", head->val);
	inOrderRecur(head->right);
}

void postOrderRecur(BTree* head)
{
	if (!head)
		return;

	postOrderRecur(head->left);
	postOrderRecur(head->right);
	printf("%d ", head->val);
}

void preOrderRecur1(BTree* head, SK* pstack)
{
	if (!head)
		return;

	Push(pstack, head);
	while (IsEmpty(pstack))
	{
		head = Pop(pstack);
		printf("%d ", head->val);

		if (head->right)
		{
			Push(pstack, head->right);
		}
		if (head->left)
		{
			Push(pstack, head->left);
		}
	}
}

void postOrderRecur1(BTree* head)
{
	assert(head);

	SK p1, p2;
	InitStack(&p1);
	InitStack(&p2);
	Push(&p1, head);
	while (IsEmpty(&p1))
	{
		head = Pop(&p1);
		Push(&p2, head);

		if (head->left)
		{
			Push(&p1, head->left);
		}
		if (head->right)
		{
			Push(&p1, head->right);
		}
		
	}

	while (IsEmpty(&p2))
	{
		printf("%d ", Pop(&p2)->val);
	}

	free(p1.base);
	free(p2.base);
	p1.top = p1.base = p2.top = p2.base = NULL;

}

void inOrderRecur1(BTree* head)
{
	assert(head);

	SK p;
	InitStack(&p);

	while (IsEmpty(&p) || head)
	{
		if (head)
		{
			Push(&p, head);
			head = head->left;
		}
		else
		{
			head = Pop(&p);
			printf("%d ", head->val);
			head = head->right;
		}
	}

	free(p.base);
	p.base = p.top = NULL;
}



