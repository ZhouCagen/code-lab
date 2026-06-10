//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//const int boundary = 20;
//
//int n, m;
//vector<vector<int>> viewpoint(boundary + 1, vector<int>(boundary + 1));
//vector<bool> vis(boundary + 1);
//int maxPath = 0;
//
//void DFS(int position, int sum)
//{
//	vis[position] = true;
//	for (int i = 1; i <= n; i++)
//	{
//		if (viewpoint[position][i] && !vis[i])
//		{
//			DFS(i, sum + viewpoint[position][i]);
//		}
//	}
//	vis[position] = false;
//	maxPath = max(maxPath, sum);
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++)
//	{
//		int tempNum1, tempNum2, tempDistance;
//		cin >> tempNum1 >> tempNum2 >> tempDistance;
//		viewpoint[tempNum1][tempNum2] = tempDistance;
//		viewpoint[tempNum2][tempNum1] = tempDistance;
//	}
//	//for (int i = 1; i <= n; i++)
//	//{
//	//	for (int j = 1; j <= n; j++)
//	//	{
//	//		cout << viewpoint[i][j] << " ";
//	//	}
//	//	cout << endl;
//	//}
//	for (int i = 1; i <= n; i++)
//	{
//		DFS(i, 0);
//	}
//	cout << maxPath;
//}