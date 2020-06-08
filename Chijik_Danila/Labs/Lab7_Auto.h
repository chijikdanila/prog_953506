#ifndef _Avto_h_
#define _Avto_h_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <dir.h>

typedef struct avto
{
	int index;
	char* model;
	unsigned int ageCreate;
	unsigned int mileAge;
	float engineSize;
	unsigned int power;
	char* transmission;
	char* gearBox;
	char* condision;
	float price;
	struct avto* next;
	struct avto* prev;
} Avto;

void aremove(Avto*);

struct avto* acreate()
{
	Avto* a = (Avto*)calloc(1, sizeof(Avto));
	if (a == NULL)
	{
		printf("�� ������� �������� ������ ��� ������ ��������");
		getch();
		return NULL;
	}
	a->index = 0;
	a->next = NULL;
	a->prev = NULL;
	a->model = (char*)calloc(20, sizeof(char));
	a->ageCreate = 1885;
	a->mileAge = 0;
	a->engineSize = 0;
	a->power = 0;
	a->transmission = (char*)calloc(20, sizeof(char));
	a->gearBox = (char*)calloc(20, sizeof(char));
	a->condision = (char*)calloc(20, sizeof(char));
	if (a->model == NULL || a->transmission == NULL || a->gearBox == NULL || a->condision == NULL)
	{
		printf("�� ������� �������� ������ ��� ������ ��������");
		aremove(a);
		getch();
		return NULL;
	}
	a->price = 0;
	return a;
}

void acr(Avto* a)
{
	if (a->next == NULL)
	{
		a->next = acreate();
		if (a->next == NULL)
			return;
		a->next->prev = a;
		a->next->index = a->index + 1;
		return;
	}
	return acr(a->next);
}

int fawrite(Avto* a)
{
	char aa[] = "e:\\sem#2\\C\\lb7\\Avto\\";
	char* aaa = a->model;
	FILE* fp = fopen(strncat(strncat(aa, aaa, 10), ".txt", 6), "w");
	if (fp == NULL)
	{
		printf("������ �������� ����� ��� �������� ��� ������");
		return 1;
	}
	fprintf(fp, "%s\n%u\n%u\n%f\n%u\n%s\n%s\n%s\n%f\n", a->model, a->ageCreate, a->mileAge, a->engineSize, a->power, a->transmission, a->gearBox, a->condision, a->price);

	if (fclose(fp))
	{
		printf("Error2");
		return 1;
	}
	printf("���� ������. ������� ����� �������, ����� ����������... ");
	return 0;
}

void awchoice(Avto* a)
{
	while (1)
	{
		int num = 0;
		system("cls");
		printf(" ��������\n (0 - ����� )\n   1 - ������,\n   2 - ��� ������������,\n   3 - ������,��.,\n   4 - ����� ���������,�.,\n");
		printf("   5 - ��������(�.�.),\n   6 - ��� �������,\n   7 - ��� ������� �������,\n   8 - ���������,\n   9 - ����,\n");
		int unsign = 0;
		float unsignn = 0;
		char chr = '\n';
		switch (num = getch())
		{
		case '0':printf(" ������� ����� �������, ����� ����������..."); return;
		case '1':printf("������� �������� ");
			if (scanf("%s", a->model) != 1 || (chr = getchar()) != '\n')
			{
				fflush(stdin);
				printf("�������� ��� ������");
				break;
			}
			break;
		case '2':
			printf("������� �������� ");
			if (scanf("%d", &unsign) != 1 || unsign < 0 || (chr = getchar()) != '\n')
			{
				fflush(stdin);
				printf("�������� ��� ������");
				break;
			}
			a->ageCreate = unsign;
			break;
		case '3':
			printf("������� �������� ");
			if (scanf("%d", &unsign) != 1 || unsign < 0 || (chr = getchar()) != '\n')
			{
				fflush(stdin);
				printf("�������� ��� ������");
				break;
			}
			a->mileAge = unsign;
			break;
		case '4':
			printf("������� �������� ");
			if (scanf("%f", &unsignn) != 1 || unsignn < 0 || (chr = getchar()) != '\n')
			{
				fflush(stdin);
				printf("�������� ��� ������");
				break;
			}
			a->engineSize = unsignn;
			break;
		case '5':
			printf("������� �������� ");
			if (scanf("%d", &unsign) != 1 || unsign < 0 || (chr = getchar()) != '\n')
			{
				fflush(stdin);
				printf("�������� ��� ������");
				break;
			}
			a->power = unsign;
			break;
		case '6':
			printf("������� �������� ");
			if (scanf("%s", a->transmission) != 1 || (chr = getchar()) != '\n')
			{
				fflush(stdin);
				printf("�������� ��� ������");
				break;
			}
			break;
		case '7':
			printf("������� �������� ");
			if (scanf("%s", a->gearBox) != 1 || (chr = getchar()) != '\n')
			{
				fflush(stdin);
				printf("�������� ��� ������");
				break;
			}
			break;
		case '8':
			printf("������� �������� ");
			if (scanf("%s", a->condision) != 1 || (chr = getchar()) != '\n')
			{
				fflush(stdin);
				printf("�������� ��� ������");
				break;
			}
			break;
		case '9':
			printf("������� �������� ");
			if (scanf("%f", &unsignn) != 1 || unsignn < 0 || (chr = getchar()) != '\n')
			{
				fflush(stdin);
				printf("�������� ��� ������");
				break;
			}
			a->price = unsignn;
			break;
		}
	}
}

