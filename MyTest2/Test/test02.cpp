#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#pragma warning(disable:4996)

#define MAX_NODE_NUM 500
#define MAX 10000
struct node {
	char node_str[MAX];
	bool skip;
} Node[MAX_NODE_NUM];

int main()
{
	int n;
	char str_buff[MAX];
	scanf("%d", &n);
	getchar();
	int child_num;
	for (int i = 0; i < n; i++)
	{
		child_num = 1;
		fgets(str_buff, sizeof(str_buff), stdin);
		str_buff[strcspn(str_buff, "\n")] = '\0';
		char* buff = strtok(str_buff, "/");
		if (buff != NULL)
			strcpy(Node[0].node_str, buff);
		while (buff != NULL)
		{
			buff = strtok(NULL, "/");
			if (buff != NULL)
			{
				strcpy(Node[child_num].node_str, buff);
				child_num++;
			}
		}
		for (int j = child_num - 1; j >= 0; j--)
		{
			if(Node[j].skip == true)
				continue;
			if (strcmp(Node[j].node_str, "..") == 0)
			{
				Node[j].skip = true;
				Node[j - 1].skip = true;
			}
			else if (strcmp(Node[j].node_str, ".") == 0)
			{
				Node[j].skip = true;
			}
			else
				Node[j].skip = false;
		}
		for (int j = 0; j < child_num; j++)
		{
			if (Node[j].skip == false)
			{
				if (j != child_num)
				{
					printf("/");
				}
				printf("%s", Node[j].node_str);
			}
			Node[j].skip = false;
		}
		printf("\n");
	}
}