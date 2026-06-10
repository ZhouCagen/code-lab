//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//int n,k;
//vector<int>num;
//long long ans;
//
//bool isPrimeNumber(int n)
//{
//	if (n == 1) return false;
//
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0) return false;
//	}
//
//	return true;
//}
//void DFS(int count, long long sum, int start)
//{
//	if (count == k)
//	{
//		if (isPrimeNumber(sum) == 1)
//		{
//			ans++;
//		}
//	}
//
//	for (int i = start; i < n; i++)
//	{
//		DFS(count + 1, sum + num[i], i + 1);
//	}
//	return;
//}
//
//int main()
//{
//	cin >> n >> k;
//	for (int i = 0; i < n; i++)
//	{
//		int tempnum;
//		cin >> tempnum;
//		num.push_back(tempnum);
//	}
//	DFS(0, 0, 0);
//
//	cout << ans << endl;
//
//	return 0;
//}