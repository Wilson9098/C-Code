#define _CRT_SECURE_NO_WARNINGS 1

#include "SingleList practice.h"


void Delete_val(SL** ps, SListDataType val)
{
	

	SL* cur = *ps;
	SL* prev = NULL;
	while (*ps && cur)
	{
		if ((*ps)->Data == val)
		{
			if ((*ps)->next)
			{
				SL* newhead = (*ps)->next;
				free(*ps);
				*ps = newhead;
				cur = *ps;
			}
			else
			{
				free(*ps);
				*ps = NULL;
			}
		}
		else
		{
			if (cur->Data == val)
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
	}
}

SL* ReverseList1(SL* ps)
{
	/*if (!ps || !(ps->next))
	{
		return ps;
	}*/  

	SL* prev = NULL, * cur = ps;
	while (cur)
	{
		SL* next = cur->next;

		cur->next = prev;
		prev = cur;
		cur = next;
		/*if (next)
			next = next->next;*/

	}
	return prev;
}

SL* ReverseList2(SL* ps)
{
	/*if (!ps || !(ps->next))
	{
		return ps;
	}*/

	SL* newhead = NULL;
	while (ps)
	{
		SL* next = ps->next;

		ps->next = newhead;
		newhead = ps;
		ps = next;
		/*if (next)
			next = next->next;*/
	}
	return newhead;
}

SL* MidNode(SL* ps)
{
	assert(ps);

	SL* fast = ps, * slow = ps;

	while (fast && fast->next)
	{
		/*fast = fast->next;
		if (!fast->next)
		{
			slow = slow->next;
			break;
		}
		else
		{
			fast = fast->next;
			slow = slow->next;
		}*/
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

SL* KNode(SL* ps, int k)
{
	assert(ps);
	if (k < 1)
		return NULL;

	SL* fast = ps, * slow = ps;
	
	while (k--)
	{
		if (fast)
		{
			fast = fast->next;
		}
		else
			return NULL;
	}

	/*if (k)
	{
		return NULL;
	}*/
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

SL* MergeList(SL* phead1, SL* phead2)
{
	/*if (!phead1 && !phead2)
		return NULL;*/
	if (!phead1)
		return phead2;
	if (!phead2)
		return phead1;
	

	SL* pnew = NULL, * cur1 = phead1, * cur2 = phead2;
	if (cur1->Data >= cur2->Data)
	{
		pnew = cur1;
		cur1 = cur1->next;
	}
	else
	{
		pnew = cur2;
		cur2 = cur2->next;
	}
	SL* newhead = pnew;

	while (cur1 && cur2)
	{
		if (cur1->Data <= cur2->Data)
		{
			pnew->next = cur1;
			pnew = pnew->next;
			cur1 = cur1->next;
		}
		else
		{
			pnew->next = cur2;
			pnew = pnew->next;
			cur2 = cur2->next;
		}
	}
	while (cur1)
	{
		pnew->next = cur1;
		pnew = pnew->next;
		cur1 = cur1->next;
	}
	while (cur2)
	{
		pnew->next = cur2;
		pnew = pnew->next;
		cur2 = cur2->next;
	}

	return newhead;
}

int IsPalindrome(SL* ps)
{
	assert(ps);

	SL* fast = ps, * slow = ps;
	int ret = 1;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	SL* Rhead = slow, * prev = NULL;
	while (slow)
	{
		SL* next = slow->next;

		slow->next = prev;
		/*if (!next)
			break;*/
		prev = slow;
		slow = next;
		/*next = next->next;*/
	}

	SL* Lhead = ps;
	Rhead = prev;

	while (Lhead && Rhead)
	{
		if (Lhead->Data != Rhead->Data)
		{
			ret = 0;
		}

		Lhead = Lhead->next;
		Rhead = Rhead->next;
	}
	/*while (Lhead && Rhead && (Lhead->Data == Rhead->Data))
	{

		Lhead = Lhead->next;
		Rhead = Rhead->next;
	}

	if (!Rhead)
	{
		return 1;
	}*/

	slow = prev;
	prev = NULL;
	while (slow)
	{
		SL* next = slow->next;

		slow->next = prev;
		/*if (!next)
			break;*/
		prev = slow;
		slow = next;
		/*next = next->next;*/
	}
	
	return ret;
}


SL* ListPatition1(SL* ps, int n)
{
	assert(ps);

	SL* cur = ps;
	SL* pLhead = NULL, * pLtail = NULL;
	SL* pRhead = NULL, * pRtail = NULL;
	SL* pMhead = NULL, * pMtail = NULL;

	while (cur)
	{
		SL* next = cur->next;
		cur->next = NULL;

		if (cur->Data < n)
		{
			if (!pLhead)
			{
				pLhead = cur;
				pLtail = cur;
			}
			else
			{
				pLtail->next = cur;
				pLtail = cur;
			}
		}
		else if (cur->Data > n)
		{
			if (!pRhead)
			{
				pRhead = cur;
				pRtail = cur;
			}
			else
			{
				pRtail->next = cur;
				pRtail = cur;
			}

		}
		else
		{
			if (!pMhead)
			{
				pMhead = cur;
				pMtail = cur;
			}
			else
			{
				pMtail->next = cur;
				pMtail = cur;
			}
		}

		cur = next;
	}

	if (pLhead)
	{
		pLtail->next = pMhead ? pMhead : pRhead;
	}
	if (pMhead)
	{
		pMtail->next = pRhead;
	}


	return pLhead ? pLhead : (pMhead ? pMhead : pRhead);
}




