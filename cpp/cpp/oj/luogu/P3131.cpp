//#include <iostream>
//#include <vector>
//#define ll long long
//using namespace std;
//
//int read()
//{
//	int x = 0, w = 1;
//	char ch = 0;
//	while (ch < '0' || ch>'9')
//	{
//		if (ch == '-') w = -1;
//		ch = getchar();
//	}
//	while (ch >= '0' && ch <= '9')
//	{
//		x = x * 10 + (ch - '0');
//		ch = getchar();
//	}
//
//	return x * w;
//
//}
//
//void write(int x)
//{
//	if (x < 0)
//	{
//		x = -x;
//		putchar('-');
//	}
//	if (x > 9)
//	{
//		write(x / 10);
//	}
//	putchar(x % 10 + '0');
//}
//
//
//int main()
//{
//	//ios::sync_with_stdio(false);
//	//cin.tie(nullptr);
//	//cout.tie(nullptr);
//
//	int N;
//	N = read();
//	vector<int> a(N + 1, 0);
//	vector<ll>  b(N + 1, 0);
//	for (int i = 1; i <= N; i++)
//	{
//		a[i] = read();
//		b[i] = b[i - 1] + a[i];
//	}
//
//	int count = 0;
//	for (int i = 0; i <= N; i++)
//	{
//		for (int j = i + count; j <= N; j++)
//		{
//			if ((b[j] - b[i]) % 7 == 0)
//			{
//				count = j - i;
//			}
//		}
//	}
//
//	write(count);
//
//	return 0;
//}