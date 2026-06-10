//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//const int boundary = static_cast<int>(1e3);
//
//int r, ans = 0;
//vector<vector<int>> number(boundary + 1, vector<int>(boundary + 1,0));
//vector<vector<int>> dp(boundary + 1, vector<int>(boundary + 1,0));
//int Sum()
//{
//	for (int i = 1; i <= r; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + number[i][j];
//			ans = max(ans, dp[i][j]);
//		}
//	}
//
//	return ans;
//}
//
//int main()
//{
//	cin >> r;
//	
//	for (int i = 1; i <= r; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			cin >> number[i][j];
//		}
//	}
//
//	cout << Sum() << endl;
//}