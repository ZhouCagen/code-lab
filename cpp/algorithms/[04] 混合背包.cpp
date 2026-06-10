#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 混合背包：属于 0-1 背包、完全背包或多重背包，然后根据类型套用相应的动态规划逻辑 */

int mixedKnapsackDP(vector<int>& weights, vector<int>& values, vector<int>& counts, int cap)
{
	int n = weights.size();
	vector<int> dp(cap + 1, 0);
	for (int i = 0; i < n; i++)
	{
		if (counts[i] == 1)
		{
			for (int c = cap; c >= weights[i]; c--)
			{
				dp[c] = max(dp[c], dp[c - weights[i]] + values[i]);
			}
		}
		else if (counts[i] == -1)
		{
			for (int c = weights[i]; c <= cap; c++)
			{
				dp[c] = max(dp[c], dp[c - weights[i]] + values[i]);
			}
		}
		else // 多重背包 (最多选 counts[i] 次，进行二进制优化) counts[i] >1
		{
			int num = counts[i], k = 1;
			vector<int> newWeights, newValues;
			while (num > k)
			{
				num -= k;
				newWeights.push_back(k * weights[i]);
				newValues.push_back(k * values[i]);
				k *= 2;
			}

			if (num > 0)
			{
				newWeights.push_back(num * weights[i]);
				newValues.push_back(num * values[i]);
			}

			for (int j = 0; j < newWeights.size(); j++)
			{
				for (int c = cap; c >= newWeights[j]; c--)
				{
					dp[c] = max(dp[c], dp[c - newWeights[j]] + newValues[j]);
				}
			}
		}
	}
	return dp[cap];
}
