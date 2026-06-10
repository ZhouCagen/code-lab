//#include<iostream>
//using namespace std;
//
//#define MAXSIZE 0xffff
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	int p_x[MAXSIZE], p_y[MAXSIZE], x_add[MAXSIZE], y_add[MAXSIZE];
//	for (int i = 0; i < n; i++)
//	{
//		int a, b, g, k;
//		cin >> a >> b >> g >> k;
//
//		p_x[i] = a;
//		p_y[i] = b;
//		x_add[i] = g;
//		y_add[i] = k;
//	}
//
//	int x, y;
//	cin >> x >> y;
//
//	int ans = -1;
//
//	for (int i = 0; i < n; i++)
//	{
//		if (x >= p_x[i] && x <= x_add[i] + p_x[i] && y >= p_y[i] && y <= y_add[i] + p_y[i])
//		{
//			ans = i + 1;
//		}
//	}
//
//	cout << ans << endl;
//
//	return 0;
//}