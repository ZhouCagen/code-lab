/*
	给定一个长度为 n 的序列 A 和一个 长度为 m 的序列 B（n,m≤5000），求出一个最长的序列，使得该序列既是 A 的子序列，也是 B 的子序列。
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string a, string b)
{
	int lena = a.length(), lenb = b.length();

	vector<vector<int>> dp(lena + 1, vector<int>(lenb + 1, 0));
	for (int i = 1; i <= lena; i++)
	{
		for (int j = 1; j <= lenb; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	return dp[lena][lenb];
}

