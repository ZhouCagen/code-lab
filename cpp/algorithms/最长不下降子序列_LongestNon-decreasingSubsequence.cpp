/*
	给定一个长度为 n 的序列 A（n ≤ 5000），求出一个最长的 A 的子序列，满足该子序列的后一个元素不小于前一个元素。
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int longestincreasingSubsequence(vector<int> a)
{
	int lena = a.size();
	vector<int> dp(lena, 1);
	int ans = 1;
	for (int i = 1; i < lena; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] <= a[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(dp[i], ans);
			}
		}
	}

	return ans;
}
