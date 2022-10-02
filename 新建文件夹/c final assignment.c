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
	printf("——————通讯录目录————————\n");
	printf("|         1.添加联系人              |\n");
	printf("|         2.查询联系人              |\n");
	printf("|         3.删除联系人              |\n");
	printf("|         4.显示联系人              |\n");
	printf("|         5.修改联系人              |\n");
	printf("\n\n");
}
void add()
{
	char ch;
	if ((fp == fopen("data.txt", "a+")) != 1)
	{
		printf("文件打开失败");
		exit(1);
	}
	while (1)
	{
		system("cls");
		printf("请输入个人信息：\n");
		p2 = (struct sign*)malloc(sizeof(struct sign));
		p2->next = NULL;
		printf("姓名：");
		scanf("%s", pe.name);
		printf("地址：");
		scanf("%s", pe.addr);
		printf("电话号码：");
		scanf("%s", pe.tel);
		strcpy(p1->name, pe.name);
		strcpy(p1->addr, pe.addr);
		strcpy(p1->tel, pe.tel);
		p1->next = p2;
		p1 = p2;
		if (fwrite(&pe, sizeof(struct sign), 1, fp) != 1)
			printf("写入错误");
		printf("输入Y或y返回目录\n");
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
	printf("\n请输入要查询的姓名：");
	scanf("%s", &findname);
	while (p1->next != NULL)
	{
		if (strcmp(p1->name, findname) == 0)
		{
			printf("%10.8s %10.6s %12.10s\n","姓名", "地址", "电话号码");
			printf("%10.8s %10.6s %12.10s\n", p1->name, p1->addr, p1->tel);
			i++;
		}
		p1 = p1->next;
	}
	printf("共 %d 条\n", i);
	system("pause");
}
void del()
{
	char deletname[8];
	system("cls");
	int i, y = 0;
	p1 = p2 = head;
	printf("请输入你想要删除的联系人姓名：");
	scanf("%s", &deletname);
	getchar();
	while (p1 != NULL)
	{
		if (strcmp(p1->name, deletname) == 0)
		{
			printf("%10.8s %10.6s %12.10s %15.4s\n","姓名", "地址", "电话号码");
			printf("%10.8s %10.6s %12.10s %15.14s\n", p1->name, p1->addr, p1->tel);
			y = 1;
			printf("\n你要删除的是这个吗？1--是；2--否\n");
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
						printf("打开文件失败");
						exit(1);
					}
					p1 = head;
					while (p1->next != NULL)
					{
						if (fwrite(p1, sizeof(struct sign), 1, fp) != 1)
							printf("写入错误");
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
		printf("对不起，没有此联系人");
	}
	system("pause");
}
void display()
{
	printf("%10.8s %10.6s %12.10s\n", "姓名", "地址", "电话号码");
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
	printf("——————通讯录目录————————\n");
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
	printf("——————通讯录目录————————\n");
	printf("|                                     |\n");
	printf("|             输入错误！              |\n");
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
		printf("文件打开错误！");
		exit(1);
	}
	fclose(fp);
	if ((fp = fopen("data.txt", "r")) == NULL)
	{
		printf("文件打开错误");
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
		printf("选择你想要的功能：");
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
