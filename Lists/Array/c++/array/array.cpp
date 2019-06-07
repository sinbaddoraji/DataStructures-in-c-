#include <iostream>
#include "dynamicArray.h"

using namespace std;

dynamicArray<int> list;


int partition(dynamicArray<int> arr, int low, int high)
{
	
	int pivot = arr[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element 
			arr.swap(i,j);
		}
	}
	arr.swap(i + 1, high);
	return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(dynamicArray<int> arr, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main()
{
	list = { 0,0,0,0 };
	list += {1, 2, 4, 5};
	list.insert(10);
	list << 2;
	list << 34;
	list += 76;
	list += 23;
	list += 34;

	list.insertAt(3, 2);
	list.insertAt(3, 5);
	list.insertAt(6, 2);

	//list.swap(1, 2);
	quickSort(list, 0, list.length - 1);

	//list.remove(2);
	//list -= 2;
	//list.remove(3);
	//list.removeAt(0);
	//list.removeLastOf(3);

	for (int i = 0; i < list.length; i++)
	{
		cout << list[i];
		if (i != list.length - 1) cout << ", ";
		else cout << endl;
	}
	system("pause");
}

