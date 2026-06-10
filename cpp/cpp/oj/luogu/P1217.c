//#include<stdio.h>
//#include<math.h>
//int digit(int x, int n)
//{
//	return x % (int)pow(10, n) / (int)pow(10, n - 1);
//}
//int main()
//{
//	int i, a, b, j;
//	scanf("%d %d", &a, &b);
//	for (i = a; i <= b; i++)
//	{
//		if (i % 2 == 1)
//		{
//			int len = (int)log10(i) + 1;
//			int sum = 0;
//			for (j = 1; j <= len; j++)
//			{
//				sum += digit(i, j) * (int)pow(10, len - j);
//			}
//			if (sum == i)
//			{
//				int have = 0;
//				for (j = 2; j <= sqrt(i); j++)
//				{
//					if (i % j == 0)
//					{
//						have = 1;
//						break;
//					}
//				}
//				if (have == 0)	
//				{
//					printf("%d\n", i);
//				}
//			}
//		}
//	}
//	return 0;
//}