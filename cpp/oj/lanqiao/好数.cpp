//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int countDigits(int number)
//{
//	if (number == 0)
//	{
//		return 1;
//	}
//	return static_cast<int>(floor(log10(abs(number))) + 1);
//}
//
//int digitNumber(int number, int digit)
//{
//	return number % static_cast<int>(pow(10, digit)) / static_cast<int>(pow(10, digit - 1));
//}
//int main()
//{
//	int N;
//	cin >> N;
//
//	int goodNumberCount = 0;
//
//	for (int i = 1; i <= N; i++)
//	{
//		int countdigits = countDigits(i);
//
//		bool isGoodNumber = true;
//		for (int j = 1; j <= countdigits; j++)
//		{
//			if (((j % 2 == 0) && (digitNumber(i, j) % 2 != 0)) || ((j % 2 != 0) && (digitNumber(i, j) % 2 == 0)))
//			{
//				isGoodNumber = false;
//				break;
//			}
//		}
//		if (isGoodNumber == 1)
//		{
//			goodNumberCount++;
//		}
//	}
//
//	cout << goodNumberCount << endl;
//
//}