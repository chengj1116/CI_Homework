#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct sign
{
	char name[15];
	char addr[20];
	char tel[15];
	struct sign* next;
}pe;
struct sign*p1, *p2, *head;
FILE *fp;
void menu()
{
	system("color OD");
	printf("\n\n");
	printf("������������ͨѶ¼Ŀ¼����������������\n");
	printf("|         1.�����ϵ��              |\n");
	printf("|         2.��ѯ��ϵ��              |\n");
	printf("|         3.ɾ����ϵ��              |\n");
	printf("|         4.��ʾ��ϵ��              |\n");
	printf("|         5.�޸���ϵ��              |\n");
	printf("\n\n");
}
void add()
{
	char ch;
	if ((fp == fopen("data.txt", "a+")) != 1)
	{
		printf("�ļ���ʧ��");
		exit(1);
	}
	while (1)
	{
		system("cls");
		printf("�����������Ϣ��\n");
		p2 = (struct sign*)malloc(sizeof(struct sign));
		p2->next = NULL;
		printf("������");
		scanf("%s", pe.name);
		printf("��ַ��");
		scanf("%s", pe.addr);
		printf("�绰���룺");
		scanf("%s", pe.tel);
		strcpy(p1->name, pe.name);
		strcpy(p1->addr, pe.addr);
		strcpy(p1->tel, pe.tel);
		p1->next = p2;
		p1 = p2;
		if (fwrite(&pe, sizeof(struct sign), 1, fp) != 1)
			printf("д�����");
		printf("����Y��y����Ŀ¼\n");
		getchar();
		ch = getchar();
		if (ch == 'Y' || ch == 'y')
			break;
	}
	fclose(fp);
}
void search()
{
	system("cls");
	p1 = head;
	char findname[8];
	int i = 0;
	printf("\n������Ҫ��ѯ��������");
	scanf("%s", &findname);
	while (p1->next != NULL)
	{
		if (strcmp(p1->name, findname) == 0)
		{
			printf("%10.8s %10.6s %12.10s\n","����", "��ַ", "�绰����");
			printf("%10.8s %10.6s %12.10s\n", p1->name, p1->addr, p1->tel);
			i++;
		}
		p1 = p1->next;
	}
	printf("�� %d ��\n", i);
	system("pause");
}
void del()
{
	char deletname[8];
	system("cls");
	int i, y = 0;
	p1 = p2 = head;
	printf("����������Ҫɾ������ϵ��������");
	scanf("%s", &deletname);
	getchar();
	while (p1 != NULL)
	{
		if (strcmp(p1->name, deletname) == 0)
		{
			printf("%10.8s %10.6s %12.10s %15.4s\n","����", "��ַ", "�绰����");
			printf("%10.8s %10.6s %12.10s %15.14s\n", p1->name, p1->addr, p1->tel);
			y = 1;
			printf("\n��Ҫɾ�����������1--�ǣ�2--��\n");
			scanf("%d", &i);
			if (i == 1)
			{
				if (p1 == head)
				{
					head = p1->next;
					free(p1);
				}
				else
				{
					p2->next = p1->next;
					free(p1);
					if ((fp == fopen("data.txt", "w+")) != 1)
					{
						printf("���ļ�ʧ��");
						exit(1);
					}
					p1 = head;
					while (p1->next != NULL)
					{
						if (fwrite(p1, sizeof(struct sign), 1, fp) != 1)
							printf("д�����");
						p1 = p1->next;
					}
				}
				fclose(fp);
			}
			printf("OK!\n");
		}
		else if (strcmp(p1->name, deletname) && (p1->next) == NULL)
		{
			i = 0;
		}
		p2 = p1;
		p1 = p1->next;
	}
	if (y == 0)
	{
		printf("�Բ���û�д���ϵ��");
	}
	system("pause");
}
void display()
{
	printf("%10.8s %10.6s %12.10s\n", "����", "��ַ", "�绰����");
	p1 = head;
	while (p1->next != NULL)
	{
		printf("%10.8s %10.6s %12.10s\n", p1->name, p1->addr, p1->tel);
		p1 = p1->next;
	}
}
void goodbye()
{
	printf("\n\n");
	printf("������������ͨѶ¼Ŀ¼����������������\n");
	printf("|                                     |\n");
	printf("|          goodbye!                   |\n");
	printf("|                                     |\n");
	printf("|                                     |\n");
	printf("|                                     |\n");
	printf("\n\n");
}
void error()
{
	printf("\n\n");
	printf("������������ͨѶ¼Ŀ¼����������������\n");
	printf("|                                     |\n");
	printf("|             �������              |\n");
	printf("|                                     |\n");
	printf("|                                     |\n");
	printf("|                                     |\n");
	printf("\n\n");
	system("pause");
}
int main()
{
	int n;
	if ((fp = fopen("data.txt", "a")) == NULL)
	{
		printf("�ļ��򿪴���");
		exit(1);
	}
	fclose(fp);
	if ((fp = fopen("data.txt", "r")) == NULL)
	{
		printf("�ļ��򿪴���");
		exit(1);
	}
	p1 = (struct sign*)malloc(sizeof(struct sign));
	p1->next = NULL;
	head = p1;
	while (!feof(fp))
	{
		if (fread(p1, sizeof(struct sign), 1, fp) != 1)
			break;
		p2 = (struct sign*)malloc(sizeof(struct sign));
		p2->next = NULL;
		p1->next = p2;
		p1 = p2;
	}
	fclose(fp);
	while (1)
	{
		menu();
		printf("ѡ������Ҫ�Ĺ��ܣ�");
		printf("    ");
		scanf("%d", &n);
		if (n == 0)
		{
			system("cls");
			goodbye();
			exit(0);
		}
		else if (n == 1)
		{
			system("color OE");
			system("cls");
			add();
		}
		else if (n == 2)
		{
			system("color OC");
			system("cls");
			search();
		}
		else if (n == 3)
		{
			system("color OA");
			del();
		}
		else if (n == 4)
		{
			system("color OB");
			system("cls");
			display();
			system("pause");
		}
		else
			error();
		system("cls");
		getchar();
	}
}
