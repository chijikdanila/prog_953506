#ifndef _Person_h_
#define _Person_h_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dir.h>

typedef struct person
{
	int index;
	char* FIO;
	char* contact;
	char* favModel;
	unsigned int fageCreate;
	char* fcondition;
	float fprise;
	struct person* next;
	struct person* prev;
} Person;

void premove(Person*);

struct person* pcreate()
{
	Person* a = (Person*)calloc(1, sizeof(Person));
	if (a == NULL)
	{
		printf("�� ������� �������� ������ ��� ������ ��������");
		getch();
		return NULL;
	}
	a->index = 0;
	a->next = NULL;
	a->prev = NULL;
	a->FIO = (char*)calloc(30, sizeof(char));
	a->contact = (char*)calloc(30, sizeof(char));
	a->favModel = (char*)calloc(20, sizeof(char));
	a->fageCreate = 1885;
	a->fcondition = (char*)calloc(20, sizeof(char));
	if (a->FIO == NULL || a->contact == NULL || a->favModel == NULL || a->fcondition == NULL)
	{
		printf("�� ������� �������� ������ ��� ������ ��������");
		premove(a);
		getch();
		return NULL;
	}
	a->fprise = 0;
	return a;
}

void pcr(Person* a)
{
	if (a->next == NULL)
	{
		a->next = pcreate();
		if (a->next == NULL)
			return;
		a->next->prev = a;
		a->next->index = a->index + 1;
		return;
	}
	return pcr(a->next);
}

int fpwrite(Person* a)
{
	char aa[] = "e:\\sem#2\\C\\lb7\\Person\\";
	char* aaa = a->FIO;
	FILE* fp = fopen(strncat(strncat(aa, aaa, 30), ".txt", 6), "w");
	if (fp == NULL)
	{
		printf("Error1");
		return 1;
	}
	fprintf(fp, "%s\n%s\n%s\n%u\n%s\n%f", a->FIO, a->contact, a->favModel, a->fageCreate, a->fcondition, a->fprise);

	if (fclose(fp))
	{
		printf("Error2");
		return 1;
	}
	return 0;
}

void pwchoice(Person* a)
{
	while (1)
	{
		int num = 0;
		system("cls");
		printf(" ��������\n (0 - ����� )\n   1 - ���,\n   2 - �������,\n   3 - �������������� ������,\n");
		printf("   4 - �������������� ��� �������,\n   5 - �������������� ���������,\n   6 - �������������� ����\n");
		int unsign = 0;
		float unsignn = 0;
		char chr = '\n';
		switch (num = getch())
		{
		case '0':printf(" ������� ����� �������, ����� ����������..."); return;
		case '1':printf("������� �������� ");
			if (scanf("%s", a->FIO) != 1 || (chr = getchar()) != '\n')
			{
				fflush(stdin);
				printf("�������� ��� ������");
				break;
			}
			break;
		case '2':
			printf("������� �������� ");
			if (scanf("%s", a->contact) != 1 || (chr = getchar()) != '\n')
			{
				fflush(stdin);
				printf("�������� ��� ������");
				break;
			}
			break;
		case '3':
			printf("������� �������� ");
			if (scanf("%s", a->favModel) != 1 || (chr = getchar()) != '\n')
			{
				fflush(stdin);
				printf("�������� ��� ������");
				break;
			}
			break;
		case '4':
			printf("������� �������� ");
			if (scanf("%d", &unsign) != 1 || unsign < 0 || (chr = getchar()) != '\n')
			{
				fflush(stdin);
				printf("�������� ��� ������");
				break;
			}
			a->fageCreate = unsign;
			break;
		case '5':
			printf("������� �������� ");
			if (scanf("%s", a->fcondition) != 1 || (chr = getchar()) != '\n')
			{
				fflush(stdin);
				printf("�������� ��� ������");
				break;
			}
			break;

		case '6':
			printf("������� �������� ");
			if (scanf("%f", &unsignn) != 1 || unsign < 0 || (chr = getchar()) != '\n')
			{
				fflush(stdin);
				printf("�������� ��� ������");
				break;
			}
			a->fprise = unsignn;
			break;
		}
	}
}

void pwrite(Person* a)
{
	int unsign = 0;
	float unsignn = 0;
	char chr = '\n';
	printf("������� ��� ");
	if (scanf("%s", a->FIO) != 1 || (chr = getchar()) != '\n')
	{
		fflush(stdin);
		printf("�������� ��� ������");
		return;
	}
	printf("������� �������� ");
	if (scanf("%s", a->contact) != 1 || (chr = getchar()) != '\n')
	{
		fflush(stdin);
		printf("�������� ��� ������");
		return;
	}
	printf("������� �������������� ������  ");
	if (scanf("%s", a->favModel) != 1 || (chr = getchar()) != '\n')
	{
		fflush(stdin);
		printf("�������� ��� ������");
		return;
	}
	printf("������� �������������� ��� �������� ");
	if (scanf("%f", &unsignn) != 1 || unsignn < 0 || (chr = getchar()) != '\n')
	{
		fflush(stdin);
		printf("�������� ��� ������");
		return;
	}
	a->fageCreate = unsignn;
	printf("������� �������������� ���������  ");
	if (scanf("%s", a->fcondition) != 1 || (chr = getchar()) != '\n')
	{
		fflush(stdin);
		printf("�������� ��� ������");
		return;
	}
	printf("������� �������������� ���� ");
	if (scanf("%f", &unsignn) != 1 || unsignn < 0 || (chr = getchar()) != '\n')
	{
		fflush(stdin);
		printf("�������� ��� ������");
		return;
	}
	a->fprise = unsignn;
	return;
}

