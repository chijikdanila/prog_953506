#include <iostream>
#include <malloc.h>
#include <stdio.h>
/*
Найти натуральное число из заданного интервала, в двоичном представлении которого больше всего единиц.
Вывести это число в двоичном и десятичном представлении.
*/

int main()
{
	int a = 0, b = 0, c = 0, d = 0, i = 0, m = 0;
	int sum1 = 0, num = 0, score = 0;
	printf("Write interval [a,b](a<b , b<524287 , a>0)\na=");
	scanf_s("%d", &a);
	printf("b=");
	scanf_s("%d", &b);
	char mas[21];
	do
	{
		d = a;
		do
		{
			c = a % 2;
			a /= 2;
			if (c == 1)
			{
				sum1++;
			}

			c = 0;
			i++;
		} while (a > 1);
		a = d;
		if (sum1 >= score)
		{
			score = sum1;
			num = a;
		}
		sum1 = 0;
		a++;
	} while (a < b);
	printf("\nYour number with the largest number of 1: %d\n", num);
	while (num > 1)
	{
		mas[m++] = (num % 2) + '0';
		num/= 2;
	}
	mas[m++] = a + '0';
	mas[m] = '\0';
	char tmp;
	for (i = 0; i < m / 2; i++)
	{
		tmp = mas[m];
		mas[m] = mas[m - 1 - i];
		mas[m - 1 - i] = tmp;
	}
	printf("Binary code:");
	for (int j = 0; j < m; j++)
		printf("%c", mas[j]);
	printf("\n");
	system("pause");
	return 0;
}

