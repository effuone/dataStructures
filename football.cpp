#include <iostream>
#include <random>
#include <string>
#include "tree.h"
using namespace std;

Tree tour;

void football(char commands[][25], int n)
{
	tnode* temp;
	int p1_result = 0;
	int p2_result = 0;
	for (int k = 0; k < 2; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n - 1; ++j)
			{
				temp = new tnode;
				if (k == 0)
				{
					strcpy_s(temp->name, 25 * sizeof(char), commands[i]);
					strcpy_s(temp->oppName, 25 * sizeof(char), commands[i]);
				}
				else
				{
					strcpy_s(temp->name, 25 * sizeof(char), commands[j]);
					strcpy_s(temp->oppName, 25 * sizeof(char), commands[j]);
				}

				p1_result = random() % 10;
				p2_result = random() % 10;

				if (p1_result > p2_result)
				{
					temp->pOwner = 3;
					temp->pOwner = 0;
				}
				else if (p1_result == p2_result)
				{
					temp->pOwner = 1;
					temp->pOwner = 1;
				}
				else
				{
					temp->pOwner = 0;
					temp->pOwner = 3;
				}
				sprintf_s(temp->match, "%d-%d", p1_result, p2_result);
				tour.insert(temp);
			}
		}
	}
}

int main()
{
	const int N = 9;
	char commands[N][25]{
	"Manchester United",
	"Barcelona",
	"Kairat",
	"Chelsea",
	"Arsenal",
	"PSG",
	"Shakhter",
	"Astana",
	"Taraz"
	};

	football(commands, N);
	tour.print(tour.getRoot());
	system("Pause>nul");
}