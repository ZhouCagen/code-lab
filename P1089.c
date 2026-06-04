//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int n, i, j;
//	scanf("%d", &n);
//	int* c = (int*)malloc(n * sizeof(int));
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &c[i]);
//	}
//	printf("0 ");
//	for (i = 1; i < n; i++)
//	{
//		int z = 0;
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (c[j] < c[i])
//			{
//				z++;
//			}
//		}
//		printf("%d ", z);
//	}
//	return 0;
//}