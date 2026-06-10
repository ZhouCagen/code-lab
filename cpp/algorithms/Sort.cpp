//#include <algorithm>
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Sort
//{
//public:
//	static void Bubblesort(vector<int> array);
//	static void Selectionsort(vector<int> array);
//	static void Insertionsort(vector<int> array);
//	static void Redixsort(vector<int> array);
//	void Quicksort(vector<int> array);
//	void Mergesort(vector<int> array);
//	void Heapsort(vector<int> array);
//	void Bucketsort(vector<int> array);
//	void Shellsort(vector<int> array);
//};
//
//
//void Sort::Bubblesort(vector<int> array)
//{
//	int count = int(array.size());
//	for (int i = 0; i < count - 1; i++)
//	{
//		for (int j = 0; j < count - 1 - i; j++)
//		{
//			if (array[j] > array[j + 1])
//			{
//				int temp = array[j];
//				array[j] = array[j + 1];
//				array[j + 1] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i < count; i++)
//	{
//		cout << array[i] << " ";
//	}
//
//	cout << endl;
//}
//
//void Sort::Selectionsort(vector<int> array)
//{
//	int count = int(array.size());
//
//	for (int i = 0; i < count; i++)
//	{
//		int MinimumPosition = i;
//		for (int j = i + 1; j < count; j++)
//		{
//			if (array[j] < array[MinimumPosition])
//			{
//				MinimumPosition = j;
//			}
//		}
//		swap(array[i], array[MinimumPosition]);
//	}
//
//	for (int i = 0; i < count; i++)
//	{
//		cout << array[i] << " ";
//	}
//
//	cout << endl;
//}
//
//void Sort::Insertionsort(vector<int> array)
//{
//	int count = int(array.size());
//	for (int i = 1; i < count; i++)
//	{
//		int no_insert = array[i];
//		int j = i - 1;
//		while (j >= 0 && array[j] > no_insert)
//		{
//			array[j + 1] = array[j];
//			j--;
//		}
//		array[j + 1] = no_insert;
//	}
//
//	for (int i = 0; i < count; i++)
//	{
//		cout << array[i] << " ";
//	}
//
//	cout << endl;
//}
//
//void Sort::Redixsort(vector<int> array)
//{
//
//}
//
//int main()
//{
//	vector<int> array = { 83, 54, 76, 98, 4, 26, 47, 61, 12, 35 };
//	Sort::Bubblesort(array);
//	Sort::Selectionsort(array);
//	Sort::Insertionsort(array);
//
//}