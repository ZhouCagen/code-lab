#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>

using namespace std;

pair<int,int> linearRangeDP(vector<int>& stones)
{
	int n = static_cast<int>(stones.size());
	if (n == 0) return { 0,0 };

	vector<int> prefixSum(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		prefixSum[i] = prefixSum[i - 1] + stones[i - 1];
	}

	vector<vector<int>> dpMin(n + 1, vector<int>(n + 1, INT_MAX));
	vector<vector<int>> dpMax(n + 1, vector<int>(n + 1, INT_MIN));
	for (int i = 1; i <= n; i++)
	{
		dpMin[i][i] = 0;
		dpMax[i][i] = 0;
	}

	for (int len = 2; len <= n; len++)
	{
		for (int i = 1; i + len - 1 <= n; i++)
		{
			int end = i + len - 1;
			for (int j = i; j < end; j++)
			{
				dpMin[i][end] = min(dpMin[i][end], dpMin[i][j] + dpMin[j + 1][end] + prefixSum[end] - prefixSum[i - 1]);
				dpMax[i][end] = max(dpMax[i][end], dpMax[i][j] + dpMax[j + 1][end] + prefixSum[end] - prefixSum[i - 1]);
			}
		}
	}

	return { dpMin[1][n] ,dpMax[1][n] };
}

//int main() 
//{
//	vector<vector<int>> tests = {
//		{3, 1, 5, 2},  // 最小22，最大22
//		{1, 2, 3},     // 最小9，最大11
//		{4, 2, 3, 5},  // 最小28，最大28
//		{7, 6, 5, 1}   // 最小34，最大49
//	};
//
//	for (auto& t : tests) {
//		auto result = linearRangeDP(t);  // 先接收整个pair
//		int minCost = result.first;
//		int maxCost = result.second;
//
//		cout << "Stones: ";
//		for (int s : t) cout << s << " ";
//		cout << "\nMin cost: " << minCost << "  Max cost: " << maxCost << "\n\n";
//	}
//	return 0;
//}