#define _CRT_SECURE_NO_WARNINGS 1

#include "Graph.h"

void Swap(SLDataType* p, const int a, const int b)
{
	SLDataType tmp = p[a];
	p[a] = p[b];
	p[b] = tmp;
}

void Patition(SQL* ps, const int L, const int R, int* arr)
{
	int pL = L - 1;
	int pR = R;
	


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
	arr[0] = pL;
	arr[1] = pR;
	
}

void QuickSort(SQL* ps, const int L, const int R)
{
	assert(ps);
	if (L >= R)
		return;

	Swap(ps->n, L + rand() % (R - L + 1), R);
	int arr[2] = { 0 };

	Patition(ps, L, R, arr);
	QuickSort(ps, L, arr[0]);
	QuickSort(ps, arr[1], R);


}

int BinaryFind(SQL* ps, int L, int R, const SLDataType Data)
{
	assert(ps);

	while (L <= R)
	{
		int mid = L + ((R - L) >> 2);
		if (ps->n[mid] > Data)
			R = mid - 1;
		else if (ps->n[mid] < Data)
			L = mid + 1;
		else
			return mid;
	}
	return -1;

}

void SeqListCheckCapacity(SQL* ps)
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

void SeqListInit(SQL* ps)
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

void SeqListPushBack(SQL* ps, const SLDataType NewData)
{
	assert(ps);
	SeqListCheckCapacity(ps);

	ps->n[ps->size] = NewData;
	ps->size++;
}

void SeqListPopBack(SQL* ps)
{
	assert(ps);

	ps->size--;
}

void SeqListPushFront(SQL* ps, const SLDataType NewData)
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

void SeqListPopFront(SQL* ps)
{
	assert(ps);

	int i = 1;
	for (i = 1; i < ps->size; i++)
	{
		ps->n[i - 1] = ps->n[i];
	}
	ps->size--;
}

void SeqListPushInsert(SQL* ps, const int index, const SLDataType NewData)
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

void SeqListEraseInsert(SQL* ps, const int index)
{
	assert(ps);

	int i = index + 1;
	for (i = index + 1; i < ps->size; i++)
	{
		ps->n[i - 1] = ps->n[i];
	}
	ps->size--;
}

void SeqListModify(SQL* ps, const int index, const SLDataType NewData)
{
	assert(ps);

	ps->n[index] = NewData;
}

void SeqListSort(SQL* ps)
{
	assert(ps);

	srand((unsigned)time(NULL));
	QuickSort(ps, 0, (ps->size) - 1);
}

int SeqListFind(SQL* ps, const SLDataType Data)
{
	assert(ps);

	SeqListSort(ps);
	return BinaryFind(ps, 0, (ps->size) - 1, Data);
}



//void PrintSL(SL* ps)
//{
//	while (ps)
//	{
//		printf("%d ", ps->Data);
//		ps = ps->next;
//	}
//}

SL* BuySLNode(const SListDataType NewData, const SL* NewNext)
{
	SL* ret = (SL*)malloc(sizeof(SListDataType) + sizeof(SL*));
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
	else if (!(*pphead)->next)
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

void BFS(GN* pG)
{
	assert(pG);

	sqQ pQ;
	InitsqQueen(&pQ);
	EnQueen(&pQ, pG);

	HMap pHM;
	InitHashMap(&pHM);
	HashMapInsert(&pHM, pG, pG->val);

	while (IsQueenEmpty(&pQ))
	{
		GN* cur = PopQueen(&pQ);
		printf("%d ", cur->val);

		SL* head = cur->nexts;
		while (head)
		{
			if (!HashMapFind(&pHM, head->Data))
			{
				EnQueen(&pQ, head->Data);
				HashMapInsert(&pHM, head->Data, head->Data->val);
			}
			head = head->next;
		}
	}


	DestroyQueen(&pQ);
	DestroyHashMap(&pHM);
}

void DFS(GN* pG)
{
	assert(pG);

	SK pSK;
	InitStack(&pSK);
	Push(&pSK, pG);
	printf("%d ", pG->val);

	HMap pHM;
	InitHashMap(&pHM);
	HashMapInsert(&pHM, pG, pG->val);

	while (IsStackEmpty(&pSK))
	{
		GN* cur = Pop(&pSK);
		SL* head = cur->nexts;

		while (head)
		{
			if (!HashMapFind(&pHM, head->Data))
			{
				Push(&pSK, cur);
				Push(&pSK, head->Data);
				HashMapInsert(&pHM, head->Data, head->Data->val);
				printf("%d ", head->Data->val);
				break;
			}
			head = head->next;
		}
	}


	DestroyStack(&pSK);
	DestroyHashMap(&pHM);
}

void ZeroIn(GN* pG, sqQ* ziQ)
{
	assert(pG && ziQ);

	sqQ pQ;
	InitsqQueen(&pQ);
	EnQueen(&pQ, pG);

	HMap pHM;
	InitHashMap(&pHM);
	HashMapInsert(&pHM, pG, pG->val);

	while (IsQueenEmpty(&pQ))
	{
		GN* cur = PopQueen(&pQ);
		if (cur->in == 0)
		{
			EnQueen(ziQ, pG);
		}

		SL* head = cur->nexts;
		while (head)
		{
			if (!HashMapFind(&pHM, head->Data))
			{
				EnQueen(&pQ, head->Data);
				HashMapInsert(&pHM, head->Data, head->Data->val);
			}
			head = head->next;
		}
	}


	DestroyQueen(&pQ);
	DestroyHashMap(&pHM);
}

void TopologySort(GN* pG)
{
	assert(pG);

	sqQ zeroInQueen;
	InitsqQueen(&zeroInQueen);
	ZeroIn(pG, &zeroInQueen);

	while (IsQueenEmpty(&zeroInQueen))
	{
		GN* cur = PopQueen(&zeroInQueen);
		printf("%d ", cur->val);

		SL* head = cur->nexts;
		while (head)
		{
			if (!--(head->Data->in))
			{
				EnQueen(&zeroInQueen, head->Data);
			}
			head = head->next;
		}
	}

	DestroyQueen(&zeroInQueen);
}

void KruskalMST(HashMap* Graph)
{
	assert(Graph);

	int i = 0;
	int sz = MAP_MAX_SIZE;
	pQ edges;
	InitpQueen(&edges);

	HMap pHM;
	InitHashMap(&pHM);

	int n = Graph->Hashsize;
	while (n)
	{
		for (i = 0; i < sz; i++)
		{
			HMNode* cur = Graph->arr[i]->next;
			while (cur)
			{
				int j = 0;
				while (cur->key->edges->n[j])
				{
					EnpQueen(&edges, cur->key->edges->n[j++]);
				}
				cur = cur->next;
				n--;
			}
			if (!n)
				break;
		}
	}


	GE* edge = PoppQueen(&edges);
	HashMapInsert(&pHM, edge->from, edge->weight);
	HashMapInsert(&pHM, edge->to, edge->weight);
	printf("%d ", edge->weight);

	while (IspQueenEmpty(&edges))
	{
		edge = PoppQueen(&edges);

		if (!HashMapFind(&pHM, edge->to))
		{
			HashMapInsert(&pHM, edge->to, edge->weight);
			printf("%d ", edge->weight);
		}
		
	}


	DestroypQueen(&edges);
	DestroyHashMap(&pHM);
}