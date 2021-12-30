#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "SqQueen.h"
#include "HashMap.h"
#include "StackPractice.h"


struct SeqList;
struct SingleList;
struct GraphNode;
struct GraphEdge;
struct HashMapNode;
struct sqQueen;
struct Stack;


typedef GraphEdge* SLDataType;

typedef struct SeqList
{
	int size;
	SLDataType* n;
	int capacity;
}SQL;


void SeqListCheckCapacity(SQL* ps);

void SeqListInit(SQL* ps);

void SeqListPushBack(SQL* ps, const SLDataType NewData);

void SeqListPopBack(SQL* ps);

void SeqListPushFront(SQL* ps, const SLDataType NewData);

void SeqListPopFront(SQL* ps);

void SeqListPushInsert(SQL* ps, const int index, const SLDataType NewData);

void SeqListEraseInsert(SQL* ps, const int index);

void SeqListModify(SQL* ps, const int index, const SLDataType NewData);

void SeqListSort(SQL* ps);

int SeqListFind(SQL* ps, const SLDataType Data);



typedef GraphNode* SListDataType;

typedef struct SingleList
{
	SListDataType Data;
	struct SingleList* next;
}SL;

void PrintSL(SL* ppead);

SL* BuySLNode(const SListDataType NewData, const SL* NewNext);

void SingleListPushBack(SL** pphead, const SListDataType NewData);

void SingleListPopBack(SL** pphead);

void SingleListPushFront(SL** pphead, const SListDataType NewData);

void SingleListPopFront(SL** pphead);

void SingleListPushInsert(SL** pphead, size_t n, const SListDataType NewData);

void SingleListEraseInsert(SL** pphead, size_t n);

SL* SingleListFind_Num(SL** pphead, size_t n);

void SingleListModify_Num(SL** pphead, size_t n, const SListDataType NewData);

SL* SingleListFind_Data(SL** pphead, const SListDataType Data);

void SingleListModify_Data(SL** pphead, const SListDataType Data, const SListDataType NewData);






typedef int GValDataType;



typedef struct GraphNode
{
	GValDataType val;
	int in;
	int out;
	SL* nexts;
	SQL* edges;

}GN;

typedef struct GraphEdge
{
	int weight;
	struct GraphNode* from;
	struct GraphNode* to;

}GE;


void BFS(GN* pG);

void DFS(GN* pG);

