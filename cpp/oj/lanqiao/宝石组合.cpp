//#include <algorithm>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int gcd(int a, int b)
//{
//	return b ? gcd(b, a % b) : a;
//}
//
//int lcm(int a, int b)
//{
//	return a * b / gcd(a, b);
//}
//
//int LCM(int a, int b, int c)
//{
//	return lcm(lcm(a, b), c);
//}
//
//float Formula(int a, int b, int c)
//{
//	cout << "LCM" << LCM(a, b, c) << "   " << lcm(a, b) << "    " << lcm(b, c) << "    " << lcm(a, c) << "     " << endl;
//	return static_cast<float>((a * b * c * LCM(a, b, c)) / (lcm(a, b) * lcm(b, c) * lcm(a, c)));
//}
//
//bool compareGroups(vector<int> group1, vector<int>group2)
//{
//	sort(group1.begin(), group1.end());
//	sort(group2.begin(), group2.end());
//
//	for (int i = 0; i < 3; i++)
//	{
//		if (group1[i] < group2[i])
//		{
//			return true;
//		}
//		else if (group1[i] > group2[i])
//		{
//			return false;
//		}
//		else
//		{
//			continue;
//		}
//	}
//
//	return false;
//}
//
//int main()
//{
//	int gemNumber;
//	cin >> gemNumber;
//	vector<int>gemStoneSparkle(gemNumber + 1, 0);
//	for (int i = 1; i <= gemNumber; i++)
//	{
//		cin >> gemStoneSparkle[i];
//	}
//
//	int idxA = 1, idxB = 2, idxC = 3;
//	float minExquisiteness = Formula(gemStoneSparkle[1], gemStoneSparkle[2], gemStoneSparkle[3]);
//	for (int i = 1; i <= gemNumber - 2; i++)
//	{
//		for (int j = i + 1; j <= gemNumber - 1; j++)
//		{
//			for (int k = j + 1; k <= gemNumber; k++)
//			{
//				float tempExquisteness = Formula(gemStoneSparkle[i], gemStoneSparkle[j], gemStoneSparkle[k]);
//				cout << i << " " << j << " " << k << endl;
//				cout << tempExquisteness << endl << endl;
//				if (tempExquisteness < minExquisiteness)
//				{
//					idxA = i;
//					idxB = j;
//					idxC = k;
//				}
//
//				else if (tempExquisteness == minExquisiteness)
//				{
//					vector<int>tempGroup = { gemStoneSparkle[i],gemStoneSparkle[j],gemStoneSparkle[k] };
//					vector<int>minGroup = { gemStoneSparkle[idxA],gemStoneSparkle[idxB],gemStoneSparkle[idxC] };
//					if (compareGroups(tempGroup, minGroup) == 1)
//					{
//						idxA = i;
//						idxB = j;
//						idxC = k;
//					}
//				}
//			}
//		}
//	}
//
//	vector<int>Group = { gemStoneSparkle[idxA],gemStoneSparkle[idxB],gemStoneSparkle[idxC] };
//	sort(Group.begin(), Group.end());
//	for (int num : Group)
//	{
//		cout << num << " ";
//	}
//
//	return 0;
//}


/*
解析:
唯一分解定理:
任何一个大于1的自然数N，如果N不是质数，那么N可以唯一分解成有限个质数的乘积
N1=pl^al*p2^a2*...*pn^an
N2=p1^bl*p2^b2*...*pn^bn
则gcd(Nl,N2)=pl^min(al,bl)*p2^min(a2, b2)*...*pn^min(an, bn)
则lcm(N1,N2)=p1^max(a1,bl)*p2^max(a2, b2)*...*pn^max(an, bn)
假设Ha,Hb，Hc相同质因子的幂次分别为x,y,z则题目中的表达式等价于
x+y+z+max(x,y,z)-max(x,y)-max(y,z)-max(x,z)
*/




//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//const int boundary = 1e5;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>num;
//	for (int i = 0; i < n; i++)
//	{
//		int tempNum;
//		cin >> tempNum;
//		num.push_back(tempNum);
//	}
//	vector<vector<int>>fact(boundary + 1);
//	vector<vector<int>>group(boundary + 1);
//	for (int i = 1; i <= boundary; i++)
//	{
//		for (int j = i; j <= boundary; j += i)
//		{
//			fact[j].push_back(i);
//		}
//	}
//	sort(num.begin(), num.end());
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < fact[num[i]].size(); j++)
//		{
//			group[fact[num[i]][j]].push_back(num[i]);
//		}
//	}
//
//	for (int i = 1e5; i >= 0; i--)
//	{
//		if (group[i].size() >= 3)
//		{
//			cout << group[i][0] << " " << group[i][1] << " " << group[i][2];
//			break;
//		}
//	}
//}