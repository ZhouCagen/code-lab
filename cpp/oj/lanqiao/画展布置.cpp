//#include <algorithm>
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <climits>
//using namespace std;
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<unsigned long long> Bi(n + 1, 0);
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> Bi[i];
//	}
//
//	sort(Bi.begin() + 1, Bi.end());
//
//	unsigned long long L = ULLONG_MAX;
//	for (int i = 1; i + m - 1 <= n; i++)
//	{
//		L = min(L, Bi[i + m - 1] * Bi[i + m - 1] - Bi[i] * Bi[i]);
//	}
//
//	cout << L << endl;
//
//	return 0;
//}