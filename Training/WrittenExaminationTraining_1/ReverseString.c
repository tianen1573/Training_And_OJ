#include<stdio.h>
#include<string.h>
void my_print(char* sH, char* sT, int count)
{
	//�Ӻ��������
	while (sT != sH)
	{
		//�����������
		if (*sT == ' ')
		{
			for (int i = 1; i <= count; i++)
			{
				printf("%c", *(sT + i));
			}
			printf(" ");
			//��������ʳ���count����
			count = 0;
		}
		//��¼���ʳ���
		else
		{
			count++;
		}
		sT--;
	}
    //��ͷ���������ж�
    //��ӡԭ���һ������
	for (int i = 0; i <= count; i++)
	{
		printf("%c", *(sT + i));
	}
}
int main()
{
	char str[100] = { 0 };
	gets(str);
	my_print(str, str + strlen(str) - 1, 0);
	return 0;
}