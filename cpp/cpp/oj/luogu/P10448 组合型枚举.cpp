//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n, m;
//
//vector<int> mark;
//vector<int> answer;
//
//void DFS(int count, int number)
//{
//	if (count == m)
//	{
//
//		for (int i = 0; i < m; i++)
//		{
//			cout << answer[i] << " ";
//		}
//		cout << endl;
//
//		return;
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		if (i > number)
//		{
//			mark[i] = 1;
//			answer[count] = i;
//			DFS(count + 1, i);
//			mark[i] = 0;
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//	mark = vector<int>(n + 1, 0);
//	answer = vector<int>(m, 0);
//
//	DFS(0, 0);
//	return 0;
//}