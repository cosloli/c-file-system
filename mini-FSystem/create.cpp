#include "pch.h"
#include "Fcommand.h"
/*Creat 1G space*/
void create(char *name)
{
	int i;
	for (i = 0; name[i] != '\0'; i++)
	{
		if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || (name[i] >= '0' && name[i] <= '9')))
		{
			printf("System name input is not legal!\n");
			return;
		}
	}
	//�ļ�ϵͳ����·��
	mini_path[3] = '\0';
	strcat(mini_path, name);

	/*.DAT������һ�ֱ�׼�ļ�������������ʹ�������չ�������ļ����岻ͬ��
		DAT�ļ������԰�����չ����������DATA����˼���������ļ��������ļ���û�н��о��Ի��Ķ��塣*/
	strcat(mini_path, ".dat");

	//�Զ�/д��ʽ�򿪻���һ���������ļ�����������д����ΪNULL��򲻿���
	if ((fp = fopen(mini_path, "wb+")) == NULL)
	{
		printf("System name input is not legal!\n");
		return;
	}
	//����1G�ռ�
	fseek(fp, 1024 * 1024 * 1024, 0);
	putw(0, fp);
	fclose(fp);
	//�ж��ļ��Ƿ񱻴���
	if ((fp = fopen(mini_path, "r+")) != NULL)
		printf("\nCreate file success.\n");
	fflush(fp);
	format();
}