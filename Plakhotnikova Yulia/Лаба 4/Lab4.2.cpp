#include "pch.h"
#include <iostream>

int main() {

	int wordCounter = 1;
	int i, sum = 0;
	char str[1024];
	printf("Enter text (less than 1024 chars) : ");
	gets_s(str);
	for (i = 0; str[i] != '\0'; i++)
	{
		if ('0' <= str[i] && str[i] <= '9')
		{
			sum += (str[i] - 48);
		}
	}

	for (int i = 1; i < strlen(str); i++) {
		if (str[i - 1] == ' ' && str[i] != ' ')
			wordCounter++;
	}

	printf("\nSum of words : %d\n", wordCounter);
	printf("\nSum of numbers: %d\n", sum);

	if (sum > wordCounter) printf("Sum of numbers more than sum of words");
	if (sum < wordCounter) printf("Sum of numbers less than sum of words");
	if (sum == wordCounter) printf("Sum of numbers equal to the sum of words");

	getchar();
	return 0;
}

