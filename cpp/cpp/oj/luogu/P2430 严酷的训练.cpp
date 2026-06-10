//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	int stats_WKY, stats_Wang;
//	cin >> stats_WKY >> stats_Wang;
//
//	int m, n;
//	cin >> m >> n;
//
//	vector<int> time_WKY(n + 1, 0);
//	for (int i = 1; i <= n; i++)
//	{
//		int time_Wang;
//		cin >> time_Wang;
//		time_WKY[i] = stats_Wang / stats_WKY * time_Wang;
//	}
//	vector<pair<int, int>> values(m + 1, { 0,0 });
//	for (int i = 1; i <= m; i++)
//	{
//		cin >> values[i].first >> values[i].second;
//	}
//
//	int time_limit;
//	cin >> time_limit;
//
//	vector<int> dp(time_limit + 1, 0);
//
//	for (int i = 1; i <= m; i++)
//	{
//		for (int c = time_limit; c >= time_WKY[values[i].first]; c--)
//		{
//			dp[c] = max(dp[c], dp[c - time_WKY[values[i].first]] + values[i].second);
//		}
//	}
//
//	cout << dp[time_limit] << endl;
//}