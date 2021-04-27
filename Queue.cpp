#include "Queue.h"
#pragma once
#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy(int xpos, int ypos);
/*
Queue - очередь

Длина-конец очереди
Начало

Максимальное значение очереди

FIFO - First IN First OUT
*/

int main() {
	QueueRing left(20);

	int l[] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 10; i++)
		left.add(l[i]);

	for (int j = 0; j < rand() % 5; j++) {
		for (int i = 0; i < 3; i++) {
			gotoxy(5, 5 + i);
			cout << left.extract();
		}
		Sleep(2000);
	}
	return 0;
}

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOutput, scrn);

}

