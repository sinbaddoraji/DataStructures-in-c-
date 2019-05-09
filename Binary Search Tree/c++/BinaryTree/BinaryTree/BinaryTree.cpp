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

Tree* newNode(int value)
{
	Tree* output = new Tree;
	output->left = NULL;
	output->right = NULL;
	output->value = value;
	return output;
}

void addNumber(int value, Tree* cur)
{
	if (value < cur->value)
	{
		if (cur->left != NULL)addNumber(value, cur->left);
		else cur->left = newNode(value);
	}
	else
	{
		if (cur->right != NULL)addNumber(value, cur->right);
		else cur->right = newNode(value);
	}
}

void addNumber(int value)
{
	if (root == NULL)
	{
		root = newNode(value);
		return;
	}
	addNumber(value, root);
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
	addNumber(5);
	addNumber(4);
	addNumber(6);
	addNumber(3);
	addNumber(7);
	addNumber(2);

	//Check if the tree contains value from 0 to 10
	for (int i = 0; i <= 10; i++)
	{
		if (treeContains(i))
			cout << "Tree contains " << i << endl;
	}
	system("pause");
}