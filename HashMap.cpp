#define _CRT_SECURE_NO_WARNINGS 1

#include "HashMap.h"



void InitHashMap(HMap* pm)
{
	assert(pm);

	int i = MAP_MAX_SIZE;
	HMNode** tmp1 = (HMNode**)malloc(i*sizeof(HMNode*));
	if (!tmp1)
	{
		puts("Intialize Failed");
		return;
	}
	pm->arr = tmp1;
	pm->Hashsize = 0;
	
	for (i -= 1; i >= 0; i--)
	{
		HMNode* tmp2 = (HMNode*)malloc(sizeof(HMNode));
		if (!tmp2)
		{
			puts("Intialize Failed");
			return;
		}

		pm->arr[i] = tmp2;
		memset(pm->arr[i], 0, sizeof(HMNode));
		/*pm->arr[i]->key = 0;
		pm->arr[i]->val = 0;
		pm->arr[i]->next = NULL;*/
	}
}

 unsigned int Hash(const HashKeyType key)
{
	unsigned int n = key;

	return n % MAP_MAX_SIZE;
}

 HMNode* HashMapFind(HMap* pm, HashKeyType key)
 {
	 assert(pm);

	 int i = Hash(key);
	 HMNode* cur = pm->arr[i]->next;

	 while (cur && cur->key != key)
	 {
		 cur = cur->next;
	 }

	 return cur;
 }

 void PrintHashMap(HMap* pm)
 {
	 assert(pm);

	 int i = 0;
	 int sz = MAP_MAX_SIZE;
	 for (i = 0; i < sz; i++)
	 {
		 printf("key = %d ", pm->arr[i]->key);
		 printf("val = %d\n", pm->arr[i]->val);
		 
		 HMNode* cur = pm->arr[i]->next;
		 while (cur)
		 {
			 printf("key = %d ", cur->key);
			 printf("val = %d\n", cur->val);
			 cur = cur->next;
		 }
		 puts("");
		
	 }
 }

 void HashMapInsert(HMap* pm, HashKeyType key, HashValType val)
 {
	 assert(pm);

	 HMNode* p = HashMapFind(pm, key);
	 if (p)
	 {
		 puts("This key has existed");
		 return;
	 }
	 else
	 {
		 int i = Hash(key);
		 HMNode* tmp = (HMNode*)malloc(sizeof(HMNode));
		 if (!tmp)
		 {
			 puts("Insert Failed");
			 return;
		 }

		 HMNode* Next = pm->arr[i]->next;
		 tmp->key = key;
		 tmp->val = val;
		 pm->arr[i]->next = tmp;
		 tmp->next = Next;
		 pm->Hashsize++;

	 }
 }

 void HashMapDelete(HMap* pm, HashKeyType key)
 {
	 assert(pm);

	 int i = Hash(key);
	 HMNode* cur = pm->arr[i]->next, * prev = pm->arr[i];
	 while (cur && cur->key != key)
	 {
		 prev = cur;
		 cur = cur->next;
	 }

	 if (cur)
	 {
		 prev->next = cur->next;
		 free(cur);
		 pm->Hashsize--;
	 }
 }

 int HashMapSize(HMap* pm)
 {
	 assert(pm);

	 return pm->Hashsize;
 }

 void DestroyHashMap(HMap* pm)
 {
	 assert(pm);

	 int i = 0;
	 int sz = MAP_MAX_SIZE;
	 for (i = 0; i < sz; i++)
	 {
		 HMNode* cur = pm->arr[i];
		 while (cur)
		 {
			 HMNode* Next = cur->next;
			 free(cur);
			 //cur->key = cur->val = 8; //test
			 cur = Next;
		 }
	 }

	 free(pm->arr);
 }
