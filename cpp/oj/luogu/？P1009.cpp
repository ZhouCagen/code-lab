//#include<iostream>
//#include <vector>
//using namespace std;
//
//#define MAXSIZE 0xffff
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	vector<int>sum(MAXSIZE, 0);
//
//	sum[0] = 0;
//
//	int digit = 1;
//
//	for (int k = 1; k <= n; k++)
//	{
//		vector<int>tempsum(MAXSIZE, 0);
//		tempsum[0] = 1;
//		int tempdigit = 1;
//
//		for (int i = 2; i <= k; i++)
//		{
//			int temp = 0;
//			for (int j = 0; j < tempdigit; j++)
//			{
//				tempsum[j] = tempsum[j] * i + temp;
//				temp = tempsum[j] / 10;
//				tempsum[j] %= 10;
//			}
//			if (temp != 0)
//			{
//				tempsum[tempdigit] = temp;
//			}
//		}
//
//		digit = tempdigit;
//
//		for (int i = 0; i < digit; i++)
//		{
//			int Temp = 0;
//
//			sum[i] += tempsum[i] + Temp;
//			Temp = sum[i] / 10;
//			sum[i] %= 10;
//
//			if (Temp != 0)
//			{
//				sum[digit] += Temp;
//				digit++;
//			}
//		}
//
//		tempsum.clear();
//	}
//
//	for (int i = digit - 1; i >= 0; i--)
//	{
//		cout << sum[i];
//	}
//	return 0;
//}