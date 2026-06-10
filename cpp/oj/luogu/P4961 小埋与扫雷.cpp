//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int boundary = static_cast<int>(1e3);
//int n, m, ans;
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };
//vector<vector<int>> matrix(boundary + 1, vector<int>(boundary + 1, 0));
//vector<vector<bool>> space(boundary + 1, vector<bool>(boundary + 1, 0));
//bool isSpace(int x, int y)
//{
//	if (matrix[x][y] == 1)
//	{
//		return false;
//	}
//	for (int i = 0; i < 8; i++)
//	{
//		int nx = x + dx[i], ny = y + dy[i];
//		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
//		{
//			if (matrix[nx][ny] == 1)
//			{
//				return false;
//			}
//		}
//	}
//
//	return true;
//}
//
//bool isNumber(int x, int y)
//{
//	if (matrix[x][y] == 1)
//	{
//		return false;
//	}
//
//	for (int i = 0; i < 8; i++)
//	{
//		int nx = x + dx[i], ny = y + dy[i];
//		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
//		{
//			if (matrix[nx][ny] == 1)
//			{
//				return true;
//			}
//		}
//	}
//
//	return false;
//}
//
//void DFS(int x, int y)
//{
//	space[x][y] = 0;
//
//	for (int i = 0; i < 8; i++)
//	{
//		int nx = x + dx[i], ny = y + dy[i];
//		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && space[nx][ny] == 1)
//		{
//			DFS(nx, ny);
//		}
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			cin >> matrix[i][j];
//		}
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			space[i][j] = isSpace(i, j);
//		}
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (isNumber(i, j) == true)
//			{
//				bool isExist = false;
//				for (int k = 0; k < 8; k++)
//				{
//					int nx = i + dx[k], ny = j + dy[k];
//					if (space[nx][ny] == true)
//					{
//						isExist = true;
//						break;
//					}
//				}
//
//				if (isExist == false)
//				{
//					ans++;
//				}
//			}
//		}
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (space[i][j] == 1)
//			{
//				ans++;
//				DFS(i, j);
//			}
//		}
//	}
//
//	cout << ans << endl;
//
//	return 0;
//}