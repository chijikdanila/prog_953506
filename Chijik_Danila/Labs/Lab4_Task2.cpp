#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <stdlib.h>
#include <string.h>
/*
В файле дан исходный текст программы на языке С.
Уровнем комментированности текста будем считать отношение объема комментариев к объему всего текста (в байтах).
Определить уровень комментированности данного текста.
*/
int main()
{
    char str[500];
    FILE* fp = fopen("code.txt", "r");
    bool flag = true;
    int value = 0, valuecom = 0;

    if (fp != NULL)
    {
        exit(1);
        while (fgets(str, 300, fp))
        {
            int com = 0;
            for (int i = 0; i < strlen(str); i++)
            {
                if (flag)
                    if (str[i] == '/')
                    {
                        if (str[i + 1] == '/')
                        {
                            valuecom += strlen(str) - i + 1;
                            value += strlen(str);
                            break;
                        }
                        else if (str[i + 1] == '*')
                        {
                            flag ^= 1;
                            com = i;
                        }
                    }
                    else
                    {
                        if (str[i] == '*' && str[i + 1] == '/')
                        {
                            flag ^= 1;
                            valuecom += i + 2 - com;
                        }
                    }
            }
            if (!flag)
                valuecom += strlen(str) - com + 1;
            value += strlen(str);
        }
        fclose(fp);
    }

    if (value > 0)
    {
        float a = (float)valuecom * 100 / value;
        printf("%f%%", a);
    }
    else
    {
        printf("0%%");
    }
}
