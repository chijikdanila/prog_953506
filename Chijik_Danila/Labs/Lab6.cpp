#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif
/*
Пользователь вводит с клавиатуры целые числа (ввод прекращается, когда будет введен '0').
Построить бинарное дерево поиска, повторяющиеся значения в дерево не добавлять.
Разработать функцию, возвращаюшую сумму значений узлов самой длинной ветви дерева.
*/
typedef struct node
{
  int numb;
  struct node *lev;
  struct node *prav;
  struct node *parent;
  int size;
} Node;

void siz_e(Node* par)
{
  if(par!=NULL)
  {
      par->size++;
      return siz_e(par->parent);
  }
  return;
}

Node* createN(Node* par)
{
   Node* tmp=(Node*)malloc(sizeof(Node));
   if(tmp==NULL)
   {
	   printf("Îøèáêà ïðè ñîçäàíèè óçëà");
	   exit(0);
   }
   tmp->prav=NULL;
   tmp->lev=NULL;
   tmp->parent=par;
   if(par!=NULL&&(par->lev==NULL&&par->prav==NULL))
   siz_e(par);
   tmp->numb=0;
   tmp->size=1;
   return tmp;
}

Node* sravn(Node* parent, int niw)
{
	if(niw>parent->numb)
	{
	if(parent->prav==NULL)
	parent->prav=createN(parent);
	return parent->prav;
	}
	else if(niw<parent->numb)
	{
	if(parent->lev==NULL)
	parent->lev=createN(parent);
	return parent->lev;
	}
	return NULL;
}

int vvod(Node* tmp)
{
  int a;
  char aa;
  if(scanf("%d",&a)!=1||((aa=getchar())!='\n'))
  {
	  printf("Îøèáêà ïðè ââîäå ýëåìåíòà, ïðîãðàììà çàâåðøåíà");
	  return 0;
  }
  if(a==0)
  return 0;

  while(tmp->numb!=0)
  {
  if(tmp->numb==a)
  return 1;
  tmp=sravn(tmp,a);
  }
  tmp->numb=a;
  return 1;
}

void deleteN(Node** tmp,Node** clean)
{
	if((*tmp)->lev!=NULL)
	{
	return deleteN(&((*tmp)->lev),clean);
	}
	if((*tmp)->prav!=NULL)
	{
	return deleteN(&((*tmp)->prav),clean);
	}
	(*clean)->parent=(*tmp)->parent;
	free((*tmp));
	(*tmp)=NULL;
	if((*clean)->parent==NULL)
	return;
	return deleteN(&((*clean)->parent),clean);
}

int vybor()
{
int a;
char aa;
lp:printf("Åñòü íåñêîëüêî âåòâåé îäèíàêîâîé äëèíû. Ïî êàêîé Âû õîòèòå ïîéòè?\n 1 - ïî ëåâîé\n -1 - ïî ïðàâîé\n ");
fflush (stdin);
	 if(scanf("%d",&a)!=1||((aa=getchar())!='\n')||(a!=1&&a!=-1))
  {
	  fflush (stdin);
	  printf("Îøèáêà ïðè âûáîðå ïóòè\n");
	  goto lp;
  }
  return a;
}

int sum(Node* par)
{
   if(par==NULL)
   {
       return 0;
   }
   int a=par->numb;
   int b=0;
   int c=0;

   if(par->size==0)
   {
       return a;
   }
   if(par->lev==NULL)
   {
       b=0;
   }
   else b=par->lev->size;
   if (par->prav==NULL)
   {
       c=0;
   }
   else c=par->prav->size;
   int vyb=0;
   if(b==c&&b!=0&&c!=0)
   {
       vyb=vybor();
       b+=vyb;
   }
   if(b>c)
   {
       return a+sum(par->lev);
   }
	else return a+sum(par->prav);
}

void main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
	 Node* a;
	 Node* clean;
	 int i=1;
	 a=createN(NULL);
	 clean=createN(NULL);
	 printf("Ââîäèòå ÷èñëà äëÿ ñîçäàíèÿ áèíàðíîãî äåðåâà ïîèñêà\n");
	 while(i==1)
	 {
	 i=vvod(a);
	 }
	 printf("\nÑóììà ñàìîé äëèííîé âåòâè ðàâíà %d",sum(a));
	 deleteN(&a,&clean);
	 free(clean);
	 getch();
}
