#define _CRT_SECURE_NO_WARNINGS 1

#include "SqQueen.h"

void InitsqQueen(sqQ* head)
{
	assert(head);

	head->Maxsize = 2;
	QElemtType* tmp = (QElemtType*)malloc(head->Maxsize * sizeof(QElemtType));
	if (!tmp)
		return;

	head->base = tmp;
	head->front = head->rear = 0;
	puts("Initialized");
}

void CheckQueen(sqQ* head)
{
	assert(head);

	if ((head->rear + 1) % head->Maxsize == head->front)
	{
		QElemtType* tmp = (QElemtType*)malloc(2 * head->Maxsize * sizeof(QElemtType));
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

void EnQueen(sqQ* head, QElemtType val)
{
	assert(head);
	CheckQueen(head);

	head->base[head->rear] = val;
	head->rear = (head->rear + 1) % head->Maxsize;
}

void DeQueen(sqQ* head)
{
	assert(head);
	if (head->front == head->rear)
		return;

	head->front = (head->front + 1) % head->Maxsize;
}

QElemtType QueenLength(sqQ* head)
{
	assert(head);

	return (head->rear - head->front + head->Maxsize) % head->Maxsize;
}
