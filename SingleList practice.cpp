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
