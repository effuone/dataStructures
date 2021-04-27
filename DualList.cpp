#include "DualList.h"
#include "iostream"

int main() {
	DList lst;
	int len = 8;
	int a[] = { 2,3,2,4,3,5,4,6 };


	for (int i = 0; i < len; i++)
		if (i % 2 == 0)
			lst.addToBegin(a[i]);
		else
			lst.addToEnd(a[i]);

	lst.print();
	return 0;
}