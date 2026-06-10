//#include <iostream>
//#include <vector>
//#include <climits>
//#include <algorithm>
//
//using namespace std;
//
//const int boundary = static_cast<int>(3e2);
//int main()
//{
//	int N;
//	cin >> N;
//	vector<int> stones(boundary + 1.0);
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> stones[i];
//	}
//
//	vector<int> prefixSum(boundary + 1, 0);
//	vector<vector<int>> dpMin(boundary + 1, vector<int>(boundary + 1, INT_MAX));
//	for (int i = 1; i <= N; i++)
//	{
//		prefixSum[i] = prefixSum[i - 1] + stones[i];
//		dpMin[i][i] = 0;
//	}
//
//	for (int len = 2; len <= N; len++)
//	{
//		for (int i = 1; i + len - 1 <= N; i++)
//		{
//			int end = i + len - 1;
//			for (int j = i; j < end; j ++ )
//			{
//				dpMin[i][end] = min(dpMin[i][end], dpMin[i][j] + dpMin[j + 1][end] + prefixSum[end] - prefixSum[i - 1]);
//			}
//		}
//	}
//
//	cout << dpMin[1][N] << endl;
//}