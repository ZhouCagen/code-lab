//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//const int boundary = static_cast<int>(1e5);
//
//vector<int> Pi(boundary + 1, 0);
//int main()
//{
//	int N;
//	cin >> N;
//	
//	int ans = 0;
//
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> Pi[i];
//		Pi[i] = max(Pi[i], Pi[i - 1] + Pi[i]);
//		ans = max(Pi[i], ans);
//	}
//
//	cout << ans;
//}