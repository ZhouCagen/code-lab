//#include<stdio.h>
//#include<math.h>
//void prime(int a[],int l)
//{
//	int i, j, h = 2;
//	a[1] = 2;
//	for (i = 3; i <= l; i++)
//	{
//		int have = 0;
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				have = 1;
//				break;
//			}
//		}
//		if (have == 0)
//		{
//			a[h++] = i;
//		}
//	}
//	int sum = a[1];
//	int c = 0;
//	for (i = 1; sum <= l; i++)
//	{
//		if (l == 2)
//		{
//			printf("2\n");
//			c = 1;
//			break;
//		}
//		sum += a[i + 1];
//		printf("%d\n", a[i]);
//		c++;
//	}
//	printf("%d", c);
//}
//int main()
//{
//	int a[10000];
//	int l;
//	scanf("%d", &l);
//	prime(a, l);
//}