//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//const int boundary = 1e2;
//
//
//int T, M;
//vector<int> weights(boundary + 1);
//vector<int> values(boundary + 1);
//
//int DPComp()
//{
//	vector<vector<int>> dp(M + 1, vector<int>(T + 1));
//	for (int i = 1; i <= M; i++)
//	{
//		for (int j = 1; j <= T; j++)
//		{
//			if (weights[i] > j)
//			{
//				dp[i][j] = dp[i - 1][j];
//			}
//			else
//			{
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
//			}
//		}
//	}
//
//	return dp[M][T];
//}
//
//int main()
//{
//	cin >> T >> M;
//	for (int i = 1; i <= M; i++)
//	{
//		cin >> weights[i] >> values[i];
//	}
//
//	cout << DPComp() << endl;
//
//}


//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//const int boundary = 1e2;
//
//
//int T, M;
//vector<int> weights(boundary + 1);
//vector<int> values(boundary + 1);
//
//int DPComp()
//{
//	vector<int> dp(T + 1, 0);
//	for (int i = 1; i <= M; i++)
//	{
//		for (int j = T; j >= weights[i]; j--)
//		{
//			dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
//		}
//	}
//	return dp[T];
//}
//
//int main()
//{
//	cin >> T >> M;
//	for (int i = 1; i <= M; i++)
//	{
//		cin >> weights[i] >> values[i];
//	}
//
//	cout << DPComp() << endl;
//}