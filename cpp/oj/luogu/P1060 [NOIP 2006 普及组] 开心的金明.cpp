//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int> values(m + 1, 0);
//	vector<int> weights(m + 1, 0);
//
//	for (int i = 1; i <= m; i++)
//	{
//		cin >> values[i] >> weights[i];
//		weights[i] *= values[i];
//	}
//	
//	vector<int> dp(n + 1, 0);
//
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = n; j >= values[i]; j--)
//		{
//			dp[j] = max(dp[j], dp[j - values[i]] + weights[i]);
//		}
//	}
//
//	cout << dp[n] << endl;
//
//	return 0;
//}