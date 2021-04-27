#pragma once
#include <iostream>
#include <ctime>
#include <random>
using namespace std;
random_device random;

struct tnode
{
	int pOwner;
	int pOppos;
	char match[10];
	char name[25];
	char oppName[25];
	tnode* left;
	tnode* right;
	tnode* parent;
};

class Tree
{
private:
	tnode* root;
public:
	Tree() { root = nullptr; }
	void print(tnode* pCur)
	{
		if (pCur != 0)
		{
			print(pCur->left);
			cout << pCur->name << "(" << pCur->match << ")" << pCur->oppName << endl;
			print(pCur->right);
		}
	}
	tnode* min(tnode* pCur)
	{
		if (pCur != 0)
		{
			while (pCur->left != 0)
			{
				pCur = pCur->left;
			}
			return pCur;
		}
	}
	tnode* max(tnode* pCur)
	{
		if (pCur != 0)
		{
			while (pCur->right != 0)
			{
				pCur = pCur->left;
			}
			return pCur;
		}
	}
	tnode* search(tnode* pCur, char* k)
	{
		while (pCur != 0 && strcmp(k, pCur->name) != 0)
		{
			if (strcmp(k, pCur->name) < 0)
			{
				pCur = pCur->left;
			}
			else
			{
				pCur = pCur->right;
			}
		}
		return pCur;
	}
	tnode* next(tnode* pCur)
	{
		tnode* nextEl = 0;
		if (pCur != 0)
		{
			if (pCur->right != 0)
			{
				return min(pCur->right);
			}
			nextEl = pCur->parent;
			while (nextEl != 0 && pCur == nextEl->right)
			{
				pCur = nextEl;
				nextEl = nextEl->parent;
			}
		}
		return nextEl;
	}
	tnode* prev(tnode* pCur)
	{
		tnode* prevEl = 0;
		if (pCur != 0)
		{
			if (pCur->left != 0)
			{
				return max(pCur->left);
			}
			prevEl = pCur->parent;
			while (prevEl != 0 && pCur == prevEl->left)
			{
				pCur = prevEl;
				prevEl = prevEl->parent;
			}
		}
		return prevEl;
	}
	tnode* getRoot()
	{
		return root;
	}
	void insert(tnode* pCur)
	{
		pCur->left = NULL;
		pCur->right = NULL;
		tnode* y = 0;
		tnode* temp = root;
		while (temp != 0)
		{
			y = temp;
			if (strcmp(pCur->name, temp->name) < 0)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		pCur->parent = y;
		if (y == 0)
		{
			root = pCur;
		}
		else if (strcmp(pCur->name, y->name) < 0)
		{
			y->left = pCur;
		}
		else
		{
			y->right = pCur;
		}
	}
	void del(tnode* pCur)
	{
		if (pCur != 0)
		{
			tnode* temp;
			tnode* y;
			if (pCur->left == 0 && pCur->right == 0)
			{
				y = pCur;
			}
			else
			{
				y = next(pCur);
			}
			if (y->left != 0)
			{
				temp = y->left;
			}
			else
			{
				temp = y->right;
			}
			if (temp != 0)
			{
				temp->parent = y->parent;
			}
			if (y->parent == 0)
			{
				root = temp;
			}
			else if (y == y->parent->left)
			{
				y->parent->left = temp;

			}
			else
			{
				y->parent->right = temp;
			}
			if (y != pCur)
			{
				strcpy_s(pCur->name, 25 * sizeof(char), y->name);
				strcpy_s(pCur->oppName, 25 * sizeof(char), y->oppName);
				strcpy_s(pCur->match, 10 * sizeof(char), y->match);
				pCur->pOppos = y->pOppos;
				pCur->pOwner = y->pOwner;
			}
			delete y;
		}
		else
		{
			while (root != 0)
			{
				del(root);
			}
		}
	}
};

