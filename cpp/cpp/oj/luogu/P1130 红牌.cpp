//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//const int boundary = 2e3;
//
//int n, m, ans = 1000000;
//vector<vector<int>>number(boundary + 1, vector<int>(boundary + 1,0));
//vector<vector<int>>dp(boundary + 1, vector<int>(boundary + 1, 0));
//
//int minDay()
//{
//	for (int j = 1; j <= m; j++)
//	{
//		dp[1][j] = number[1][j];
//	}
//	for (int i = 2; i <= n; i++)
//	{
//		dp[i - 1][0] = dp[i - 1][m];
//		for (int j = 1; j <= m; j++)
//		{
//			dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + number[i][j];
//		}
//	}
//	for (int j = 1; j <= m; j++)
//	{
//		ans = min(ans, dp[n][j]);
//	}
//
//	return ans;
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			cin >> number[i][j];
//		}
//	}
//
//	cout << minDay() << endl;
//} 