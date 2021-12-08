#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"


void Swap(SLDataType* p, const int a, const int b)
{
	SLDataType tmp = p[a];
	p[a] = p[b];
	p[b] = tmp;
}

int* Patition(SL* ps, const int L, const int R)
{
	int pL = L - 1;
	int pR = R;
	/*int ret[2] = { 0 };*/

	/*SLDataType Randomindex = rand() % (ps->size);
	Swap(ps->n, R, Randomindex);*/

	int i = L;
	while (i < pR)
	{
		if (ps->n[i] < ps->n[R])
		{
			Swap(ps->n, i++, ++pL);
		}
		else if (ps->n[i] > ps->n[R])
		{
			Swap(ps->n, i, --pR);
		}
		else
		{
			i++;
		}
	}
	Swap(ps->n, pR++, R);

	int ret[] = { pL, pR };

	return ret;
}

void QuickSort(SL* ps, const int L, const int R)
{
	assert(ps);
	if (L >= R)
		return;
	
	int* arr = Patition(ps, L, R);
	QuickSort(ps, L, arr[0]);
	QuickSort(ps, arr[1], R);
	

}

void SeqListCheckCapacity(SL* ps)
{
	assert(ps);

	if (ps->size >= ps->capacity)
	{
		SLDataType* tmp = (SLDataType*)realloc(ps->n, 2 * sizeof(SLDataType) * (ps->capacity));
		if (!tmp)
		{
			puts("Expansion Failed");
			return;
		}
		ps->n = tmp;
		ps->capacity *= 2;

		puts("Expanded");
	}
}

void SeqListInit(SL* ps)
{
	assert(ps);

	ps->size = 0;
	ps->n = (SLDataType*)malloc(sizeof(SLDataType) * 2);
	if (!ps)
	{
		puts("Build Failed");
		return;
	}
	ps->capacity = 2;

	puts("Initalized");
}

void SeqListPushBack(SL* ps, const SLDataType NewData)
{
	assert(ps);
	SeqListCheckCapacity(ps);

	ps->n[ps->size] = NewData;
	ps->size++;
}

void SeqListPopBack(SL* ps)
{
	assert(ps);

	ps->size--;
}

void SeqListPushFront(SL* ps, const SLDataType NewData)
{
	assert(ps);
	SeqListCheckCapacity(ps);

	int i = 0;
	for (i = ps->size - 1; i >= 0; i--)
	{
		ps->n[i + 1] = ps->n[i];
	}
	ps->n[0] = NewData;
	ps->size++;
}

void SeqListPopFront(SL* ps)
{
	assert(ps);

	int i = 1;
	for (i = 1; i < ps->size; i++)
	{
		ps->n[i - 1] = ps->n[i];
	}
	ps->size--;
}

void SeqListPushInsert(SL* ps, const int index, const SLDataType NewData)
{
	assert(ps);
	SeqListCheckCapacity(ps);

	int i = 0;
	for (i = ps->size - 1; i >= index; i--)
	{
		ps->n[i + 1] = ps->n[i];
	}
	ps->n[index] = NewData;
	ps->size++;
}

void SeqListEraseInsert(SL* ps, const int index)
{
	assert(ps);

	int i = index+1;
	for (i = index+1; i < ps->size; i++)
	{
		ps->n[i - 1] = ps->n[i];
	}
	ps->size--;
}

void SeqListModify(SL* ps, const int index, const SLDataType NewData)
{
	assert(ps);

	ps->n[index] = NewData;
}

void SeqListSort(SL* ps)
{
	assert(ps);

	srand((unsigned)time(NULL));
	QuickSort(ps,0,(ps->size) - 1);
}