void pfind(Person* a)
{
	while (1)
	{
		int num = 0;
		system("cls");
		printf(" ��������\n (0 - ����� )\n   1 - ���,\n   2 - �������,\n   3 - �������������� ������,\n");
		printf("   4 - �������������� ��� �������,\n   5 - �������������� ���������,\n   6 - �������������� ����\n");
		switch (num = getch())
		{
		case '0':printf(" ������� ����� �������, ����� ����������..."); return;
		case '1':printf("��� %s", a->FIO); getch(); break;
		case '2':printf("������� %s", a->contact); getch(); break;
		case '3':printf("�������������� ������ %s", a->favModel); getch(); break;
		case '4':printf("�������������� ��� �������� %u", a->fageCreate); getch(); break;
		case '5':printf("�������������� ��������� %s", a->fcondition); getch(); break;
		case '6':printf("�������������� ���� %f", a->fprise); getch(); break;
		}
	}
}

void pread(Person* a)
{
	printf("��� %s\n", a->FIO);
	printf("������� %s\n", a->contact);
	printf("�������������� ������ %s\n", a->favModel);
	printf("�������������� ��� �������� %u\n", a->fageCreate);
	printf("�������������� ��������� %s\n", a->fcondition);
	printf("�������������� ���� %f\n", a->fprise);
	return;
}

int fpremove(Person* a)
{
	if (a->FIO != NULL)
	{
		char aa[] = "e:\\sem#2\\C\\lb7\\Person\\";
		char delet[] = "e:\\sem#2\\C\\lb7\\deletesPerson\\";
		char* aaa = a->FIO;
		char* delett = a->FIO;

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

void premove(Person* a)
{
	if (a->index == 0)
		return;
	fpremove(a);
	free(a->FIO);
	free(a->contact);
	free(a->favModel);
	free(a->fcondition);
	if (a->prev != NULL)
		a->prev->next = a->next;
	if (a->next != NULL)
		a->next->prev = a->prev;
	Person* b = a;
	while (b != NULL)
	{
		--b->index;
		b = b->next;
	}
	free(a);
}

int fpread(Person* a)
{
	char aa[] = "e:\\sem#2\\C\\lb7\\Person\\";
	char* aaa = a->FIO;
	FILE* fp = fopen(strncat(strncat(aa, aaa, 30), ".txt", 6), "r");
	if (fp == NULL)
	{
		printf("Error");
		return 1;
	}
	if (fscanf(fp, "%s\n%s\n%s\n%u\n%s\n%f", a->FIO, a->contact, a->favModel, &a->fageCreate, a->fcondition, &a->fprise) != 6)
	{
		printf("Error");
		return 1;
	}

	if (fclose(fp))
	{
		printf("Error");
		return 1;
	}
	return 0;
}

int ffpread(Person* a, char* fole)
{
	char aa[40] = "E:\\sem#2\\C\\lb7\\Person1\\";
	FILE* fp = fopen(strncat(aa, fole, 30), "r");
	if (fp == NULL)
	{
		printf("Error1");
		return 1;
	}
	if (fscanf(fp, "%s\n%s\n%s\n%u\n%s\n%f", a->FIO, a->contact, a->favModel, &a->fageCreate, a->fcondition, &a->fprise) != 6)
	{
		printf("Error2");
		return 1;
	}
	if (fclose(fp))
	{
		printf("Error");
		return 1;
	}
	return 0;
}

void ffpwrite(Person* a)
{
	if (strncmp(a->FIO, "", 1) == 0)
		return;
	char aa[] = "e:\\sem#2\\C\\lb7\\Person1\\";
	FILE* fp = fopen(strncat(strncat(aa, a->FIO, 30), ".txt", 6), "w");
	if (fp == NULL)
	{
		printf("Error1");
		return;
	}
	fprintf(fp, "%s\n%s\n%s\n%u\n%s\n%f", a->FIO, a->contact, a->favModel, a->fageCreate, a->fcondition, a->fprise);

	if (fclose(fp))
	{
		printf("Error2");
		return;
	}
}

void pfullremove(Person* a)
{
	if (a->next != NULL)
		pfullremove(a->next);
	ffpwrite(a);
	free(a->FIO);
	free(a->contact);
	free(a->favModel);
	free(a->fcondition);
	free(a);
}
int fpcreate(Person* a)
{
	if (a->FIO != NULL)
	{
		char aa[] = "e:\\sem#2\\C\\lb7\\Person \\";
		char* aaa = a->FIO;
		FILE* fp = fopen(strncat(strncat(aa, aaa, 30), ".txt", 6), "w");
		if (fp == NULL)
		{
			printf("Error");
			return 1;
		}
		if (fclose(fp))
		{
			printf("Error");
			return 1;
		}
	}
	return 0;
}

void precover(Person* a)
{
	Person* persona = a;
	struct ffblk f; //������ ��������� ��������� ffblk
	int done;
	int number = -1;

	done = findfirst("E:\\sem#2\\C\\lb7\\deletesPerson\\*.txt", &f, 0);
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
	done = findfirst("E:\\sem#2\\C\\lb7\\deletesPerson\\*.txt", &f, 0);
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
		if (persona->next == NULL)
		{
			pcr(persona);
			persona = persona->next;
		}
		if (strncmp(persona->FIO, "\0", 1) == 0)
		{
			char aa[] = "e:\\sem#2\\C\\lb7\\deletesPerson\\";
			FILE* fp = fopen(strncat(aa, f.ff_name, 30), "r");
			if (fp == NULL)
			{
				printf("Error1");
				return;
			}

			if (fscanf(fp, "%s\n%s\n%s\n%u\n%s\n%f", persona->FIO, persona->contact, persona->favModel, &persona->fageCreate, persona->fcondition, &persona->fprise) != 6)
			{
				printf("Error2");
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
