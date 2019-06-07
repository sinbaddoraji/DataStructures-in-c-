#include <iostream>

using namespace std;

class Node
{
public:
	Node* previous = NULL;
	Node* next = NULL;
	int value;

	Node(const Node& node)
	{ 
		previous = node.previous;
		next = node.next;
		value = node.value;
	}

	Node(){}
};

class List
{
public:
	Node* start = NULL;

	void insert(int value)
	{
		Node* node = new Node;
		node->value = value;

		if (start == NULL)
		{
			start = node;
		}
		else
		{
			node->previous = end();
			end()->next = node;
		}
	}

private:
	Node* end()
	{
		Node* output = start;

		while (output->next != NULL)
			output = output->next;

		return output;
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
	list.insert(10);
	list.insert(2);
	list.insert(34);
	list.insert(76);
	list.insert(23);
	list.insert(34);

	displayValues();
	system("pause");
}

