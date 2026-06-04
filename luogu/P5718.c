//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int n, i, j;
//	scanf("%d", &n);
//	int* a = (int*)malloc(n * sizeof(int));
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = 0; j < n - i - 1; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				int temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//		}
//	}
//	int min = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (a[i] >= 0)
//		{
//			min = a[i];
//			break;
//		}
//	}
//	printf("%d", min);
//	return 0;
//}