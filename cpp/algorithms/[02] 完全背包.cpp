#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 完全背包：动态规划 */
int unboundedKnapsackDP(vector<int> weights, vector<int> values, int cap)
{
	int n = weights.size();
	vector<vector<int>> dp(n + 1, vector<int>(cap + 1.0));
	for (int i = 1; i <= n; i++)
	{
		for (int c = 0; c <= cap; c++)
		{
			if (weights[i - 1] > cap)
			{
				dp[i][c] = dp[i - 1][c];
			}
			else
			{
				dp[i][c] = max(dp[i - 1][c], dp[i][c - weights[i - 1]] + values[i - 1]);
			}
		}
	}
	return dp[n][cap];
}

/* 完全背包：空间优化后的动态规划 */
int unboundedKnapsackDPComp(vector<int> weights, vector<int> values, int cap)
{
	int n = weights.size();
	vector<int> dp(cap + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int c = 0; c <= cap; c++)
		{
			if (weights[i - 1] > c)
			{
				dp[c] = dp[c];
			}
			else
			{
				dp[c] = max(dp[c], dp[c - weights[i - 1]] + values[i - 1]);
			}
		}
	}

	return dp[cap];
}