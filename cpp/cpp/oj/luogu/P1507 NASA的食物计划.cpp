//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	int maxh, maxt, n;
//	cin >> maxh >> maxt >> n;
//
//	vector<int> hi(n + 1, 0);
//	vector<int> ti(n + 1, 0);
//	vector<int> ki(n + 1, 0);
//
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> hi[i] >> ti[i] >> ki[i];
//	}
//
//	vector<vector<int>> dp(maxh + 1, vector<int>(maxt + 1, 0));
//	
//	for (int x = 1; x <= n; x++)
//	{
//		for (int y = maxh; y >= hi[x]; y--)
//		{
//			for (int z = maxt; z >= ti[x]; z--)
//			{
//				dp[y][z] = max(dp[y][z], dp[y - hi[x]][z - ti[x]] + ki[x]);
//			}
//		}
//	}
//
//	cout << dp[maxh][maxt] << endl;
//
//	return 0;
//}