void awrite(Avto* a)
{
	int unsign = 0;
	float unsignn = 0;
	char chr = '\n';
	printf("������� ������ ");
	if (scanf("%s", a->model) != 1 || (chr = getchar()) != '\n')
	{
		fflush(stdin);
		printf("�������� ��� ������");
		return;
	}
	printf("������� ������� ������ ");
	if (scanf("%d", &unsign) != 1 || unsign < 0 || (chr = getchar()) != '\n')
	{
		fflush(stdin);
		printf("�������� ��� ������");
		return;
	}
	a->ageCreate = unsign;
	printf("������� ������ ");
	if (scanf("%d", &unsign) != 1 || unsign < 0 || (chr = getchar()) != '\n')
	{
		fflush(stdin);
		printf("�������� ��� ������");
		return;
	}
	a->mileAge = unsign;
	printf("������� ����� ��������� ");
	if (scanf("%f", &unsignn) != 1 || unsignn < 0 || (chr = getchar()) != '\n')
	{
		fflush(stdin);
		printf("�������� ��� ������");
		return;
	}
	a->engineSize = unsignn;
	printf("������� �������� ��������� ");
	if (scanf("%d", &unsign) != 1 || unsign < 0 || (chr = getchar()) != '\n')
	{
		fflush(stdin);
		printf("�������� ��� ������");
		return;
	}
	a->power = unsign;
	printf("������� ��� ������� ");
	if (scanf("%s", a->transmission) != 1 || (chr = getchar()) != '\n')
	{
		fflush(stdin);
		printf("�������� ��� ������");
		return;
	}
	printf("������� ��� ������� ������� ");
	if (scanf("%s", a->gearBox) != 1 || (chr = getchar()) != '\n')
	{
		fflush(stdin);
		printf("�������� ��� ������");
		return;
	}
	printf("������� �������� ���������� ");
	if (scanf("%s", a->condision) != 1 || (chr = getchar()) != '\n')
	{
		fflush(stdin);
		printf("�������� ��� ������");
		return;
	}
	printf("������� ���� ");
	if (scanf("%f", &unsignn) != 1 || unsignn < 0 || (chr = getchar()) != '\n')
	{
		fflush(stdin);
		printf("�������� ��� ������");
		return;
	}
	a->price = unsignn;
	return;
}

void afind(Avto* a)
{
	while (1)
	{
		int num = 0;
		system("cls");
		printf(" ��������\n (0 - ����� )\n   1 - ������,\n   2 - ��� ������������,\n   3 - ������,��.,\n   4 - ����� ���������,�.,\n");
		printf("   5 - ��������(�.�.),\n   6 - ��� �������,\n   7 - ��� ������� �������,\n   8 - ���������,\n   9 - ����,\n");
		switch (num = getch())
		{
		case '0':printf(" ������� ����� �������, ����� ����������..."); return;
		case '1':printf("������ %s", a->model); getch(); break;
		case '2':printf("������� ����� %u", a->ageCreate); getch(); break;
		case '3':printf("������ ����� %u", a->mileAge); getch(); break;
		case '4':printf("����� ��������� ����� %f", a->engineSize); getch(); break;
		case '5':printf("�������� �����%u", a->power); getch(); break;
		case '6':printf("��� ������ %s", a->transmission); getch(); break;
		case '7':printf("��� ������� ������� %s", a->gearBox); getch(); break;
		case '8':printf("��������� %s", a->condision); getch(); break;
		case '9':printf("���� %f", a->price); getch(); break;
		}
	}
}

