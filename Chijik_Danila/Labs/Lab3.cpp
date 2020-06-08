#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/*
Динамический двумерный массив a(n, n -1) заполнить случайными числами.
После строки, содержащей максимальный элемент массива, вставить строку из нулей.
Зеркально отобразить элементы массива относительно главной диагонали, а затем относительно побочной диагонали.
Вывести на экран исходный и результирующий массивы.
*/
int main()
{
    int n, i = 0, j = 0, x, r = 0, q = 0, max;
    puts("Input number:");
    scanf_s("%d", &n);
    int** a = (int**)calloc(n , sizeof(int*));
    puts("\nSource array:");
    for (i = 0; i < n - 1 ; i++)
    {
        a[i] = (int*)calloc(n , sizeof(int));
        for (j = 0; j < n ; j++)
        {
            a[i][j] = rand() % 50 - 10;
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }
    a[n - 1] = (int*)calloc(n, sizeof(int));
    max = a[0][0];
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
                r = i;
                q = j;
            }
        }
    }
    printf("\nMax element is a[%d][%d] = %d\n", (r + 1), (q + 1), max);
    a[n - 1] = (int*)calloc(n , sizeof(int));
    int* bbb = a[n - 1];
    for (i = n - 1; i > r + 1; i--)
    {
        a[i] = a[i - 1];
    }
    a[r + 1] = bbb;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }
    puts("Mirror image symmetry about a horizontal axis:");
    for (i = 0, x = 1; i < n; i++, x++) 
    {
        for (j = 0; j < n; j++)
            printf("%6d", a[n - x][j]);
        printf("\n");
    }
    puts("Mirror image symmetry about a vertical axis:");
    for (i = 0; i < n; i++, x++) 
    {
        for (j = 0, x = 1; j < n; j++, x++)
            printf("%6d", a[i][n - x]);
        printf("\n");
    }

    for (i = 0; i < n ; i++)
    {
        free(a[i]);
    }
    free(a);
    return 0;
}