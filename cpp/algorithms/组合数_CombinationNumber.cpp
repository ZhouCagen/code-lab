/*
	组合数公式：
	C（n,m）= n!/( m! * (n-m)!)
	C（n,m）= C（n,n-m）
	C (n,m）= C (n-1.m-1)+ C (n-1,m)

*/

// 组合数代码实现

/*
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


unsigned long long factorial(int n)
{
	if (n < 0) return 0;

	else if (n == 0 || n == 1) return 1;

	else return n * factorial(n - 1);
}

unsigned long long combination_Recursion(int n, int k)
{
	if (k > n) return 0;

	else if (k == 0 || k == n) return 1;

	else return factorial(n) / (factorial(k) * factorial(n - k));
}


// 利用 C(n, k) = C(n-1, k-1) + C(n-1, k) 
unsigned long long combination_DynamicRecursion(int n, int k)
{
	vector<vector<unsigned long long>> C(n + 1, vector<unsigned long long>(k + 1, 0));

	for (int i = 0; i <= n; i++)
	{
		C[i][0] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= min(i, k); j++)
		{
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}

	return C[n][k];
}

// 动态规划 优化空间复杂度：
unsigned long long combination_DynamicRecursion_Coptimization(int n, int k)
{
	vector<unsigned long long> C(k + 1, 0);

	C[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = min(i, k); j > 0; j--)
		{
			C[j] += C[j - 1];
		}
	}

	return C[k];
}

unsigned long long combination_Direct(int n, int k)
{
	if (k > n) return 0;

	if (k > n - k) k = n - k;  // C(n, k) = C(n, n-k)

	unsigned long long result = 1;
	for (int i = 1; i <= k; i++)
	{
		result = result * (n - i + 1) / (i); // C(n, m) = (n - m + 1)/m  *C(n, m-1)
	}

	return result;
}


int main()
{
	int n, k;
	std::cout << "Enter n and k: ";
	cin >> n >> k;
	std::cout << "Combination_Recursion： C(" << n << ", " << k << ") = " << combination_Recursion(n, k) << std::endl;
	std::cout << "Combination_DynamicRecursion： C(" << n << ", " << k << ") = " << combination_DynamicRecursion(n, k) << std::endl;
	std::cout << "Combination_DynamicRecursion_Coptimization： C(" << n << ", " << k << ") = " << combination_DynamicRecursion_Coptimization(n, k) << std::endl;
	std::cout << "combination_Direct： C(" << n << ", " << k << ") = " << combination_Direct(n, k) << std::endl;

	return 0;
}
	
*/