void aread(Avto* a)
{
	printf("������ %s\n", a->model);
	printf("������� ������ %d\n", a->ageCreate);
	printf("������ %d\n", a->mileAge);
	printf("����� ��������� %f\n", a->engineSize);
	printf("�������� ��������� %d\n", a->power);
	printf("��� ������� %s\n", a->transmission);
	printf("��� ������� ������� %s\n", a->gearBox);
	printf("�������� ���������� %s\n", a->condision);
	printf("���� %f\n", a->price);
	return;
}

int faremove(Avto* a)
{
	if (a->model != NULL)
	{
		char aa[] = "e:\\sem#2\\C\\lb7\\Avto\\";
		char delet[] = "e:\\sem#2\\C\\lb7\\deletesAvto\\";
		char* aaa = a->model;
		char* delett = a->model;

		if (remove(strncat(strncat(aa, aaa, 10), ".txt", 6)))
		{
			printf("���������� ����� �� ����������");
			return 1;
		}

		FILE* fp = fopen(strncat(strncat(delet, delett, 10), ".txt", 6), "w");
		if (fp == NULL)
		{
			printf("������ �������� ����� ��� �������� ��� ������");
			return 1;
		}
		if (fclose(fp))
		{
			printf("������ �������� �����");
			return 1;
		}
	}
	return 0;
}

void aremove(Avto* a)
{
	if (a->index == 0)
		return;
	faremove(a);
	free(a->model);
	free(a->transmission);
	free(a->condision);
	free(a->gearBox);
	if (a->prev != NULL)
		a->prev->next = a->next;
	if (a->next != NULL)
		a->next->prev = a->prev;
	Avto* b = a;
	while (b != NULL)
	{
		--b->index;
		b = b->next;
	}
	free(a);
}

int facreate(Avto* a)
{
	if (a->model != NULL)
	{
		char aa[] = "e:\\sem#2\\C\\lb7\\Avto\\";
		char* aaa = a->model;
		FILE* fp = fopen(strncat(strncat(aa, aaa, 10), ".txt", 6), "w");
		if (fp == NULL)
		{
			printf("������ �������� ����� ��� �������� ��� ������");
			return 1;
		}
		if (fclose(fp))
		{
			printf("������ �������� �����");
			return 1;
		}
	}
	return 0;
}

int ffaread(Avto* a, char* fone)
{
	char aa[] = "e:\\sem#2\\C\\lb7\\Avto1\\";
	FILE* fp = fopen(strncat(aa, fone, 10), "r");
	if (fp == NULL)
	{
		printf("��� ����� �������, ��� ������ ����� �� ����������");
		return 1;
	}
	if (fscanf(fp, "%s\n%u\n%u\n%f\n%u\n%s\n%s\n%s\n%f\n", a->model, &a->ageCreate, &a->mileAge, &a->engineSize, &a->power, a->transmission, a->gearBox, a->condision, &a->price) != 9)
	{
		printf("� ����� ��������� ������ ��� �� ��� �������");
		return 1;
	}
	if (fclose(fp))
	{
		printf("������ �������� �����");
		return 1;
	}
	return 0;
}

int faread(Avto* a)
{
	char aa[] = "e:\\sem#2\\C\\lb7\\Avto1\\";
	char* aaa = a->model;
	FILE* fp = fopen(strncat(strncat(aa, aaa, 10), ".txt", 6), "r");
	if (fp == NULL)
	{
		printf("��� ����� �������, ��� ������ ����� �� ����������");
		return 1;
	}
	if (fscanf(fp, "%s\n%u\n%u\n%f\n%u\n%s\n%s\n%s\n%f\n", a->model, &a->ageCreate, &a->mileAge, &a->engineSize, &a->power, a->transmission, a->gearBox, a->condision, &a->price) != 9)
	{
		printf("� ����� ��������� ������ ��� �� ��� �������");
		return 1;
	}
	if (fclose(fp))
	{
		printf("������ �������� �����");
		return 1;
	}
	return 0;
}


