#pragma once
#include "dynamicArray.h"
#include <iostream>
#include <initializer_list>

using namespace std;

template<typename T>
class Node
{
public:
	Node* previous = NULL;
	Node* next = NULL;
	T value;

	Node(const Node& node)
	{
		previous = node.previous;
		next = node.next;
		value = node.value;
	}

	Node() {}
};

template<typename T>
class dynamicArray
{
	T null = *(new T);
	Node<T>* start = NULL;

	Node<T>* end()
	{
		Node<T>* output = start;

		while (output->next != NULL)
			output = output->next;

		return output;
	}

public:
	int length = 1;
	dynamicArray(){}

	dynamicArray(initializer_list<T> l)
	{
		T* cur = (T*)l.begin();
		while (cur != l.end())
		{
			insert(*cur);
			cur += 1;
		}
	}

	void insert(T value)
	{
		Node<T>* node = new Node<T>;
		node->value = value;

		if (start == NULL) start = node;
		else insert(node, end());
	}

	void insert(Node<T>* node, Node<T>* cur)
	{
		//Insert value between current and it's next value

		Node<T>* temp = cur->next; // Next node

		cur->next = node;
		node->next = temp;
		node->previous = cur;

		length++;
	}

	void insertAt(Node<T>* node,int index)
	{
		Node<T>* cur = start;
		for (int i = 0; i < index - 1; i++)
		{
			if (cur->next == NULL) throw;
			else cur = cur->next;
		}

		insert(node, cur);
	}

	void insertAt(T value, int index)
	{
		Node<T>* node = new Node<T>;
		node->value = value;
		insertAt(node, index);
	}

	void removeStart()
	{
		start = start->next;
		delete start->previous;
	}

	void remove(Node<T>* node)
	{
		if (node == start)
		{
			removeStart();
			length--;
			return;
		}
		Node<T>* temp1 = node->previous;
		Node<T>* temp2 = node->next;

		Node<T>* next = node->next;
		Node<T>* previous = node->previous;
		
		next->previous = temp1;
		previous->next = temp2;

		temp2->previous = temp2;
		temp1->next = temp2;

		//node->next->previous = temp1;
		//node->previous->next = temp2;

		delete node;
		length--;
	}
	
	void remove(T value)
	{
		Node<T>* cur = start;
		for (int i = 0; i < length; i++)
		{
			if (cur->value == value)break;
			else cur = cur->next;
		}
		remove(cur);
	}

	void removeAt(int index)
	{
		Node<T>* cur = start;
		for (int i = 0; i < index - 1; i++)
		{
			if (cur->next == NULL) throw;
			else cur = cur->next;
		}
		remove(cur);
	}

	void removeLastOf(T value)
	{
		Node<T>* cur = start;
		Node<T>* rem = new Node<T>;

		int index = -1;
		for (int i = 0; i < length; i++)
		{
			if (cur->value == value)index = i;
			else cur = cur->next;
		}

		removeAt(index - 1);
	}

	void swap(int index1,int index2)
	{
		//Swap only node values
		if (index1 < length && index2 < length)
		{
			Node<T>* a = value(index1);
			Node<T>* b = value(index2);
			int c = value(index2)->value;

			b->value = a->value;
			a->value = c;
		}
	}


	Node<T>* value(int i)
	{
		Node<T>* cur = start;

		for (int index = 0; index != i; index++)
		{
			if (cur->next != NULL) cur = cur->next;
			else return NULL;
		}

		return cur;
	}

	T& operator[](int i)
	{
		return value(i)->value;
	}

	friend void operator<<(dynamicArray<T>& output, const T& value) 
	{
		output.insert(value);
	}

	friend void operator<<(dynamicArray<T>& output, const Node<T>* value)
	{
		output.insert(value);
	}

	friend void operator+=(dynamicArray<T>& output, const T& value)
	{
		output.insert(value);
	}

	friend void operator+=(dynamicArray<T>& output, const Node<T>* value)
	{
		output.insert(value);
	}

	friend void operator+=(dynamicArray<T>& a, initializer_list<T> b)
	{
		dynamicArray<T> c = b;
		a += c;
	}

	friend void operator+=(dynamicArray<T>& a, dynamicArray<T> b)
	{
		for (int i = 0; i < b.length; i++)  a += b[i];
	}


	friend void operator-=(dynamicArray<T>& output, const T& value)
	{
		output.remove(value);
	}

};

