//#include<iostream>
//#include <vector>
//using namespace std;
//
//#define MAXSIZE 0xffff
//
//int main()
//{
//	string a, b;
//	cin >> a >> b;
//
//	vector<int>num1(MAXSIZE, 0), num2(MAXSIZE, 0);
//
//	size_t lena = a.length(), lenb = b.length();
//	
//	int count = 0;
//
//	for (int i = int(lena) - 1; i >= 0; i--)
//	{
//		num1[count++] = a[i] - '0';
//	}
//
//	count = 0;
//
//	for (int i = int(lenb) - 1; i >= 0; i--)
//	{
//		num2[count++] = b[i] - '0';
//	}
//
//	int lenc = lena + lenb;
//
//	vector<int>num(lenc, 0);
//
//	for (int i = 0; i < lena; i++)
//	{
//		int temp = 0;
//		for (int j = 0; j < lenb; j++)
//		{
//			num[i + j] += num1[i] * num2[j] + temp;
//			temp = num[i + j] / 10;
//			num[i + j] %= 10;
//		}
//		num[i + lenb] = temp;
//	}
//
//	for (int i = lenc - 1; i >= 0; i--)
//	{
//		if (num[i] == 0 && lenc > 1)
//		{
//			lenc--;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	for (int i = lenc - 1; i >= 0; i--)
//	{
//		cout << num[i];
//	}
//
//	return 0;
//}