void ffawrite(Avto* a)
{
	if (strncmp(a->model, "", 1) == 0)
		return;
	char aa[] = "e:\\sem#2\\C\\lb7\\Avto1\\";
	FILE* fp = fopen(strncat(strncat(aa, a->model, 10), ".txt", 6), "w");
	if (fp == NULL)
	{
		printf("������ �������� ����� ��� �������� ��� ������");
		return;
	}
	fprintf(fp, "%s\n%u\n%u\n%f\n%u\n%s\n%s\n%s\n%f\n", a->model, a->ageCreate, a->mileAge, a->engineSize, a->power, a->transmission, a->gearBox, a->condision, a->price);

	if (fclose(fp))
	{
		printf("Error2");
		return;
	}
}
void afullremove(Avto* a)
{
	if (a->next != NULL)
		afullremove(a->next);
	ffawrite(a);
	free(a->model);
	free(a->transmission);
	free(a->condision);
	free(a->gearBox);
	free(a);
}

void obmen(Avto* a, Avto* b)
{
	Avto c = *a;
	a->model = b->model;
	a->ageCreate = b->ageCreate;
	a->mileAge = b->mileAge;
	a->engineSize = b->engineSize;
	a->power = b->power;
	a->transmission = b->transmission;
	a->gearBox = b->gearBox;
	a->condision = b->condision;
	a->price = b->price;
	b->model = c.model;
	b->ageCreate = c.ageCreate;
	b->mileAge = c.mileAge;
	b->engineSize = c.engineSize;
	b->power = c.power;
	b->transmission = c.transmission;
	b->gearBox = c.gearBox;
	b->condision = c.condision;
	b->price = c.price;
}

void sortVybor(Avto* a, int* zn, int* num, char* symbol)
{
	Avto* nw = a;
	int gr = 0;
	while (gr < *zn)
	{
		nw = nw->next;
		++gr;
	}
	Avto* mr = nw;
	Avto* nexx;
	Avto* pree;
	for (int i = 0; i < ((*num) - (*zn)); ++i)
	{
		mr = mr->next;
		if (*symbol == '0')
			if (nw->price > mr->price)
			{
				obmen(nw, mr);
			}
		if (*symbol == '1')
			if (nw->ageCreate > mr->ageCreate)
			{
				obmen(nw, mr);
			}
	}
}

void raschet(Avto* a, int* b)
{
	if (a->next != NULL)
	{
		++* b;
		raschet(a->next, b);
	}
}

void sort(Avto* a, char* symbol)
{
	int num = 0;
	raschet(a, &num);
	for (int i = 0; i < num; ++i)
	{
		sortVybor(a, &i, &num, symbol);
	}
}


void arecover(Avto* a)
{
	Avto* ayto = a;
	struct ffblk f; //������ ��������� ��������� ffblk
	int done;
	int number = -1;

	done = findfirst("E:\\sem#2\\C\\lb7\\deletesAvto\\*.txt", &f, 0);
	if (done) { printf("��������� ����� �����������\n"); return; }
	if (!done)
	{
		printf("%d - %s\n", ++number, f.ff_name);
		done = findnext(&f);
	}
	printf("������� ����� ������� �����\n");
	if (scanf(" %d", &number) != 1 || getchar() != '\n' || number < 0)
	{
		fflush(stdin);
		printf("�������� ��� ������\n");
		return;
	}
	done = findfirst("E:\\sem#2\\C\\lb7\\deletesAvto\\*.txt", &f, 0);
	for (int i = 0; i < number; ++i)
	{
		done = findnext(&f);
		if (done == -1)
		{
			printf("�� ����� �������������� �����\n");
			return;
		}
	}
	for (;;)
	{
		if (ayto->next == NULL)
		{
			acr(ayto);
			ayto = ayto->next;
		}
		if (strncmp(ayto->model, "\0", 1) == 0)
		{
			char aa[] = "e:\\sem#2\\C\\lb7\\deletesAvto\\";
			FILE* fp = fopen(strncat(aa, f.ff_name, 30), "r");
			if (fp == NULL)
			{
				printf("Error1");
				return;
			}

			if (fscanf(fp, "%s\n%u\n%u\n%f\n%u\n%s\n%s\n%s\n%f\n", ayto->model, &ayto->ageCreate, &ayto->mileAge, &ayto->engineSize, &ayto->power, ayto->transmission, ayto->gearBox, ayto->condision, &ayto->price) != 9)
			{
				printf("� ����� ��������� ������ ��� �� ��� �������");
				return;
			}

			if (fclose(fp))
			{
				printf("Error2");
				return;
			}

			remove(aa);
			return;
		}
	}
}

#endif
