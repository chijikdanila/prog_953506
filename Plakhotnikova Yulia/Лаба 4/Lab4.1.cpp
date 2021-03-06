
#include "pch.h"
#include <iostream>
#include <malloc.h>
#include <string.h>
#include <ctype.h>


	void Input(int *x)
	{
		char c;
		int a;

		while (1)
		{
			scanf_s("%d", &a);
			c = getchar();
			if (c == '\n' && a >= 0)
				break;
			rewind(stdin);
		}
		*x = a;
	}

	int strlength(char *str)
	{
		int i = 0, len = 0;

		while (str[i++])
			len++;

		return len;
	}

	

	int Palindrom(char *str)
	{
			for (int i = 0; i < strlength(str) / 2; ++i)
			{
				if (str[i] != str[strlength(str) - i - 1])
				{
					return 0;
				}
			}
			return 1;
	}

	void Clear(char clearArray[10], int *amount, int k) 
	{
		for (; k < *amount - 1; k++)
		{
			clearArray[k] = clearArray[k + 1];
		}
		amount--;
	}

	void main(void)
	{
		int n, amountOfWords;
		char arrayOfWords[10][80];

		printf("amount of matrix = ");
		Input(&n);

		for (int i = 0; i < n; i++)
		{
			puts("--------------------");
			printf("amount of words = ");
			Input(&amountOfWords);

			for (int i = 0; i < amountOfWords; i++)
			{
				gets_s(arrayOfWords[i], 80);
			}
			puts("");

			for (int i = 0; i < amountOfWords; i++)
			{
				if (Palindrom(arrayOfWords[i])) { Clear(arrayOfWords[i], &amountOfWords, i); i--; continue; }
				printf("%s\n", arrayOfWords[i]);
			}
		}
		getchar();
	}

	