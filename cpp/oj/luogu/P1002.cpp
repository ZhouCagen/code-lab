//#include<iostream>
//using namespace std;
//
//bool unpass(int m_x, int m_y, int x, int y)
//{
//	int unpass_x[9] = { m_x - 2,m_x - 2,m_x - 1,m_x - 1,m_x + 1,m_x + 1,m_x + 2,m_x + 2,m_x };
//	int unpass_y[9] = { m_y - 1,m_y + 1,m_y - 2,m_y + 2,m_y - 2,m_y + 2,m_y - 1,m_y + 1,m_y };
//
//	for (int i = 0; i < 9; i++)
//	{
//		if (x == unpass_x[i] && y == unpass_y[i])
//		{
//			return true;
//		}
//	}
//
//	return false;
//}
//
//int main()
//{
//	unsigned long long a[21][21] = { {0} };
//	int b_x, b_y;
//	cin >> b_x;
//	cin >> b_y;
//
//	int m_x, m_y;
//	cin >> m_x;
//	cin >> m_y;
//
//	a[0][0] = 1;
//
//	for (int i = 0; i <= b_x; i++)
//	{
//		for (int j = 0; j <= b_y; j++)
//		{
//			if (i == 0 && j == 0)
//			{
//				continue;
//			}
//
//			if (unpass(m_x, m_y, i, j) == 1)
//			{
//				continue;
//			}
//			else
//			{
//				if (i == 0)
//				{
//					a[i][j] = a[i][j - 1];
//				}
//				else if (j == 0)
//				{
//					a[i][j] = a[i - 1][j];
//				}
//				else
//				{
//					a[i][j] = a[i - 1][j] + a[i][j - 1];
//				}
//			}
//		}
//	}
//	if (m_x == 0 && m_y == 0 && b_x == 0 && b_y == 0)
//	{
//		cout << 0 << endl;
//	}
//	else
//	{
//		cout << a[b_x][b_y] << endl;
//	}
//	return 0;
//}