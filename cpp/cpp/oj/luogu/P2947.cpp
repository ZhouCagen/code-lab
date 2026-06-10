//#include <iostream>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//int main()
//{
//	int N;
//	cin >> N;
//
//	vector<int>heights(N + 1);
//
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> heights[i];
//	}
//
//
//	vector<int>subscipt(N + 1);
//
//	stack<int>stack_Monotonic;
//
//	for (int i = N; i >= 0; i--)
//	{
//		while (!stack_Monotonic.empty() && heights[stack_Monotonic.top()] <= heights[i])
//		{
//			stack_Monotonic.pop();
//		}
//
//		subscipt[i] = stack_Monotonic.empty() ? 0 : stack_Monotonic.top();
//
//		stack_Monotonic.push(i);
//	}
//
//	for (int i = 1; i <= N; i++)
//	{
//		cout << subscipt[i] << endl;
//	}
//
//	return 0;
//}