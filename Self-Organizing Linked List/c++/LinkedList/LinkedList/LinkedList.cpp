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
	list.insert(10);
	list.insert(2);
	list.insert(34);
	list.insert(76);
	list.insert(23);
	list.insert(34);
	
	

	/*
	list.insert(3);
	list.insert(2);
	list.insert(2);
	list.insert(4);
	list.insert(1);
	list.insert(6);
	*/
	
	/*
	list.insert(9);
	list.insert(3);
	list.insert(8);
	list.insert(2);
	list.insert(5);
	list.insert(2);
	list.insert(4);
	list.insert(7);
	list.insert(1);
	list.insert(6);
	*/
	
	
	displayValues();
	system("pause");
}

