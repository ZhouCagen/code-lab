//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	unsigned long long f[1000];
//	f[0] = 1;
//	f[1] = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			f[i] += f[j - 1] * f[i - j];
//			f[i] %= 100;
//		}
//	}
//	cout << f[n] << endl;
//	return 0;
//}
