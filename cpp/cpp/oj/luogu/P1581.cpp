//#include<iostream>
//using namespace std;
//int main()
//{
//	int bit[7] = { 2,3,5,7,11,13 };
//	
//	int score[6] = { 0 };
//
//	int digit1[5] = { 0 }, digit2[5] = { 0 };
//
//	string s;
//	cin >> s;
//
//	string num1, num2;
//
//	size_t pos = s.find('+');
//	if (pos != string::npos)
//	{
//		num1 = s.substr(0, pos);
//		num2 = s.substr(pos + 1);
//	}
//	int len1 = num1.size() - 1, len2 = num2.size() - 1;
//
//	int count1 = 0;
//
//
//	while (len1 >= 0)
//	{
//		if (num1[len1] >= '0' && num1[len1] <= '9')
//		{
//			if (num1[len1 - 1] >= '0' && num1[len1 - 1] <= '9')
//			{
//				digit1[count1] = (num1[len1 - 1] - '0') * 10 + num1[len1] - '0';
//				len1--;
//			}
//			else
//			{
//				digit1[count1] = num1[len1] - '0';
//			}
//			count1++;
//		}
//		len1--;
//	}
//
//	int count2 = 0;
//
//	while (len2 >= 0)
//	{
//		if (num2[len2] >= '0' && num2[len2] <= '9')
//		{
//			if (num2[len2 - 1] >= '0' && num2[len2 - 1] <= '9')
//			{
//				digit2[count2] = (num2[len2 - 1] - '0') * 10 + num2[len2] - '0';
//				len2--;
//			}
//			else
//			{
//				digit2[count2] = num2[len2] - '0';
//			}
//			count2++;
//		}
//		len2--;
//	}
//
//	int maxcount = max(count1, count2);
//
//	int temp = 0;
//
//	for (int i = 0; i < maxcount; i++)
//	{
//		score[i] = digit1[i] + digit2[i] + temp;
//		
//		temp = score[i] / bit[i];
//
//		score[i] %= bit[i];
//	}
//
//	if (temp != 0)
//	{
//		score[maxcount++] = temp;
//	}
//	
//	for (int i = maxcount - 1; i >= 0; i--)
//	{
//		if (i != maxcount - 1)
//		{
//			cout << ",";
//		}
//
//		cout << score[i];
//	}
//
//	return 0;
//}