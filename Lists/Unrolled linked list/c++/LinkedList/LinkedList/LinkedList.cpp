#include <iostream>

using namespace std;

class Node
{
	int availableIndex = 0;

public:
	Node* next = NULL;
	int value[3];
	

	bool isFull()
	{
		return availableIndex == 3;
	}

	void setValue(int val)
	{
		if (!isFull())
		{
			value[availableIndex] = val;
			availableIndex++;
		}
	}
};

class List
{
public:
	Node* start = new Node;
	Node* end = NULL;

	void insert(int value)
	{
		if (!start->isFull())
			start->setValue(value);
		else if(end == NULL)
		{
			Node* next = new Node;
			next-> setValue(value);

			start->next = next;
			end = next;
		}
		else if(end->isFull())
		{
			Node* next = new Node;
			next-> setValue(value);

			end->next = next;
			end = next;
		}
		else end->setValue(value);
		
	}

	
};

List list;

void displayValues()
{
	Node* cur = list.start; 
	while (true)
	{
		for (int i = 0;  i < 3; i++)
			cout << cur->value[i] << "\n";
		
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

