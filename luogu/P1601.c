//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main()
//{
//	char a[20] = { '\0' }, b[20] = { '\0' };
//	gets(a);
//	gets(b);
//	int c[20], d[20], e[20];
//	int len1 = strlen(a);
//	int len2 = strlen(b);
//	int i;
//	for (i = 0; i < len1; i++)
//	{
//		c[len1 - i] = a[i] - '0';
//	}
//	for (i = 0; i < len2; i++)
//	{
//		d[len2 - i] = b[i] - '0';
//	}
//	int len3 = len1 > len2 ? len1 : len2;
//	for (i = 1; i <= len3 + 1; i++)
//	{
//		e[i] += c[i] + d[i];
//		e[i + 1] = e[i] / 10;
//		e[i] %= 10;
//	}
//	if (e[len3 + 1] == 0 && len3 + 1 > 0)
//	{
//		len3--;
//	}
//	for (i = len3 + 1; i >0; i--)
//	{
//		printf("%d", e[i]);
//	}
//	return 0;
//}