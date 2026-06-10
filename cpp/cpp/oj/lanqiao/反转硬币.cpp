//#include <bits/stdc++.h>
//using namespace std;
//
//long long ans1=0;
//
//long long f(vector< vector<int> > coin,int n,int m)
//{
//	long long ans=0;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			int count=0;
//			if(i+1>=1&&i+1<=n&&coin[i+1][j]==coin[i][j])
//			{	
//				count++;
//			}
//			if(i-1>=1&&i-1<=n&&coin[i-1][j]==coin[i][j])
//			{	
//				count++;
//			}
//			if(j+1>=1&&j+1<=m&&coin[i][j+1]==coin[i][j])
//			{
//				count++; 
//			}
//			if(j-1>=1&&j-1<=m&&coin[i][j-1]==coin[i][j])
//			{
//				count++;
//			}
//			ans+=count*count;
//		}
//	}
//	return ans;
//}
//
//void dfs(vector< vector<int> > coin,int n,int m,int count,long long ans1)
//{
//	if(count>n)
//	{
//		return;
//	}
//	
//	ans1=f(coin,n,m);
//	for(int i=count;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			
//			if(coin[i][j]==1)
//			{
//				coin[i][j]=0;
//			}
//			if(coin[i][j]==0)
//			{
//				coin[i][j]=1;
//			}			
//		}
//		ans1=max(ans1,f(coin,n,m));
//		dfs(coin,n,m,count+1,ans1);
//	}
//}
//
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int n,m;
//	cin>>n>>m;
//	vector< vector<int> > coin(n+1,vector<int>(m+1,0));
//	for(int i=1;i<=n;i++)
//	{
//		string s;
//		cin>>s;
//		int ldx=0;
//		for(int j=1;j<=m;j++)
//		{
//			coin[i][j]=s[ldx++]-'0';
//		}
//	}
//	vector<vector <int> > newcoin(n+1,vector<int>(m+1,0));
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<coin[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	
//	dfs(coin,n,m,1,ans1);
//	
//	cout<<ans1<<endl;
//	
//	return 0;
//}


#include <iostream>
#include <vector>
using namespace std;
using namespace std;

long long ans1 = 0;

// 计算得分
long long f(vector<vector<int>>& coin, int n, int m)
{
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int count = 0;
            if (i + 1 <= n && coin[i + 1][j] == coin[i][j])
                count++;
            if (i - 1 >= 1 && coin[i - 1][j] == coin[i][j])
                count++;
            if (j + 1 <= m && coin[i][j + 1] == coin[i][j])
                count++;
            if (j - 1 >= 1 && coin[i][j - 1] == coin[i][j])
                count++;
            ans += count * count;
        }
    }
    return ans;
}

// 深搜：每行可以选择是否翻转（0↔1）
void dfs(vector<vector<int>>& coin, int n, int m, int count, long long& ans1)
{
    if (count > n)
    {
        ans1 = max(ans1, f(coin, n, m));
        return;
    }

    // 不翻转当前行
    dfs(coin, n, m, count + 1, ans1);

    // 翻转当前行：0->1, 1->0
    for (int j = 1; j <= m; j++)
    {
        coin[count][j] ^= 1; // 直接异或1，0变1，1变0
    }

    dfs(coin, n, m, count + 1, ans1);

    // 翻回来，恢复原状
    for (int j = 1; j <= m; j++)
    {
        coin[count][j] ^= 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> coin(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            coin[i][j] = s[j - 1] - '0';
        }
    }

    dfs(coin, n, m, 1, ans1);

    cout << ans1 << endl;

    return 0;
}
