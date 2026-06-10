//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int boundary = 100;
//int n, m;
//vector<vector<char>> matrix(boundary + 1, vector<char>(boundary + 1));
//int dx[4] = { 0,-1,0,1 };
//int dy[4] = { -1,0,1,0 };
//
//void DFS(int x, int y)
//{
//	matrix[x][y] = '0';
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + dx[i], ny = y + dy[i];
//		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
//		{
//			if (matrix[nx][ny] != '0')
//			{
//				DFS(nx, ny);
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			cin >> matrix[i][j];
//		}
//	}
//
//	int ans = 0;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (matrix[i][j] != '0')
//			{
//				ans++;
//				DFS(i, j);
//			}
//		}
//	}
//
//	cout << ans << endl;
//}