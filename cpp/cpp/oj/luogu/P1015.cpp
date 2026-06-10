//#include <algorithm>
//#include <iostream>
//#include <vector>
//
//#define maxsize 0xff
//using namespace std;
//
//bool isEqual(const vector<int>& n1, const vector<int>& n2)
//{
//	if (n1.size() != n2.size())
//	{
//		return false;
//	}
//
//	for (int i = 0; i < static_cast<int>(n1.size()); i++)
//	{
//		if (n1[i] != n2[i])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	string N, M;
//
//	cin >> N;
//	cin >> M;
//
//	int lenN = static_cast<int>(N.length());
//	int lenM = static_cast<int>(M.length());
//
//	vector<int> num(maxsize);
//	vector<int> add_num(2);
//
//	for (int i = 0; i < lenM; i++)
//	{
//		num[i] = M[lenM - 1 - i] - '0';
//	}
//
//	bool Palindromic_Number = false;
//	int ans = 0;
//
//	for (int i = 1; i <= 30; i++)
//	{
//		vector<int> reverse_num(maxsize);
//		vector<int> new_num(maxsize);
//
//		for (int i = 0; i < lenM; i++)
//		{
//			reverse_num[i] = num[lenM - 1 - i] - '0';
//		}
//
//		int temp = 0;
//
//		for (int i = 0; i < lenM; i++)
//		{
//			new_num[i] = num[i] + reverse_num[i] + temp;
//			temp = new_num[i] / 10;
//			new_num[i] %= 10;
//		}
//
//		if (temp != 0)
//		{
//			new_num[i] = temp;
//		}
//
//		vector<int>reverse_new_num = new_num;
//		reverse(reverse_new_num.begin(), reverse_new_num.end());
//
//		if (isEqual(new_num, reverse_new_num) == 1)
//		{
//			Palindromic_Number = true;
//			break;
//		}
//		else
//		{
//			if (lenN == 1)
//			{
//				num[0] += N[0] - '0';
//			}
//			if (lenN == 2)
//			{
//				num[0] += N[1] - '0';
//				num[1] += N[0] - '0';
//			}
//
//			int Temp = 0;
//			for (int i = 0; i < lenM; i++)
//			{
//				num[i] += Temp;
//				Temp = num[i] / 10;
//				num[i] %= 10;
//			}
//
//			if()
//		}
//
//		ans++;
//	}
//
//	if (Palindromic_Number == 0)
//	{
//		cout << "Impossible!" << endl;
//	}
//	else
//	{
//		cout << ans << endl;
//	}
//
//	return 0;
//}