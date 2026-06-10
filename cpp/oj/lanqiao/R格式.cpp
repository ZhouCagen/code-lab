/*
#include <iostream>
#include <cmath>
using namespace std;

int numberRound(float number)
{
	return static_cast<int>(number + 0.5);
}

int main()
{
	int conversionParameters;
	float number;
	cin >> conversionParameters >> number;

	float result = static_cast<float>(pow(2, conversionParameters)) * number;
	cout << numberRound(result);

	return 0;
}
*/


//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	string d;
//	cin >> n >> d;
//	vector<int> number;
//	int count = 0, position = 0;
//
//	for (int i = d.size() - 1; i >= 0; i--)
//	{
//		if (d[i] != '.')
//		{
//			number.push_back(d[i] - '0');
//		}
//		else
//		{
//			position = count;
//		}
//		count++;
//	}
//
//	while (n != 0)
//	{
//		int temp = 0;
//
//		for (int i = 0; i < number.size(); i++)
//		{
//			number[i] = number[i] * 2 + temp;
//			if (number[i] >= 10)
//			{
//				temp = number[i] / 10;
//				number[i] %= 10;
//			}
//			else
//			{
//				temp = 0;
//			}
//		}
//
//		if (temp != 0)
//		{
//			number.push_back(temp);
//		}
//
//		n--;
//	}
//
//	if (position != 0 && number[position - 1] >= 5)
//	{
//		int temp = 1;
//		for (int i = position; i < number.size(); i++)
//		{
//			number[i]++;
//			if (number[i] >= 10)
//			{
//				number[i] -= 10;
//			}
//			else
//			{
//				temp = 0;
//				break;
//			}
//		}
//
//		if (temp != 0)
//		{
//			number.push_back(temp);
//		}
//	}
//
//	for (int i = number.size() - 1; i >= position; i--)
//	{
//		cout << number[i];
//	}
//
//	return 0;
//
//}