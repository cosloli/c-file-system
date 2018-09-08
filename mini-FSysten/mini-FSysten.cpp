// mini-FSysten.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace std;

/*宏定义*/
#define BLOCK_SIZE 4096		//每个块的大小
#define BLOCK_NUMBER 262144 //文件系统中块的数量
#define FCB_NUMBER 4032 * 64//控制单元的数量为258048个，隶属于（1，4032），寻找控制块操作应为第x块，第y个
#define IB_NUMBER 258111	//文件信息块数量为258111个，隶属于（4033，262144）
/*宏定义*/

/*全局变量*/
char mini_path[100] = "E:\\";
/*全局变量*/ 

/*函数定义*/
void create(char *name);
/*函数定义*/

/*creat 1G space*/
void create(char *name)
{
	FILE *fp;
	int i;
	for (i = 0; name[i] != '\0'; i++)
	{
		if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || (name[i] >= '0' && name[i] <= '9')))
		{
			printf("系统名称输入不合法！\n");
			return;
		}
	}
	//文件系统所在路径
	mini_path[3] = '\0';
	strcat(mini_path, name);

	/*.DAT并不是一种标准文件。许多软件都使用这个扩展名，但文件含义不同。
		DAT文件，可以按照扩展名来看就是DATA的意思，即数据文件，这类文件并没有进行绝对化的定义。*/
	strcat(mini_path, ".dat");	

	//以读/写方式打开或建立一个二进制文件，允许读和写。（为NULL则打不开）
	if ((fp = fopen(mini_path, "wb+")) == NULL)	
	{
		printf("系统名称输入不合法!\n");
		return;
	}
	//开辟1G空间
	fseek(fp, 1024 * 1024 * 1024, 0);
	putw(0, fp);
	fclose(fp);
	//判断文件是否被创建
	if ((fp = fopen(mini_path, "r+")) != NULL)
		printf("创建文件成功！\n");
	fclose(fp);
	//Format();
}

int main()
{
	char name[10] = "miniFS";
	create(name);
}
