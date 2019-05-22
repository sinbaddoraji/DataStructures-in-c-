#include <iostream>

using namespace std;

class Node
{
public:
	Node* npx = NULL; //Pointer of next and previous
	int value;

	Node(int val) { value = val; }
};

class List
{
public:
	Node* start = NULL;
	Node* end = NULL;

	void insert(int value)
	{
		Node* node = new Node(value);

		if (start == NULL)
		{
			start = end = node;
		}
		else
		{
			//insert at list end

			//Make nex node the XOR of the last node and null
			node->npx = XOR (end, NULL);
			end->npx = XOR(node, XOR (end->npx, NULL));
			end = node;
		}

	}

	Node* XOR(Node* a, Node* b)
	{
		return (Node*)((intptr_t)a ^ (intptr_t)b);
	}

	

};

List list;

void displayValues()
{
	Node* cur = list.start; 
	Node* prev = NULL;
	Node* next;

	while (cur != NULL)
	{
		cout << cur->value << "\n";
		next = list.XOR(prev, cur->npx);

		prev = cur;
		cur = next;
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

