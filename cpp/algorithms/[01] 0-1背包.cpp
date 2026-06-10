#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 0-1 背包：暴力搜索 */
int knapsackDFS(vector<int> &weights,vector<int> &values,int i,int c)
{
	if (i == 0 || c == 0)
	{
		return 0;
	}
	
	if (weights[i - 1] > c)
	{
		return knapsackDFS(weights, values, i - 1, c);
	}

	int no = knapsackDFS(weights, values, i - 1, c);
	int yes = knapsackDFS(weights, values, i - 1, c - weights[i - 1]) + values[i - 1];

	return max(no, yes);
}
	//  由于每个物品都会产生不选和选两条搜索分支，因此时间复杂度为 O(2^n)
 
/* 0-1 背包：记忆性搜索 */
int knapsackDFSMem(vector<int> &weights, vector<int> &values, vector<vector<int>> &memorys, int i, int c)
{
	if (i == 0 || c == 0)
	{
		return 0;
	}

	if (memorys[i][c] != -1)
	{
		return memorys[i][c];
	}

	if (weights[i - 1] > c)
	{
		return knapsackDFSMem(weights, values, memorys, i - 1, c);
	}

	int no = knapsackDFSMem(weights, values, memorys, i - 1, c);
	int yes = knapsackDFSMem(weights, values, memorys, i - 1, c - weights[i - 1]) + values[i - 1];

	memorys[i][c] = max(no, yes);

	return memorys[i][c];
}

/* 0-1 背包：动态规划 */

int knapsackDP(vector<int> &weights, vector<int> &values, int cap)
{
	int n = weights.size();
	vector<vector<int>> dp(n + 1, vector<int>(cap + 1,	0));
	for (int i = 1; i <= n; i++)
	{
		for (int c = 0; c <= cap; c++)
		{
			if (weights[i - 1] > c)
			{
				dp[i][c] = dp[i - 1][c];
			}
			else
			{
				dp[i][c] = max(dp[i - 1][c], dp[i - 1][c - weights[i - 1]] + values[i - 1]);
			}
		}

	}

	return dp[n][cap];
}

/* 0-1 背包：空间优化后的动态规划 */
int knapsackDPComp(vector<int> &weights, vector<int> &values, int cap)
{
	int n = weights.size();
	vector<int>dp(cap + 1,0);

	for (int i = 1; i <= n; i++)
	{
		for (int c = cap; c >= weights[i - 1]; c--)
		{

			dp[c] = max(dp[c], dp[c - weights[i - 1]] + values[i - 1]);
		}
	}
	return dp[cap];
}