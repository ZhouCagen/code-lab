//#include<iostream>
//#include<cmath>
//
//using namespace std;
//
//bool isPrimeNumber(int number)
//{
//	if (number == 2 || number == 3)
//	{
//		return 1;
//	}
//
//	if (number % 6 != 1 && number % 6 != 5)
//	{
//		return 0;
//	}
//
//	for (int i = 5; i <= sqrt(number); i += 6)
//	{
//		if (number % i == 0 || number % (i + 2) == 0)
//		{
//			return 0;
//		}
//	}
//
//	return 1;
//}
//
//bool isPalindromeNumber(int number)
//{
//	int Number[10], position = 1;
//	while (number > 0)
//	{
//		Number[position] = number % 10;
//		number /= 10;
//		position++;
//	}
//
//	for (int i = 1; i <= position / 2; i++)
//	{
//		if (Number[i] != Number[position - i])
//		{
//			return 0;
//		}
//	}
//	
//	return 1;
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	int min_number, max_number;
//	cin >> min_number >> max_number;
//	
//	for (int i = min_number; i <= max_number; i++)
//	{
//		if (i % 2 == 0)
//		{
//			continue;
//		}
//		
//		if (isPrimeNumber(i) == 1)
//		{
//			if (isPalindromeNumber(i) == 1)
//			{
//				cout << i << endl;
//			}
//		}
//	}
//
//	return 0;
//}
//
// 
// 



//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	
//}