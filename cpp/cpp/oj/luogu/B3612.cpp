//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n + 1, 0);
//	vector<int> b(n + 1, 0);
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//		b[i] = b[i - 1] + a[i];
//	}
//
//	int m;
//	cin >> m;
//	for (int i = 1; i <= m; i++)
//	{
//		int c, d;
//		cin >> c >> d;
//		cout << b[d] - b[c - 1] << endl;
//	}
//
//	return 0;
//}