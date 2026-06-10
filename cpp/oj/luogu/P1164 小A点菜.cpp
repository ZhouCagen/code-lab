//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	int N, M;
//	cin >> N >> M;
//
//	vector<int> ai(N + 1, 0);
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> ai[i];
//	}
//
//	int ans = 0;
//	vector<int> dp(M + 1, 0);
//
//	dp[0] = 1;
//
//	for (int i = 1; i <= N; i++)
//	{
//		for (int cap = M; cap >= ai[i]; cap--)
//		{
//			dp[cap] += dp[cap - ai[i]];
//		}
//	}
//
//	cout << dp[M] << endl;
//}