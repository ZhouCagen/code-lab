//#include <iostream>
//using namespace std;
//
//int a, b, c, frequency;
//
//void round()
//{
//	int tempa = a;  
//	int tempb = b;
//	int tempc = c;
//	a = (tempb + tempc) / 2; 
//	b = (tempa + tempc) / 2;
//	c = (tempa + tempb) / 2;
//	return;
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int T;
//	cin >> T;
//
//	for (int i = 1; i <= T; i++)
//	{
//
//		cin >> a >> b >> c >> frequency;
//		for (int j = 1; j <= frequency; j++)
//		{
//			round();
//			if (a == b && b == c)
//			{
//				break;
//			}
//		}
//		cout << a << " " << b << " " << c << endl;
//	}
//
//	return 0;
//}