using namespace std;
class QueueRing {
private:
	int* wait;
	int current;
	int maxLenght;
public:
	QueueRing(int n) {
		maxLenght = n;
		wait = new int[maxLenght];
		current = 0;
	}
	bool isEmpty() {
		return current == 0;
	}
	bool isFull() {
		return current == maxLenght;
	}

	void add(int a)
	{
		if (!isFull()) {
			wait[current++] = a;
		}
	}

	int extract() {
		if (!isEmpty()) {
			int temp = wait[0];
			for (int i = 1; i < current; i++)
				wait[i - 1] = wait[i];

			wait[current - 1] = temp;
			return temp;
		}
		else
		{
			return -1;
		}
	}
	void show() {
		for (int i = 0; i < current; i++)
			cout << wait[i] << " <- ";
	}
	~QueueRing() {
		delete[]wait;
	}
};
class Queue {
private:
	int* wait;
	int current;
	int maxLenght;
public:
	Queue(int n) {
		maxLenght = n;
		wait = new int[maxLenght];
		current = 0;
	}
	bool isFull() {
		return current == maxLenght;
	}
	bool isEmpty() {
		return current == 0;
	}
	int getCount() {
		return current;
	}
	void show() {
		for (int i = 0; i < current; i++)
			cout << wait[i] << " <- ";
	}
	void add(int a) {
		if (!isFull())
			wait[current++] = a;
	}
	int extract() {
		if (!isEmpty()) {
			int temp = wait[0];
			for (int i = 1; i < current; i++)
				wait[i - 1] = wait[i];

			current--;
			return temp;
		}
		else
		{
			return -1;
		}
	}

	~Queue() {
		delete[]wait;
	}
};
class QueuePriori {
private:
	int* wait;
	int* pr;
	int maxLenght;
	int current;
public:
	QueuePriori(int n) {
		maxLenght = n;
		wait = new int[maxLenght];
		pr = new int[maxLenght];
		current = 0;
	}

	bool isFull() {
		return current == maxLenght;
	}
	bool isEmpty() {
		return current == 0;
	}
	int getCount() {
		return current;
	}

	void add(int a, int p) {
		if (!isFull())
		{
			wait[current] = a;
			pr[current] = p;
			current++;
		}

	}

	int extract() {
		if (!isEmpty()) {
			int max_pr = pr[0];
			int max_pos = 0;
			for (int i = 0; i < current; i++) {
				if (max_pr < pr[i]) {
					max_pr = pr[i];
					max_pos = i;
				}
			}

			int temp_w = wait[max_pos];
			int temp_p = pr[max_pos];
			for (int i = max_pos; i < current - 1; i++)
			{
				wait[i] = wait[i + 1];
				pr[i] = pr[i + 1];
			}
			current--;
			return temp_w;
		}
		else
			return -1;
	}
	void show() {
		for (int i = 0; i < current; i++)
			cout << wait[i] << ":" << pr[i] << " ";
		cout << endl;
	}
	~QueuePriori() {
		delete[]wait;
		delete[]pr;
	}
};