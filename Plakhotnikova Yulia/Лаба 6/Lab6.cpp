#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

// описание элемента дерева поиска 
typedef struct NODE
{
	char key;
	long count;
	struct NODE *left, *right;
} NODE;

// вставка элемента со значением x в дерево поиска
void Insert(NODE **q, char x)
{
	if (*q == NULL)
	{
		*q = (NODE *)malloc(sizeof(NODE));
		(*q)->key = x;
		(*q)->count = 1;
		(*q)->left = (*q)->right = NULL;
	}
	else
	{
		if ((*q)->key == x)
			((*q)->count)++;
		else
			if ((*q)->key > x)
				Insert(&((*q)->left), x);
			else Insert(&((*q)->right), x);
	}
}

// вывод элементов дерева поиска на экран в порядке возрастания и количеством повторений
void Display(NODE *q)
{
	if (q != NULL)
	{
		Display(q->left);
		printf("%c : %d\n", q->key, q->count);
		Display(q->right);
	}
}

// количество вершин
long Count(NODE *q)
{
	return q == NULL ? 0 : 1 + Count(q->left) + Count(q->right);
}

// удаление дерева
void Freemem(NODE *q) {
	if (q != NULL) {
		Freemem(q->left);
		Freemem(q->right);
		free(q);
	}
}

// количество листьев дерева
int list_count(NODE *q)
{
	int result;
	if (q == NULL)
	{
		result = 0;
	}

	else if ((q->left == NULL) && (q->right == NULL))
	{
		result = 1;
	}

	else
	{
		result = list_count(q->left) + list_count(q->right);
	}

	return result;

}

int main()
{
	NODE *root = NULL, *q;
	char s[80], *ps;
	printf("Enter the string: ");
	gets_s(s, 80);
	for (ps = s; *ps; ++ps)
		Insert(&root, *ps);
	Display(root);
	int result = list_count(root);
	printf("\nNumber of leaves: %d\n", result);
	Freemem(root);
	
	getchar();
	return 0;
}