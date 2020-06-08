#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
/*
Три отрезка. Разработать программу, меню которой позволяет пользователю выполнить следующие функции:
1. Ввести координаты начала и конца трех отрезков в двумерном пространстве.
2. Определить, можно ли из этих отрезков составить треугольник.
3. Если это возможно, то определить вид треугольника (правильный, прямоугольный, равнобедренный, произвольного вида).
4. Вычислить периметр образованного треугольника.
5. Вычислить площадь треугольника
6. Информация о версии и авторе программы.
7. Выход из программы.
*/
void Vvod(int *x, int *y)
{
	printf("Write coordinates of 3 lines(odd-numbered index - coordinates of beginning of the segment, even-numbered - ending)\n");
	for (int i = 0; i < 6; i++)
	{
		printf("\nWrite coordinates x%d:", i+1);
		if (scanf("%d",x+i) != 1 || (getchar() != '\n'))
		{
			printf("ERROR. Write x again\n");
			fflush(stdin);
			i--;
		}
	}
	for (int j = 0; j < 6; j++)
    {
     printf("\nWrite coordinates y%d:", j+1);
		if (scanf("%d",y+j) != 1 || (getchar() != '\n'))
		{
			printf("ERROR. Write y again\n");
			fflush(stdin);
			j--;
		}
    }
}

void Triangle(int* x, int* y, float* a, float* b, float* c, bool* triangle)
{
    *triangle = false;
    *a = sqrt(pow((x[1] - x[0]),2) + pow((y[1] - y[0]),2));
    *b = sqrt(pow((x[3] - x[2]),2) + pow((y[3] - y[2]),2));
    *c = sqrt(pow((x[5] - x[4]),2) + pow((y[5] - y[4]),2));
    if((*a+*b > *c) && (*a+*c > *b) && (*b+*c > *a))
    {
        printf("\nYou can make a triangle from the sides a(%.1f), b(%.1f), c(%.1f)\n", *a,*b,*c);
        *triangle = true;
    }
    else printf("\nYou can't make a triangle from the sides a(%.1f), b(%.1f), c(%.1f)\n", *a,*b,*c);
    getch();
}

void Perimeter(float a, float b, float c, bool triangle)
{
    if(triangle == false)
    {
       printf(" :D");
    }
    else printf("Perimeter: %.1f", a+b+c);
    getch();
}

void Square(float a, float b, float c, bool triangle)
{
    if(triangle == false)
    {
        printf(" XD");
    }
    else
    {
        float p = (a+b+c)/2;
        printf("Square: %f", sqrt(p*(p-a)*(p-b)*(p-c)));
    }
    getch();
}

void Type(float a, float b, float c, bool triangle)
{
    int i = 0;
    if(triangle == false)
    {
        printf(" ;)");
    }
    else
    {
      printf("Your triangle: ");
      if( (a*a) + (b*b) == c*c )
      {
         printf("Rectangular with hypotenuse c(%.1f)", c);
         i++;
      }
      if( (b*b) + (c*c) == a*a )
      {
          printf("Rectangular with hypotenuse a(%.1f)", a);
          i++;
      }
      if ( (a*a) + (c*c) == b*b )
      {
          printf("Rectangular with hypotenuse b(%.1f)", b);
          i++;
      }
      if ((a == b && a == c && b == c) && i == 0 )
      {
          printf("Regular");
          getch();
          return;
      }
      if((a == b || b == c || a == c) && i == 1 )
      {
          printf(", isosceles");
      }
      if((a == b || b == c || a == c) && i == 0 )
      {
          printf("Isosceles");
      }
    }
    getch();
}

void Delete(int* x, int* y)
{
	free(x);
	free(y);
}

void Info()
{
    printf("\nVersion alpha 1.0\nAutor: it's me, Mario\nMario Production,2020\n");
    getch();
}

void Menu()
{
    printf("Menu:\n1.Enter coordinates\n2.Can it be triangle?\n3.Type of triangle(if it's possible)\n4.Perimeter\n5.Square\n6.About programm\n7.Exit\n\n");
}

void Exit()
{
    system("cls");
    printf("Thanks for using this beautiful(horrible) programm. Goodbye!");
    getch();
}

int main()
{
	int *x, *y, choose;
	float a = 0, b = 0, c = 0;
	bool exit = false, triangle = false;
	x = (int*)calloc(6, sizeof(int));
	y = (int*)calloc(6, sizeof(int));
	while(!exit)
    {
      Menu();
	  printf("Choose the task:");
	  scanf("%d", &choose);
       switch(choose)
	   {
          case 1: Vvod(x,y); break;
	      case 2: Triangle(x,y,&a,&b,&c,&triangle); break;
	      case 3: Type(a,b,c, triangle); break;
	      case 4: Perimeter(a,b,c,triangle); break;
	      case 5: Square(a,b,c,triangle); break;
	      case 6: Info(); break;
	      case 7: Delete(x,y); exit = true; Exit(); break;
	      default: break;
	   }
	   system("cls");
    }
    return 0;
}
