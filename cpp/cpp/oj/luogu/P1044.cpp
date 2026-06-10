//#include<iostream>
//using namespace std;
//
//int main()
//{
//	unsigned long long f[20];
//	f[0] = 1;
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		f[i] = f[i - 1] * (4 * i - 2) / (i + 1);
//	}
//	cout << f[n] << endl;
//	return 0;
//}



/*	
	ตÝน้ TLE
int dfs(int a, int b, int n)
{
	int ans = 0;
	if (b == 0 && n == 0)
	{
		return 1;
	}
	else if (n < 0)
	{
		return ans;
	}
	else if (b != 0)
	{
		ans += dfs(a + 1, b - 1, n) + dfs(a, b + 1, n - 1);
	}
	else
	{
		if (n == 0)
		{
			return ans;
		}
		else
		{
			ans += dfs(a, b + 1, n - 1);
		}
	}

	return ans;
}
int main()
{
	int n;
	cin >> n;
	cout << dfs(0, 0, n) << endl;
}

*/

