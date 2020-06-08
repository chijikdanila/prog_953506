#include <stdio.h>
#include <math.h>
/*
sin(x) = x - x^3/3! - ... + (-1)^n-1*(x^(2n-1)/(2n-1)! + ...
Численно убедиться в справедливости равенства,
для чего для заданного значения х вычислить его левую часть и разложение, стоящее в правой части.
При каком n исследуемое выражение отличается от sin x менее, чем на заданную погрешность ε?
Испытать разложение на сходимость при разных значениях х.
*/

int iter(double x, double e, double rez)
{
    double a = 0, g;
    int n = 1;
    for ( ; ; n++){
        g = pow(-1, (n-1)) * pow(x , (2 * n - 1));
        for(int i = 1; i <= (2 * n - 1); i++)
        {
            g /= i;
        }
        a += g;
        printf("\nIteration: %lf", a);
        if(a - e <= rez && rez <= a + e){
            break;
        }
    }
    return n;
}

double rec(double x, double e, double rez, double sum, int n)
{
    double g = pow(-1, (n-1)) * pow(x , (2 * n - 1));
    for(int i = 1; i <= (2 * n - 1); i++)
    {
            g /= i;
    }
    sum += g;
    printf("\nRekursion: %lf", sum);
    if(sum - e <= rez && rez <= sum + e){
        return n;
    }
    return rec(x, e, rez, sum, n + 1);
}

int main()
{
    double e, rez, x, sum = 0;
    int n = 1, rez2;
    printf ("Write x:\n");
    scanf ("%lf", &x);
    printf ("Write e:\n");
    scanf ("%lf", &e);

    rez = sin(x);
    rez2 = iter(x, e, rez);
    printf("\nNecessary n with iteration: %d",rez2);
    rez2 = rec(x, e, rez, sum, n);
    printf("\nNecessary n with recursion: %d",rez2);
    printf("\nRezult(sin): %lf",rez);
    return 0;
}
