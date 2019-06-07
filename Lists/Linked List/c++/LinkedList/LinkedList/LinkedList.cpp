#include <iostream>

using namespace std;

class Node
{
public:
	Node* next = NULL;
	int value;
};

class List
{
public:
	Node* start = NULL;
	Node* end = NULL;

	void insert(int value)
	{
		Node* node = new Node;
		node->value = value;

		if (start == NULL)
		{
			start = node;
			end = node;
		}
		else
		{
			end->next = node;
			end = node;
		}
	}

	
};

List list;

void displayValues()
{
	Node* cur = list.start; 
	while (true)
	{
		cout << cur->value << "\n";
		cur = cur->next;
		if (cur == NULL) break;
	}
}

int main()
{
	list.insert(3);
	list.insert(2);
	list.insert(2);
	list.insert(4);
	list.insert(1);
	list.insert(6);
	
	displayValues();
	system("pause");
}

