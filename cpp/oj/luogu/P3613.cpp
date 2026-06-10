//#include<iostream>
//#include <vector>
//#define MAXSIZE 100000
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	int q;
//	cin >> q;
//	vector<vector<unsigned long long>>a(MAXSIZE, vector<unsigned long long>(MAXSIZE, 0));
//	for (int s = 1; s <= q; s++)
//	{
//		int num;
//		cin >> num;
//		if (num == 1)
//		{
//			int i;
//			cin >> i;
//			int j;
//			cin >> j;
//			unsigned long long k;
//			cin >> k;
//			if (k == 0)
//			{
//				a[i][j] = 0;
//			}
//			else
//			{
//				a[i][j] += k;
//			}
//		}
//		if (num == 2)
//		{
//			int i;
//			cin >> i;
//			int j;
//			cin >> j;
//			cout << a[i][j] << endl;
//		}
//	}
//	return 0;
//}