#define _CRT_SECURE_NO_WARNINGS 1

#include "SingleList practice.h"


void Swap(SL** arr, int a, int b)
{
	SL* tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

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

SL* ListPatition2(SL* ps, int val)
{
	assert(ps);

	int n = 0;
	SL* cur = ps;
	while (cur)
	{
		n++;
		cur = cur->next;
	}

	SL** arr = new SL * [n];

	int i = 0;
	cur = ps;
	for (i = 0; i < n; i++)
	{
		arr[i] = cur;
		cur = cur->next;
		/*arr[i]->next = NULL;*/
	}

	int pL = -1;
	int pR = n;
	i = 0;

	while (i < pR)
	{
		if (arr[i]->Data < val)
		{
			Swap(arr, i++, ++pL);
		}
		else if (arr[i]->Data > val)
		{
			Swap(arr, i, --pR);
		}
		else
		{
			i++;
		}
	}

	i = 0;
	while (i < n-1)
	{
		arr[i]->next = arr[i+1];
		i++;
	}
	arr[i]->next = NULL;
	
	/*for (i = 1; i < n; i++)
	{
		arr[i - 1]->next = arr[i];
	}
	arr[i - 1]->next = NULL;*/

	/*delete[] arr;
	arr = NULL;*/

	return arr[0];
}

SL* GetLoopNode(SL* ps)
{
	assert(ps);

	SL* fast = ps->next->next;
	SL* slow = ps->next;

	while (fast != slow)
	{
		if (!fast->next || !fast->next->next)
		{
			return NULL;
		}

		fast = fast->next->next;
		slow = slow->next;
	}

	fast = ps;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return fast;
}

SL* noLoop(SL* head1, SL* head2)
{
	assert(head1 && head2);

	SL* cur1 = head1, * cur2 = head2;
	int len1 = 1;
	int len2 = 1;
	while (cur1->next)
	{
		cur1 = cur1->next;
		len1++;
	}
	
	while (cur2->next)
	{
		cur2 = cur2->next;
		len2++;
	}

	if (cur1 == cur2)
	{
		int n = len1 < len2 ? len2 - len1 : len1 - len2;
		cur1 = len1 > len2 ? head1 : head2;
		cur2 = len1 > len2 ? head2 : head1;
		while (n--)
		{
			cur1 = cur1->next;
		}

		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	else
		return NULL;
}

SL* bothLoop(SL* head1, SL* loop1, SL* head2, SL* loop2)
{
	assert(head1 && head2 && loop1 && loop2);

	if (loop1 == loop2)
	{
		SL* cur1 = head1, * cur2 = head2;
		int len1 = 1;
		int len2 = 1;
		while (cur1->next == loop1)
		{
			cur1 = cur1->next;
			len1++;
		}

		while (cur2->next == loop1)
		{
			cur2 = cur2->next;
			len2++;
		}

		int n = len1 < len2 ? len2 - len1 : len1 - len2;
		cur1 = len1 > len2 ? head1 : head2;
		cur2 = len1 > len2 ? head2 : head1;
		while (n--)
		{
			cur1 = cur1->next;
		}

		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	else
	{
		SL* cur = loop1->next;
		while (cur != loop1)
		{
			if (cur == loop2)
			{
				return loop2;
			}
			cur = cur->next;
		}
		return NULL;
	}
}

SL* GetIntersect(SL* head1, SL* head2)
{
	assert(head1 && head2);

	SL* loop1 = GetLoopNode(head1);
	SL* loop2 = GetLoopNode(head2);

	if (loop1 && loop2)
		return bothLoop(head1, loop1, head2, loop2);
	if (!loop1 && !loop2)
	{
		return noLoop(head1, head2);
	}
	return NULL;
}



