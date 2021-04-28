#include <iostream>
#include <random>
using namespace std;
random_device random;

template <typename T>
struct Element
{
	T data;
	Element<T>* next;
};
template <typename T>
class List
{
	Element <T>* begin;
	Element <T>* end;
	int count;
public:
	List() { begin = end = NULL; count = 0; }
	~List() { deleteAll(); }
	int getCount()
	{
		return count;
	}
	void deleteAll()
	{
		while (begin != 0)
		{
			Element <T>* temp = begin;
			begin = temp->next;
			delete temp;
		}
	}
	void addToTail(T d)
	{
		Element <T>* temp = new Element <T>;
		temp->data = d;
		temp->next = NULL;
		if (begin != NULL)
		{
			end->next = temp;
			end = temp;
		}
		else
		{
			begin = end = temp;
		}
	}
	void addToHead(T d)
	{
		Element <T>* temp = new Element <T>;
		temp->data = d;
		if (begin != NULL)
		{
			temp->next = begin;
			begin = temp;
		}
	}

	void addToSelPos(T element, int pos)
	{
		Element <T>* temp = begin;
		Element <T>* temp2 = new Element<T>;
		temp2->data = element;
		int i = 1;
		while (temp != end)
		{
			++i;
			if (i == pos)
			{
				break;
			}
			temp = temp->next;
		}
		temp2->next = temp->next;
		temp->next = temp2;
	}

	void delFromHead()
	{
		if (begin != NULL)
		{
			Element <T>* temp = begin;
			begin = temp->next;
			delete temp;
		}
	}
	void delFromTail()
	{
		Element <T>* temp = begin;
		while (temp->next != end)
		{
			temp = temp->next;
		}
		end = temp;
		temp = temp->next;
		delete temp;
		end->next = NULL;
	}
	void print()
	{
		Element <T>* temp = begin;
		while (temp != 0)
		{
			cout << temp->data << "";
			temp = temp->next;
		}
	}
};

int main()
{
	List<int> lst;

	lst.addToTail(1);
	lst.addToTail(2);
	lst.addToTail(3);
	lst.addToTail(4);
	lst.addToTail(5);

	lst.print();
	cout << endl;
	lst.addToSelPos(6, 3);
	lst.print();
	return 0;
}
