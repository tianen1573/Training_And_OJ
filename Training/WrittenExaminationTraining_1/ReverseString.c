#include<stdio.h>
#include<string.h>
void my_print(char* sH, char* sT, int count)
{
	//从后遍历数组
	while (sT != sH)
	{
		//输出单词条件
		if (*sT == ' ')
		{
			for (int i = 1; i <= count; i++)
			{
				printf("%c", *(sT + i));
			}
			printf(" ");
			//待输出单词长度count归零
			count = 0;
		}
		//记录单词长度
		else
		{
			count++;
		}
		sT--;
	}
    //从头遍历特殊判断
    //打印原序第一个单词
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