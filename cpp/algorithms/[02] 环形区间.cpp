#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>

using namespace std;

pair<int,int> circularRangeDP(vector<int>& stones)
{
	int n = static_cast<int>(stones.size());
	if (n == 0) return{ 0,0 };

	vector<int> prefixSum(2 * n + 1, 0);
	vector<vector<int>> dpMin(2 * n + 1, vector<int>(2 * n + 1, INT_MAX));
	vector<vector<int>> dpMax(2 * n + 1, vector<int>(2 * n + 1, INT_MIN));

	for (int i = 1; i <= n; i++) 
	{
		prefixSum[i] = prefixSum[i - 1] + stones[i - 1];
		dpMin[i][i] = 0;
		dpMax[i][i] = 0;
	}

	for (int i = 1; i <= n; i++) 
	{
		prefixSum[i + n] = prefixSum[i + n - 1] + stones[i - 1];
		dpMin[i + n][i + n] = 0;
		dpMax[i + n][i + n] = 0;
	}

	for (int len = 2; len <= n; len++)
	{
		for (int i = 1; i + len - 1 <= 2 * n; i++)
		{
			int end = i + len - 1;
			for (int j = i; j < end; j++)
			{
				dpMin[i][end] = min(dpMin[i][end], dpMin[i][j] + dpMin[j + 1][end] + prefixSum[end] - prefixSum[i - 1]);
				dpMax[i][end] = max(dpMax[i][end], dpMax[i][j] + dpMax[j + 1][end] + prefixSum[end] - prefixSum[i - 1]);
			}
		}
	}

	int minCost = INT_MAX;
	int maxCost = INT_MIN;

	for (int i = 1; i <= n; i++)
	{
		minCost = min(minCost, dpMin[i][i + n - 1]);
		maxCost = max(maxCost, dpMax[i][i + n - 1]);
	}

	return { minCost,maxCost };
}

