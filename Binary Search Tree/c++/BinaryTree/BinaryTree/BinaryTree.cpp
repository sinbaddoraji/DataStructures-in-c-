#include <iostream>

using namespace std;

class Tree
{
public:
	int value;
	Tree* left;
	Tree* right;
};

Tree* root;

//New node item
Tree* newNode(int value)
{
	Tree* output = new Tree;
	output->left = NULL;
	output->right = NULL;
	output->value = value;
	return output;
}

void addNode(int value, Tree* cur)
{
	//if the value being added is less than the node being checked
	//then go check left node 
	//else if node is null then node = new node with value
	
	//if the value being added is greater than the node being checked
	//then go check right node 
	//else if node is null then node = new node with value
	if (value < cur->value)
	{
		if (cur->left != NULL)addNode(value, cur->left);
		else cur->left = newNode(value);
	}
	else
	{
		if (cur->right != NULL)addNode(value, cur->right);
		else cur->right = newNode(value);
	}
}

void addNode(int value)
{
	if (root == NULL)
	{
		root = newNode(value);
		return;
	}
	addNode(value, root);
}

bool treeContains(int value)
{
	Tree* cur = root;
	while (value > cur->value)
	{
		if(cur->right != NULL)
			cur = cur->right;
		else break;
	}
	while (value < cur->value)
	{
		if (cur->left != NULL)
			cur = cur->left;
		else break;
	}
	return cur->value == value;
}


int main()
{
	addNode(5);
	addNode(4);
	addNode(6);
	addNode(3);
	addNode(7);
	addNode(2);

	//Check if the tree contains value from 0 to 10
	for (int i = 0; i <= 10; i++)
	{
		if (treeContains(i))
			cout << "Tree contains " << i << endl;
	}
	system("pause");
}