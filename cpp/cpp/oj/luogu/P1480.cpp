



//高精度除高精度 有个TLE

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//#define MAXSIZE 0xffff
//
//class Division
//{
//public:
//	int MAX(int lena, vector<int>& num1, vector<int>& num2)
//	{
//		for (int i = lena - 1; i >= 0; i--)
//		{
//			if (num1[i] > num2[i])
//			{
//				return 1;
//			}
//			else if (num1[i] < num2[i])
//			{
//				return -1;
//			}
//		}
//		return 0;
//	}
//
//	void ShiftLeft(int lena, vector<int>& num2, vector<int>& newnum2, int shiftlen)
//	{
//		if (shiftlen <= 0)
//		{
//			newnum2 = num2;
//			return;
//		}
//		else
//		{
//			for (int i = lena - 1; i >= 0; i--)
//			{
//				if (i - shiftlen >= 0)
//				{
//					newnum2[i] = num2[i - shiftlen];
//				}
//				else
//				{
//					newnum2[i] = 0;
//				}
//			}
//		}
//		return;
//	}
//
//	void Substract(int lena, vector<int>& num1, vector<int>& newnum2)
//	{
//		for (int i = 0; i < lena; i++)
//		{
//			num1[i] -= newnum2[i];
//			if (num1[i] < 0)
//			{
//				num1[i] += 10;
//				num1[i + 1]--;
//			}
//		}
//		return;
//	}
//};
//
//int main()
//{
//	string a, b;
//	cin >> a >> b;
//
//	if (b == "0")
//	{
//		cout << "输入错误 0不能作为除数" << endl;
//		return 0;
//	}
//
//	vector<int>num1(MAXSIZE, 0), num2(MAXSIZE, 0);
//
//	int lena = a.length(), lenb = b.length();
//
//	int Shiftlen = lena - lenb;
//
//	vector<int>num(MAXSIZE, 0);
//
//	for (int i = 0; i < lena; i++)
//	{
//		num1[i] = a[lena - i - 1] - '0';
//	}
//
//	for (int i = 0; i < lenb; i++)
//	{
//		num2[i] = b[lenb - i - 1] - '0';
//	}
//
//	Division division;
//
//	vector<int>movednum2(MAXSIZE, 0);
//
//	int first_nonZero = 0;
//
//	while (division.MAX(lena, num1, num2) >= 0)
//	{
//		division.ShiftLeft(lena, num2, movednum2, Shiftlen);
//
//		while (division.MAX(lena, num1, movednum2) >= 0)
//		{
//			division.Substract(lena, num1, movednum2);
//			num[Shiftlen]++;
//		}
//
//		if (first_nonZero == 0 && num[Shiftlen] != 0)
//		{
//			first_nonZero = Shiftlen;
//		}
//		
//		Shiftlen--;
//	}
//
//	for (int i = first_nonZero; i >= 0; i--)
//	{
//		cout << num[i];
//	}
//
//	return 0;
//}
//
