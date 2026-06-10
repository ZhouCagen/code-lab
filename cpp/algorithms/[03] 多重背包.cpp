#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 多重背包：动态规划 */
int completeKnapsackDP(vector<int> &weights, vector<int> &values, vector<int> &counts, int cap)
{
	int n = weights. size();
	vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int c = 0; c <= cap; c++)
		{
			dp[i][c] = dp[i - 1][c];
			for (int k = 1; k <= counts[i] && k * weights[i] <= c; k++)
			{
				dp[i][c] = max(dp[i][c], dp[i - 1][c - k * weights[i]] + k * values[i]);
			}
		}
	}
	return dp[n][cap];
}

/* 多重背包：空间优化后的动态规划 */
int completeKnapsackDPComp(vector<int>& weights, vector<int>& values, vector<int>& counts, int cap)
{
	int n = weights.size();
	vector<int> dp(cap + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int c = cap; c >= 0; c--)
		{
			for (int k = 1; k <= counts[i] && k * weights[i] <= c; k++)
			{
				dp[c] = max(dp[c], dp[c - k * weights[i]] + k * weights[i]);
			}
		}
	}
	return dp[cap];
}

/* 多重背包：二进制分组优化的动态规划 */
int completeKnapsackDPBinary(vector<int>& weights, vector<int>& values, vector<int>& counts, int cap)
{
	int n = weights.size();
	vector<int> dp(cap + 1, 0);
	vector<int> newWeights, newValues;
	int index = 0;
	for (int i = 1; i <= n; i++)
	{
		int c = 1, k = counts[i];
		while (k > c)
		{
			k -= c;
			newWeights.push_back(c * weights[i]);
			newValues.push_back(c * values[i]);
			c *= 2;
		}

		if (k > 0)
		{
			newWeights.push_back(k * weights[i]);
			newValues.push_back(k * values[i]);
		}
	}
	for (int i = 0; i < newWeights.size(); i++)
	{
		for (int c = cap; c >= newWeights[i]; c--)
		{
			dp[c] = max(dp[c], dp[c - newWeights[i]] + newValues[i]);
		}
	}

	return dp[cap];
}