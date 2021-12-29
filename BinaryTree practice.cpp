#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree practice.h"
#include "HashMap.h"
#include "SqQueen.h"


void InitStack(SK* ps)
{

	StackDataType* tmp = (StackDataType*)malloc(10 * sizeof(StackDataType));
	if (!tmp)
		return;

	ps->base = tmp;
	ps->top = ps->base;
	ps->stacksize = 2;
	puts("Initialized");
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


void WidthRecur(BTree* head)
{
	assert(head);

	sqQ pQ;
	InitsqQueen(&pQ);

	EnQueen(&pQ, head);
	while (IsQueenEmpty(&pQ))
	{
		head = PopQueen(&pQ);
		printf("%d ", head->val);
		
		if (head->left)
		{
			EnQueen(&pQ, head->left);
		}
		if (head->right)
		{
			EnQueen(&pQ, head->right);
		}
	}
}

//int GetMaxWidth(BTree* head)
//{
//	assert(head);
//
//	int curNodeLevel = 1;
//	int curLevel = 1;
//	int curLevelWidth = 0;
//	int MaxWidth = 0;
//	sqQ pQ;
//	InitsqQueen(&pQ);
//	HMap pHM;
//	InitHashMap(&pHM);
//
//	EnQueen(&pQ, head);
//	HashMapInsert(&pHM, head, curLevel);
//
//	while (IsQueenEmpty(&pQ))
//	{
//		head = PopQueen(&pQ);
//		curNodeLevel = HashMapFind(&pHM, head)->val;
//		/*printf("%d ", head->val);*/
//
//		if (curLevel == curNodeLevel)
//		{
//			curLevelWidth++;
//		}
//		else
//		{
//			curLevel++;
//			if (MaxWidth < curLevelWidth)
//			{
//				MaxWidth = curLevelWidth;
//			}
//			curLevelWidth = 1;
//		}
//
//
//		if (head->left)
//		{
//			EnQueen(&pQ, head->left);
//			HashMapInsert(&pHM, head->left, curLevel + 1);
//		}
//		if (head->right)
//		{
//			EnQueen(&pQ, head->right);
//			HashMapInsert(&pHM, head->right, curLevel + 1);
//		}
//	}
//
//	return MaxWidth;
//}

int IsCBT(BTree* head)
{
	assert(head);

	sqQ pQ;
	InitsqQueen(&pQ);
	int leaf = 0;

	EnQueen(&pQ, head);
	while (IsQueenEmpty(&pQ))
	{
		head = PopQueen(&pQ);
		if (head->right && !head->left)
			return 0;
		if (leaf && (head->left || head->right))
			return 0;

		if (head->left)
			EnQueen(&pQ, head->left);
		if (head->right)
			EnQueen(&pQ, head->right);
		if (!head->left || !head->right)
			leaf = 1;
	}
	return 1;
}

int getHeight(BTree* head)
{
	if (!head)
		return 0;

	int leftHeight = getHeight(head->left);
	int rightHeight = getHeight(head->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}


int IsBalanced(BTree* head)
{
	if (!head)
		return 1;

	int L = IsBalanced(head->left);
	int R = IsBalanced(head->right);

	int LHeight = getHeight(head->left);
	int RHeight = getHeight(head->right);

	if (abs(LHeight - RHeight) > 1)
		return 0;

	if (!L || !R)
		return 0;
	else
		return 1;
}

int IsBST(BTree* head)
{
	if (!head)
		return 1;

	int L = IsBST(head->left);
	int R = IsBST(head->right);

	if (head->left && head->left->val >= head->val)
		return 0;
	if (head->right && head->right->val <= head->val)
		return 0;

	if (!L || !R)
		return 0;
	else
		return 1;
}


void getPrevNode(BTree* head, HMap* pHM)
{
	if (!head)
		return;

	HashMapInsert(pHM, head->left, head);
	HashMapInsert(pHM, head->right, head);

	getPrevNode(head->left, pHM);
	getPrevNode(head->right, pHM);

}

BTree* LowestCommonAncestor1(BTree* head, BTree* node1, BTree* node2)
{
	if (!head)
		return NULL;

	HMap pHM;
	InitHashMap(&pHM);
	getPrevNode(head, &pHM);
	HashMapInsert(&pHM, head, NULL);

	while (node1)
	{
		BTree* cur = node2;
		while (cur)
		{
			if (cur == node1)
			{
				return cur;
			}
			cur = HashMapFind(&pHM, cur)->val;
		}
		node1 = HashMapFind(&pHM, node1)->val;
	}

	DestroyHashMap(&pHM);
	return NULL;
}

BTree* LowestCommonAncestor2(BTree* head, BTree* node1, BTree* node2)
{
	if (!head || head == node1 || head == node2)
		return head;

	BTree* L = LowestCommonAncestor2(head->left, node1, node2);
	BTree* R = LowestCommonAncestor2(head->right, node1, node2);

	if (L && R)
		return head;
	
	return L ? L : R;
}

void PrintAllFolds(int i, int n, int j)
{
	if (i > n)
		return;

	PrintAllFolds(i + 1, n, 1);
	printf("%d ", j);
	PrintAllFolds(i + 1, n, 0);

}

