#define _CRT_SECURE_NO_WARNINGS 1

#include "SingleList.h"


void PrintSL(SL* ps)
{
	while (ps)
	{
		printf("%d ", ps->Data);
		ps = ps->next;
	}
}

SL* BuySLNode(const SListDataType NewData, const SL* NewNext)
{
	SL* ret = (SL*)malloc(sizeof(SListDataType)+sizeof(SL*));
	if (!ret)
	{
		puts("BUY NODE FAILED");
		return NULL;
	}
		
	ret->Data = NewData;
	ret->next = (SL*)NewNext;
	return ret;
}

void SingleListPushBack(SL** pphead, const SListDataType NewData)
{

	SL* NewNode = BuySLNode(NewData, NULL);
	if (!*pphead)
	{
		*pphead = NewNode;
	}
	else
	{
		SL* Last = *pphead;
		while (Last->next)
		{
			Last = Last->next;
		}
		Last->next = BuySLNode(NewData, NULL);
	}
}

void SingleListPopBack(SL** pphead)
{

	if (!(*pphead))
		return;
	else if(!(*pphead)->next)
		*pphead = NULL;

	else
	{
		SL* prev = NULL;
		SL* Last = *pphead;
		while (Last->next)
		{
			prev = Last;
			Last = Last->next;
		}
		
		free(Last);
		prev->next = NULL;
	}

}

void SingleListPushFront(SL** pphead, const SListDataType NewData)
{
	SL* newhead = BuySLNode(NewData, *pphead);
	*pphead = newhead;
}

void SingleListPopFront(SL** pphead)
{
	if (!*pphead)
		return;

	SL* newhead = (*pphead)->next;

	free(*pphead);
	*pphead = newhead;
}

void SingleListPushInsert(SL** pphead, size_t n, const SListDataType NewData)
{
	assert(n > 0);

	if (n == 1)
	{
		SingleListPushFront(pphead, NewData);
		return;
	}
	SL* pI = *pphead;
	SL* prev = NULL;
	while (--n && pI)
	{
		prev = pI;
		pI = (pI)->next;
	}

	if (n)
	{
		puts("INSERT FAILED");
		return;
	}
	else
	{
		if (!pI)
		{
			prev->next = BuySLNode(NewData, NULL);
		}
		else if (!(pI->next))
		{
			prev->next = BuySLNode(NewData, pI);
		}
		else
		{
			prev->next = BuySLNode(NewData, pI);
		}
	}
}

void SingleListEraseInsert(SL** pphead, size_t n)
{
	assert(n > 0);

	if (n == 1)
	{
		SingleListPopFront(pphead);
		return;
	}

	SL* pI = *pphead;
	SL* prev = NULL;
	while (--n && pI)
	{
		prev = pI;
		pI = pI->next;
	}

	if (n)
	{
		puts("ERASE FAILED");
		
	}
	else
	{
		if (!pI)
		{
			;
		}
		else
		{
			prev->next = pI->next;
			free(pI);
		}
	}
}

SL* SingleListFind_Num(SL** pphead, size_t n)
{
	assert(n > 0);

	SL* pI = *pphead;
	while (--n && pI)
	{
		pI = pI->next;
	}

	if (n)
	{
		puts("Empty");
		return NULL;
	}
	else
	{
		if (!pI)
		{
			puts("Empty");
			return NULL;
		}
		else
		{
			return pI;
		}
	}
}

void SingleListModify_Num(SL** pphead, size_t n, const SListDataType NewData)
{
	assert(n > 0);

	/*if (n == 1)
	{
		if (!pphead)
			SingleListPushFront(pphead, NewData);
		else
			(*pphead)->Data = NewData;

		return;
	}*/
	if (!*pphead)
	{
		BuySLNode(NewData, NULL);
		return; 
	}

	SL* pI = *pphead;
	SL* prev = NULL;
	while (--n && pI)
	{
		prev = pI;
		pI = pI->next;
	}

	if (n)
	{
		puts("MODIFY FAILED");
	}
	else
	{
		if (!pI)
		{
			prev->next = BuySLNode(NewData, NULL);
		}
		else
		{
			pI->Data = NewData;
		}
	}
}

SL* SingleListFind_Data(SL** pphead, const SListDataType Data)
{
	/*if (!*pphead)
	{
		puts("Can't Find it");
		return NULL;
	}*/
	
	SL* cur = *pphead;
	while (cur && !(Data == cur->Data))
	{
		cur = cur->next;
	}

	if (!cur)
	{
		puts("Can't Find it");
		return NULL;
	}
	
	return cur;
}

void SingleListModify_Data(SL** pphead, const SListDataType Data, const SListDataType NewData)
{
	/*if (!*pphead)
	{
		puts("Can't Find it");
		return;
	}*/

	SL* cur = *pphead;
	while (cur && !(Data == cur->Data))
	{
		cur = cur->next;
	}

	if (!cur)
	{
		puts("Can't Find it");
	}
	else
	{
		cur->Data = NewData;
	}
}
