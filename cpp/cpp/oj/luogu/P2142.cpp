//#include <iostream>
//#include <vector>
//using namespace std;
//#define MAXSIZE 0xffff
//
//int main()
//{
//	string a, b;
//	cin >> a >> b;
//
//	size_t lena = a.length(), lenb = b.length();
//
//	vector<int>num1(MAXSIZE, 0), num2(MAXSIZE, 0);
//
//	if (lena < lenb || (lena == lenb && a < b))
//	{
//		cout << "-";
//		string temp = a;
//		a = b;
//		b = temp;
//
//		size_t lentemp = lena;
//		lena = lenb;
//		lenb = lentemp;
//	}
//
//	for (int i = 0; i < lena; ++i)
//	{
//		num1[i] = a[lena - 1 - i] - '0';
//	}
//
//	for (int i = 0; i < lenb; ++i)
//	{
//		num2[i] = b[lenb - 1 - i] - '0';
//	}
//
//	vector<int>num3(lena, 0);
//
//	for (int i = 0; i < lena; i++)
//	{
//		if (num1[i] < num2[i])
//		{
//			num1[i] += 10;
//			num3[i] = num1[i] - num2[i];
//			num1[i + 1]--;
//		}
//		else
//		{
//			num3[i] = num1[i] - num2[i];
//		}
//	}
//
//	for (int i = int(lena) - 1; i >= 0; i--)
//	{
//		if (num3[i] == 0 && lena > 1)
//		{
//			lena--;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	for (int i = int(lena) - 1; i >= 0; i--)
//	{
//		cout << num3[i];
//	}
//
//	return 0;
//}