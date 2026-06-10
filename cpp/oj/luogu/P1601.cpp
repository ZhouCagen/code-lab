//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//#define MAXSIZE 520
//int main()
//{
//	string a, b;
//	cin >> a >> b;
//	size_t lena = a.length(), lenb = b.length();
//	vector<int>num1(MAXSIZE, 0), num2(MAXSIZE, 0);
//	int count = 0;
//	for (int i = lena - 1; i >= 0; i--)
//	{
//		num1[count++] = a[i] - '0';
//	}
//	
//	count = 0;
//	for (int i = lenb - 1; i >= 0; i--)
//	{
//		num2[count++] = b[i] - '0';
//	}
//	vector<int>num3(MAXSIZE, 0);
//	int lenmax = max(lena, lenb);
//
//	int temp = 0;
//
//	for (int i = 0; i < lenmax; i++)
//	{
//		num3[i] = num1[i] + num2[i] + temp;
//		temp = num3[i] / 10;
//		num3[i] %= 10;
//	}
//
//	if (temp != 0)
//	{
//		num3[lenmax] = temp;
//		lenmax++;
//	}
//	for (int i = lenmax - 1; i >= 0; i--)
//	{
//		cout << num3[i];
//	}
//
//	return 0;
//}