//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int boundary = 10;
//int N, K;
//vector<vector<int>> matrix(boundary + 1, vector<int>(boundary + 1));
//int dx[8] = { -1,-1,0,1,1,1,0,-1 };
//int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
//string path;
//bool isVisit[boundary + 1][boundary + 1];
//bool isThrough[boundary + 1][boundary + 1][boundary + 1][boundary + 1];
//
//bool DFS(int x, int y)
//{
//	if (x == N && y == N)
//	{
//		return path.size() == N * N - 1;
//	}
//	isVisit[x][y] = true;
//	for (int i = 0; i <= 7; i++)
//	{
//		int nx = x + dx[i], ny = y + dy[i];
//		if (nx > 0 && nx <= N && ny > 0 && ny <= N &&isVisit[nx][ny]==false && isThrough[x][y][nx][ny] == false)
//		{
//			if (matrix[nx][ny] == (matrix[x][y] + 1) % K)
//			{
//				if (isThrough[x][ny][nx][y] == false && isThrough[nx][y][x][ny] == false)
//				{
//					isThrough[x][y][nx][ny] = true;
//					path += i + '0';
//					if (DFS(nx, ny))	return true;
//					path.erase(path.end() - 1);
//					isThrough[x][y][nx][ny] = false;
//				}
//			}
//		}
//	}
//	isVisit[x][y] = false;
//	return false;
//}
//
//int main()
//{
//	cin >> N >> K;
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			cin >> matrix[i][j];
//		}
//	}
//
//	if (DFS(1, 1) == true)
//	{
//		cout << path << endl;
//	}
//	else
//	{
//		cout << "-1" << endl;
//	}
//
//	return 0;
//}