#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#pragma inline
#define N 2
typedef struct
{
	char name[10];
	char count:8;
	short p_price;
	short s_price;
	short t_amount;
	short s_amount;
	short recommend;
}good;
good ga1[N] = { 0 };
extern "C" void func3_calculation(good *p);
extern "C" void func4_rank(good *p1, short *p3);
extern "C" void func5_output(good *p1, short *p3,char *str6);
char enter[] = { "0" };
char str6[] = { "商品的名称，折扣，进价，售价，进货数，已售数，推荐度，推荐度排名如下:\n" };
short goods_degree[N] = { 0 };
char BUF[15] = { 0 };
int find()
{
	int flag1 = 1;
	char input_good[10] = { 0 };
	printf("请输入您要查询的商品！\n");
rewritegood:
	scanf("%s", input_good);
	if (strcmp(input_good, enter) == 0)
	return 0;
	for (int i = 0; i < N; i++)
	{
		flag1 = strcmp(ga1[i].name, input_good);
		if (flag1 == 0)
		{
			printf("商品名称：%s 折扣：%d 销售价：%d 进货总数：%d 已售数量：%d 推荐度：%d \n", ga1[i].name, ga1[i].count, ga1[i].s_price, ga1[i].t_amount, ga1[i].s_amount, ga1[i].recommend);
			return 0;
		}
	}
	printf("未找到对应的商品，请重新输入！\n");
	goto rewritegood;
}
extern "C" void printv(int v)
{
	printf("%d\n", v);
}

extern "C" void prints(char *s)
{
	printf("%s", s);
}
extern "C" void printAGood(good *gai, int index)
{
	printf("%s ", ga1[index].name);
	printf("%d ", ga1[index].count);
	printf("%d ", ga1[index].p_price);
	printf("%d ", ga1[index].s_price);
	printf("%d ", ga1[index].t_amount);
	printf("%d ", ga1[index].s_amount);
	printf("%d ", ga1[index].recommend);
}
int main()
{
	char true_name[] = {"fenghaobo"};
	char true_pass[] = {"12345"};
	char quit[] = { "q" };
	char good_1[] = { "pen" };
	char good_2[] = { "book" };
	char good_3[] = { "Temp-Value" };
	char input_name[10] = { 0 };
	char input_pass[6] = { 0 };
	char input_good[10] = { 0 };
	int flag = 1;
	int auth = 0;
	strcpy(ga1[0].name, good_1);
	ga1[0].count = 10;
	ga1[0].p_price = 35;
	ga1[0].s_price = 56;
	ga1[0].t_amount = 70;
	ga1[0].s_amount = 25;
	ga1[0].recommend = 0;
	strcpy(ga1[1].name, good_2);
	ga1[1].count = 9;
	ga1[1].p_price = 12;
	ga1[1].s_price = 30;
	ga1[1].t_amount = 25;
	ga1[1].s_amount = 5;
	ga1[1].recommend = 0;
	for (int i = 2; i < N; i++)
	{
		strcpy(ga1[i].name, good_3);
		ga1[i].count = 8;
		ga1[i].p_price = 15;
		ga1[i].s_price = 20;
		ga1[i].t_amount = 30;
		ga1[i].s_amount = 2;
		ga1[i].recommend = 0;
	}
	printf("请输入您的用户名！\n");
rewritename:
	scanf("%s", input_name);
	flag = strcmp(input_name, quit);
	if (flag == 0)
	{
		printf("正在退出！\n");
		goto quit;
	}
	flag = strcmp(input_name, enter);
	if (flag == 0)
		;
	else
	{
		flag = strcmp(input_name, true_name);
		if (flag != 0)
		{
			printf("您输入的用户名有误，请重新输入用户名\n");
			goto rewritename;
		}
		printf("请输入您的密码！\n");
	rewritepass:
		scanf("%s", input_pass);
		flag = strcmp(input_pass, true_pass);
		if (flag != 0)
		{
			printf("您输入的用密码有误，请重新输入密码\n");
			goto rewritepass;
		}
		printf("登录成功！\n");
		system("pause");
		auth = 1;
	}
function3:
	system("CLS");
	if (auth == 0)
	{
		int choose1 = 0;
		printf("                         MENU                      \n");
		printf("//-----------------------------------------------//\n");
		printf("         1=查询商品信息          2=程序退出          \n");
		printf("//-----------------------------------------------//\n");
		printf("请选择您要进行的操作！\n");
		scanf("%d", &choose1);
		if (choose1 == 1)
		{
			find();
			printf("商品信息显示完毕！\n");
			system("pause");
			goto function3;
		}
		else if (choose1 == 2)
		{
			printf("正在退出！\n");
			goto quit;
		}
		else 
		{
			printf("您的输入有误，请重新输入！\n");
			goto function3;
		}

	}
	else if (auth == 1)
	{
		printf("                         MENU                      \n");
		printf("//-----------------------------------------------//\n");
		printf("1 = 查询商品信息 2 = 修改商品信息 3 = 计算推荐度\n");
		printf("4 = 计算推荐度排名 5 = 输出全部商品信息 6 = 程序退出\n");
		printf("//-----------------------------------------------//\n");
		int choose2 = 0;
		printf("请选择您要进行的操作！\n");
		scanf("%d", &choose2);
		if (choose2 == 1)
		{
			find();
			printf("商品信息显示完毕！\n");
			system("pause");
			goto function3;
		}
		else if (choose2 == 6)
		{
			printf("正在退出！\n");
			goto quit;
		}
		else if (choose2 == 2)
		{
			int flag2 = 0;
			int index = 0;
			int temp = 0;
			char change_good[10] = { 0 };
			printf("请输入您要修改的商品名称！\n");
		rewritechange:
			scanf("%s", change_good);
			for (int i = 0; i < N; i++)
				if (strcmp(change_good, ga1[i].name) == 0)
				{
					flag2 = 1;
					index = i;
					break;
				}
			if (flag2 == 0)
			{
				printf("请重新输入商品名！\n");
				goto rewritechange;
			}
			printf("请依次输入您要修改的数据！\n");
			printf("折扣：%d 》", ga1[index].count);
			scanf("%d", &temp);
			ga1[index].count = temp;
			printf("进货价：%d 》", ga1[index].p_price);
			scanf("%hd", &(ga1[index].p_price));
			printf("销售价：%d 》", ga1[index].s_price);
			scanf("%hd", &(ga1[index].s_price));
			printf("进货总数：%d 》", ga1[index].t_amount);
			scanf("%hd", &(ga1[index].t_amount));
			printf("数据修改完毕！\n");
			system("pause");
			goto function3;
		}
		else if (choose2 == 3)
		{
			func3_calculation(ga1);
			//for (int i = 0; i < N; i++)
				//printf("%d\n", ga1[i].recommend);
			printf("推荐度计算完毕！\n");
			system("pause");
			goto function3;
		}
		else if (choose2 == 4)
		{
			func4_rank(ga1, goods_degree);
			printf("推荐度排名计算完毕！\n");
			system("pause");
			goto function3;
		}
		else if (choose2 == 5)
		{
			func5_output(ga1, goods_degree, str6);
			printf("商品信息显示完毕！\n");
			system("pause");
			goto function3;
		}
	}
	quit:
	return 0;
}
