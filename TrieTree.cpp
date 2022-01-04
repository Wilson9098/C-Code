#define _CRT_SECURE_NO_WARNINGS 1

#include "TrieTree.h"

void InitTrieTree(TTNode* root)
{
	assert(root);

	root->P = 0;
	root->E = 0;
	root->nexts = new TTNode*[26];
	memset(root->nexts, 0, 26 * sizeof(TTNode*));
}

TTNode* BuyTTNode()
{
	TTNode* newNode = new TTNode;
	newNode->P = 0;
	newNode->E = 0;
	newNode->nexts = new TTNode*[26];
	memset(newNode->nexts, 0, 26 * sizeof(TTNode*));

	return newNode;
}

void TrieTreeInsert(TTNode* root, const char* string)
{
	assert(root);

	int i = 0;
	TTNode* cur = root;
	while (string[i])
	{
		int p = string[i++] - 'a';
		if (!cur->nexts[p])
		{
			cur->nexts[p] = BuyTTNode();
		}
		cur->nexts[p]->P++;
		cur = cur->nexts[p];
	}
	cur->E++;
	root->P++;
}

int TrieTreeSearch(TTNode* root, const char* string)
{
	assert(root);

	int i = 0; 
	TTNode* cur = root;
	while (string[i])
	{
		int p = string[i++] - 'a';
		if (!cur->nexts[p])
			return 0;
		cur = cur->nexts[p];
	}
	return cur->E;
}

int TrieTreePrefixNumber(TTNode* root, const char* pre)
{
	assert(root);

	int i = 0;
	TTNode* cur = root;
	while (pre[i])
	{
		int p = pre[i++] - 'a';
		if (!cur->nexts[p])
			return 0;
		cur = cur->nexts[p];
	}
	return cur->P;
}

void TrieTreeDelete(TTNode* root, const char* string)
{
	assert(root);

	if (!TrieTreeSearch(root, string))
		return;

	TTNode* cur = root;
	root->P--;
	
	int i = 0;

	while (string[i])
	{
		int p = string[i] - 'a';
		cur->nexts[p]->P--;
		
		if (!cur->nexts[p]->P)
		{
			while (string[i])
			{
				p = string[i++] - 'a';
				TTNode* Next = cur->nexts[p];

				cur->nexts[p] = NULL;
				if (cur != root)
				{
					delete[] cur->nexts;
					delete cur;
				}
				cur = Next;
			}
			delete[] cur->nexts;
			delete cur;
			return;
		}
		cur = cur->nexts[p];
		i++;
	}
	cur->E--;
}