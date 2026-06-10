#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
有 n 件物品和一个大小为 m 的背包，第 i 个物品的价值为 w_i，体积为 v_i。每个物品属于一个组，同组内最多只能选择一个物品
从「在所有物品中选择一件」变成了「从当前组中选择一件」，于是就对每一组进行一次 0-1 背包就可以了。
*/

int groupKnapsackDP(vector<vector<int>>& weights, vector<vector<int>>& values, vector<int>& counts, int cap)
{
	int n = weights.size();
	vector<int> dp(cap + 1, 0);

	for (int i = 0; i < n; i++)
	{
		for (int c = cap; c >= 0; c--)
		{
			for (int k = 0; k < counts[i] && k < weights[i].size(); k++)
			{
				if (c >= weights[i][k])
				{
					dp[c] = max(dp[c], dp[c - weights[i][k]] + values[i][k]);
				}
			}
		}
	}
	return dp[cap];
}