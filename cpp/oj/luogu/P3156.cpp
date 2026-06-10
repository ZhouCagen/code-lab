//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	long long int n;
//	cin >> n;
//	int m;
//	cin >> m;
//	vector<unsigned long long int>ID;
//	for (long long i = 0; i < n; i++)
//	{
//		unsigned long long int id;
//		cin >> id;
//		ID.emplace_back(id);
//		/*
//			ID[i] = id;  为错误操作
//			当你声明vector<unsigned long long int> ID;时，它默认是一个空向量，不包含任何元素。
//			然后，你在循环中直接通过ID[i] = id;来访问不存在的元素，这导致了越界访问，从而引发了段错误。
//
//			预先分配足够的空间给ID向量  
//			vector<unsigned long long int> ID(n + 1); // 分配n+1个元素的空间，因为索引从0到n 
//		*/
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		long long num;
//		cin >> num;
//		cout << ID[num - 1] << endl;
//	}
//	return 0;
//}