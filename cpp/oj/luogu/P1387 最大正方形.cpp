//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//const int boundary = static_cast<int>(1e2);
//
//int n, m;
//vector<vector<int>> matrix(boundary + 1, vector<int>(boundary + 1, 0));
//vector<vector<int>> dp(boundary + 1, vector<int>(boundary + 1, 0));
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			cin >> matrix[i][j];
//		}
//	}
//
//	int maxLength = 0;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (matrix[i][j] == 1)
//			{
//				dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
//				maxLength = max(maxLength, dp[i][j]);
//			}
//		}
//	}
//
//	cout << maxLength << endl;
//
//	return 0;
//}