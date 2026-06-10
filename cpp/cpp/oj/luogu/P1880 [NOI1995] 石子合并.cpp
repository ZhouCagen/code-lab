//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
//const int boundary = static_cast<int>(1e2);
//
//int main()
//{
//	int N;
//	cin >> N;
//	vector<int> stones(boundary + 1, 0);
//
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> stones[i];
//	}
//
//	vector<int> prefixSum(2 * N + 1, 0);
//	vector<vector<int>> dpMin(2 * N + 1, vector<int>(2 * N + 1, INT_MAX));
//	vector<vector<int>> dpMax(2 * N + 1, vector<int>(2 * N + 1, INT_MIN));
//
//	for (int i = 1; i <= N; i++)
//	{
//		prefixSum[i] = prefixSum[i - 1] + stones[i];
//		dpMin[i][i] = 0;
//		dpMax[i][i] = 0;
//	}
//
//	for (int i = 1; i <= N; i++)
//	{
//		prefixSum[i + N] = prefixSum[i + N - 1] + stones[i];
//		dpMin[i + N][i + N] = 0;
//		dpMax[i + N][i + N] = 0;
//	}
//
//	for (int len = 1; len <= N; len++)
//	{
//		for (int i = 1; i + len - 1 <= 2 * N; i++)
//		{
//			int end = i + len - 1;
//			for (int j = i; j < end; j++)
//			{
//				dpMin[i][end] = min(dpMin[i][end], dpMin[i][j] + dpMin[j + 1][end] + prefixSum[end] - prefixSum[i - 1]);
//				dpMax[i][end] = max(dpMax[i][end], dpMax[i][j] + dpMax[j + 1][end] + prefixSum[end] - prefixSum[i - 1]);
//			}
//		}
//	}
//
//	int minCost = INT_MAX;
//	int maxCost = INT_MIN;
//
//	for (int i = 1; i <= N; i++)
//	{
//		minCost = min(minCost, dpMin[i][i + N - 1]);
//		maxCost = max(maxCost, dpMax[i][i + N - 1]);
//	}
//
//	cout << minCost << endl << maxCost << endl;
//}
