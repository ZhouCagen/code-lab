//#include <iostream>
//#include <algorithm>
//#include <climits>
//using namespace std;
//
//const int boundary = 1000;
//
//int n;
//long long student[boundary + 1];
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> student[i];
//	}
//
//	unsigned long long prefixAnd[boundary + 1] = { 0 };
//
//	prefixAnd[1] = student[1];
//	for (int i = 2; i <= n; i++)
//	{
//		prefixAnd[i] = prefixAnd[i - 1] + student[i];
//	}
//
//	unsigned long long minDifference = ULLONG_MAX;
//	for (int i = 1; i < n; i++)
//	{
//		unsigned long long leftSum = prefixAnd[i];
//		unsigned long long rightSum = prefixAnd[n] - prefixAnd[i];
//		unsigned long long temp = (leftSum > rightSum) ? (leftSum - rightSum) : (rightSum - leftSum);
//		minDifference = min(temp, minDifference);
//	}
//
//	cout << minDifference << endl;
//
//	return 0;
//}



