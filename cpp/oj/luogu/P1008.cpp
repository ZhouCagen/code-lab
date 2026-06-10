//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a, b, c;
//	int f[9] = { 0 };
//	for (int i = 1; i <= 3; i++)
//	{
//		for (int j = 1; j <= 9; j++)
//		{
//			for (int k = 1; k <= 9; k++)
//			{
//
//				if (i == j || j == k || i == k)
//				{
//					continue;
//				}
//				a = i * 100 + j * 10 + k;
//				b = a * 2;
//				c = a * 3;
//
//				if (c > 1000)
//				{
//					return 0;
//				}
//
//				int d = b / 100, e = b % 100 / 10, f = b % 10;
//				int o = c / 100, p = c % 100 / 10, q = c % 10;
//
//				if (i + j + k + d + e + f + o + p + q == 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 && i * j * k * d * e * f * o * p * q == 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9)
//				{
//					cout << a << " " << b << " " << c << endl;
//				}
//			}
//		}
//	}
//	return 0;
//}