#define _CRT_SECURE_NO_WARNINGS 1

#include "PrioriyQueen.h"


int Compare(pQElemtType a, pQElemtType b)
{
	return a - b;
}

void InitpQueen(pQ* head)
{
	assert(head);

	head->Maxsize = 2;
	pQElemtType* tmp = (pQElemtType*)malloc(head->Maxsize * sizeof(pQElemtType));
	if (!tmp)
		return;

	head->base = tmp;
	head->front = head->rear = 0;
	puts("Initialized");
}

void CheckpQueen(pQ* head)
{
	assert(head);

	if ((head->rear + 1) % head->Maxsize == head->front)
	{
		pQElemtType* tmp = (pQElemtType*)malloc(2 * head->Maxsize * sizeof(pQElemtType));
		if (!tmp)
			return;


		int i = 0;
		while (head->front != head->rear)
		{
			tmp[i++] = head->base[head->front];
			head->front = (head->front + 1) % head->Maxsize;
		}

		free(head->base);
		head->base = tmp;
		head->Maxsize *= 2;
		head->front = 0;
		head->rear = i;

		puts("Expanded");
	}
}

void EnpQueen_Min(pQ* head, pQElemtType val)
{
	assert(head);
	CheckpQueen(head);
	
	int i = head->rear;
	while (i>=head->front && Compare(val, head->base[(i-1)/2]) < 0)
	{
		head->base[i] = head->base[(i-1)/2];
		head->base[(i - 1) / 2] = val;
		i = (i - 1) / 2;
	}
	head->base[i] = val;
	head->rear = (head->rear + 1) % head->Maxsize;
}

void EnpQueen_Max(pQ* head, pQElemtType val)
{
	assert(head);
	CheckpQueen(head);

	int i = head->rear;
	while (i >= head->front && Compare(val, head->base[(i - 1) / 2]) > 0)
	{
		head->base[i] = head->base[(i - 1) / 2];
		head->base[(i - 1) / 2] = val;
		i = (i - 1) / 2;
	}
	head->base[i] = val;
	head->rear = (head->rear + 1) % head->Maxsize;
}




//void DepQueen(pQ* head)
//{
//	assert(head);
//	if (head->front == head->rear)
//		return;
//
//	head->front = (head->front + 1) % head->Maxsize;
//}

int pQueenLength(pQ* head)
{
	assert(head);

	return (head->rear - head->front + head->Maxsize) % head->Maxsize;
}

void DestroypQueen(pQ* head)
{
	assert(head);

	free(head->base);
	head = NULL;
}

pQ* IspQueenEmpty(pQ* head)
{
	assert(head);

	if (head->rear == head->front)
		return NULL;
	else
		return head;
}

pQElemtType PoppQueen_Min(pQ* head)
{
	assert(head);
	if (head->front == head->rear)
		return NULL;

	pQElemtType ret = head->base[head->front];
	head->base[head->front] = head->base[head->rear - 1];

	int start = head->front;
	int left = 2 * start + 1;
	while (left < head->rear)
	{
		int min = left + 1 < head->rear && (Compare(head->base[left + 1], head->base[left]) < 0) ? left + 1 : left;

		if (Compare(head->base[start], head->base[min]) > 0)
		{
			pQElemtType tmp = head->base[start];
			head->base[start] = head->base[min];
			head->base[min] = tmp;

			start = min;
			left = 2 * start + 1;
		}
		else
			break;
	}

	head->rear = (head->rear - 1) % head->Maxsize;

	return ret;
}

pQElemtType PoppQueen_Max(pQ* head)
{
	assert(head);
	if (head->front == head->rear)
		return NULL;

	pQElemtType ret = head->base[head->front];
	head->base[head->front] = head->base[head->rear - 1];

	int start = head->front;
	int left = 2 * start + 1;
	while (left < head->rear)
	{
		int max = left + 1 < head->rear && (Compare(head->base[left + 1], head->base[left]) > 0) ? left + 1 : left;

		if (Compare(head->base[start], head->base[max]) < 0)
		{
			pQElemtType tmp = head->base[start];
			head->base[start] = head->base[max];
			head->base[max] = tmp;

			start = max;
			left = 2 * start + 1;
		}
		else
			break;
	}

	head->rear = (head->rear - 1) % head->Maxsize;

	return ret;
}

int pQueenFind(pQ* head, pQElemtType val)
{
	assert(head);

	int i = head->front;
	
	while (i <= head->rear)
	{
		if (Compare(val, head->base[i]))
			i++;
		else
			return i;
	}
	/*while (L <= R)
	{
		int mid = L + ((R - L) >> 1);

		if (Compare(val, head->base[mid] < 0))
		{
			R = mid - 1;
		}
		else if (Compare(val, head->base[mid] > 0))
		{
			L = mid + 1;
		}
		else
			return 1;
	}*/
	return -1;
}

void pQueenModify_Min(pQ* head, pQElemtType val, pQElemtType newval)
{
	assert(head);

	int i = pQueenFind(head, val);
	head->base[i] = newval;

	if (Compare(val, newval) > 0)
	{
		while (i >= head->front && newval < head->base[(i - 1) >> 1])
		{
			head->base[i] = head->base[(i - 1) >> 1];
			head->base[(i - 1) >> 1] = newval;
			i = (i - 1) >> 1;
		}
	}
	else if (Compare(val, newval) < 0)
	{
		int start = i;
		int left = 2 * start + 1;

		while (left <= head->rear)
		{
			int min = left + 1 <= head->rear && (Compare(head->base[left + 1], head->base[left]) < 0) ? left + 1 : left;

			if (newval > head->base[min])
			{
				head->base[start] = head->base[min];
				head->base[min] = newval;
				start = min;
				left = 2 * start + 1;
			}
			else
				break;
		}
	}
}

void pQueenModify_Max(pQ* head, pQElemtType val, pQElemtType newval)
{
	assert(head);

	int i = pQueenFind(head, val);
	head->base[i] = newval;

	if (Compare(val, newval) < 0)
	{
		while (i >= head->front && newval > head->base[(i - 1) >> 1])
		{
			head->base[i] = head->base[(i - 1) >> 1];
			head->base[(i - 1) >> 1] = newval;
			i = (i - 1) >> 1;
		}
	}
	else if (Compare(val, newval) > 0)
	{
		int start = i;
		int left = 2 * start + 1;

		while (left <= head->rear)
		{
			int max = left + 1 <= head->rear && (Compare(head->base[left + 1], head->base[left]) > 0) ? left + 1 : left;

			if (newval < head->base[max])
			{
				head->base[start] = head->base[max];
				head->base[max] = newval;
				start = max;
				left = 2 * start + 1;
			}
			else
				break;
		}
	}
}
