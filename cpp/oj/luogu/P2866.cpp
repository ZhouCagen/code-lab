//#include <iostream>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//int main()
//{
//	long long N;
//	cin >> N;
//
//	vector<int>heights(N + 1);
//
//	for (long long i = 1; i <= N; i++)
//	{
//		cin >> heights[i];
//	}
//
//	stack<int>stack_Monotonic;
//
//	long long ans = 0;
//
//	for (long long i = 1; i <= N; i++)
//	{
//		while (!stack_Monotonic.empty() && stack_Monotonic.top() <= heights[i])
//		{
//			stack_Monotonic.pop();
//		}
//
//		ans += stack_Monotonic.size();
//
//		stack_Monotonic.push(heights[i]);
//	}
//
//	cout << ans;
//
//	return 0;
//}