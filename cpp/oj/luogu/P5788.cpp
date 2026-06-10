//#include<iostream>
//#include<stack>
//#include <vector>
//
//using namespace std;
//int main()
//{
//
//  // 关闭与C标准库的I/O同步，并解除cin和cout之间的绑定，以提高I/O性能  
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	long long n;
//	cin >> n;
//
//	vector<int>integers(n + 1);
//	vector<int>subscipt(n + 1);
//	stack<int>stack_monotonic;
//
//	for (long long i = 1; i <= n; i++)
//	{
//		cin >> integers[i];
//	}
//	for (long long i = n; i >= 1; i--)
//	{
//		while (!stack_monotonic.empty() && integers[stack_monotonic.top()] <= integers[i])
//		{
//			stack_monotonic.pop();
//		}
//
//		subscipt[i] = stack_monotonic.empty() ? 0 : stack_monotonic.top();
//
//		stack_monotonic.push(i);
//	}
//	for (long long i = 1; i <= n; i++)
//	{
//		cout << subscipt[i] << " ";
//	}
//	return 0;
//}