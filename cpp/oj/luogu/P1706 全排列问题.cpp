//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n;
//
//vector<int> mark;
//vector<int> answer;
//
//void DFS(int count)
//{
//	if (count == n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			cout << "    " << answer[i];
//		}
//		cout << endl;
//		return;
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		if (!mark[i])
//		{
//			mark[i] = 1;
//			answer[count] = i;
//			DFS(count + 1);
//			mark[i] = 0;
//		}
//	}
//}
//
//int main()
//{
//	cin >> n;
//	mark = vector<int>(n + 1, 0);
//	answer = vector<int>(n, 0);
//	DFS(0);
//	return 0;
//}