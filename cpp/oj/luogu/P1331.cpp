//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int boundary = 1000;
//int r, c;
//vector<vector<char>> map(boundary + 1, vector<char>(boundary + 1));
//int dx[4] = { 0,-1,0,1 };
//int dy[4] = { -1,0,1,0 };
//bool isConnect(int x, int y)
//{
//	int count = 0;
//	if (map[x][y] == '#') count++;
//	if (map[x + 1][y] == '#')count++;
//	if (map[x][y + 1] == '#')count++;
//	if (map[x + 1][y + 1] == '#')count++;
//	if (count == 3) return true;
//
//	return false;
//}
//
//void DFS(int x, int y)
//{
//	map[x][y] = '*';
//	for (int i = 0; i < 4; i++)
//	{
//		if (x + dx[i] >= 1 && x + dx[i] <= r && y + dy[i] >= 1 && y + dy[i] <= c)
//		{
//			if (map[x + dx[i]][y + dy[i]] == '#')
//			{
//				DFS(x + dx[i], y + dy[i]);
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> r >> c;
//	for (int i = 1; i <= r; i++)
//	{
//		for (int j = 1; j <= c; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//
//	for (int i = 1; i < r; i++)
//	{
//		for (int j = 1; j < c; j++)
//		{
//			if (isConnect(i, j) == true)
//			{
//				cout << "Bad placement." << endl;
//				return 0;
//			}
//		}
//	}
//	
//	int count = 0;
//	for (int i = 1; i <= r; i++)
//	{
//		for (int j = 1; j <= c; j++)
//		{
//			if (map[i][j] == '#')
//			{
//				count++;
//				DFS(i, j);
//			}
//		}
//	}
//
//	cout << "There are " << count << " ships." << endl;
//}