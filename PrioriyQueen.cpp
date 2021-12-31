#define _CRT_SECURE_NO_WARNINGS 1

#include "PrioriyQueen.h"


int Compare(QElemtType a, QElemtType b)
{
	return a - b;
}

void InitsqQueen(pQ* head)
{
	assert(head);

	head->Maxsize = 1000;
	QElemtType* tmp = (QElemtType*)malloc(head->Maxsize * sizeof(QElemtType));
	if (!tmp)
		return;

	head->base = tmp;
	head->front = head->rear = 0;
	puts("Initialized");
}

//void CheckQueen(pQ* head)
//{
//	assert(head);
//
//	if ((head->rear + 1) % head->Maxsize == head->front)
//	{
//		QElemtType* tmp = (QElemtType*)malloc(2 * head->Maxsize * sizeof(QElemtType));
//		if (!tmp)
//			return;
//
//
//		int i = 0;
//		while (head->front != head->rear)
//		{
//			tmp[i++] = head->base[head->front];
//			head->front = (head->front + 1) % head->Maxsize;
//		}
//
//		free(head->base);
//		head->base = tmp;
//		head->Maxsize *= 2;
//		head->front = 0;
//		head->rear = i;
//
//		puts("Expanded");
//	}
//}

void EnQueen(pQ* head, QElemtType val)
{
	assert(head);
	/*CheckQueen(head);*/

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

//void DeQueen(pQ* head)
//{
//	assert(head);
//	if (head->front == head->rear)
//		return;
//
//	head->front = (head->front + 1) % head->Maxsize;
//}

int QueenLength(pQ* head)
{
	assert(head);

	return (head->rear - head->front + head->Maxsize) % head->Maxsize;
}

void DestroyQueen(pQ* head)
{
	assert(head);

	free(head->base);
	head = NULL;
}

pQ* IsQueenEmpty(pQ* head)
{
	assert(head);

	if (head->rear == head->front)
		return NULL;
	else
		return head;
}

QElemtType PopQueen(pQ* head)
{
	assert(head);
	if (head->front == head->rear)
		return NULL;

	QElemtType ret = head->base[head->front];
	head->base[head->front] = head->base[head->rear - 1];

	int start = head->front;
	int left = 2 * start + 1;
	while (left < head->rear)
	{
		int max = left + 1 < head->rear && (Compare(head->base[left + 1], head->base[left]) < 0) ? left + 1 : left;

		if (Compare(head->base[start], head->base[max]) > 0)
		{
			QElemtType tmp = head->base[start];
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
