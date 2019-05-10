#include <iostream>

using namespace std;

class Node
{
public:
	Node* previous = NULL;
	Node* next = NULL;
	int value;
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
			insert(node,start);
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

	void insert(Node* node, Node* cur)
	{
		if (cur == start && node->value < cur->value)
		{
			Node* temp = node; // New node to be added to start
			start->previous = NULL; // Remove node linking backwords
			temp->next = start; //Link current start to be its next link

			temp->next->previous = temp;

			start = temp;
		}
		else if ((node->value < end()->value) && (node->value > start->value))
		{
			cur = end();
			while (true)
			{
				if (cur->previous == NULL) break;

				if (node->value < cur->previous->value) cur = cur->previous;
				else break;
			}

			Node* temp = cur; // Temp copy of cur
			temp->previous = node; //Link node to it as its previous node

			node->previous = cur->previous; // Set new node's previous as cur's previous
			node->next = temp;

			cur = temp; // Replace cur with temp copy
		}
		else
		{
			if (cur->next == NULL) cur->next = node;
			else
			{
				while (true)
				{
					if (node->value > cur->next->value)
						cur = cur->next;
					else break;
					

					if (cur->next == NULL) break;
				}

				//Insert value between current and it's next value

				Node* temp = cur->next; // Next node

				cur->next = node;
				node->next = temp;
				node->previous = cur;

			}
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

