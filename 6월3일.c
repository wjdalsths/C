#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int main()
{
	//�迭
	/*char c[10] = { "gwangju" };
	int size = sizeof(c);
	int si = sizeof(c) / 10;
	printf("%d %d\n", size, si);
	printf("%p %p\n", c, &c[0]);
	printf("%d\n", strlen(c));*/
	//���ڿ� ���� strlen()
	//%p �ּ�
	
	//strcat(to,"���ڿ�")to�� ���ڿ��� �ٿ���
	//strcpy(to,from)to�� from ����
	/*char from[10] = { "king" };
	char to[10];
	strcpy(to, from);
	printf("%s\n", to);
	strcat(to, "dom");
	printf("%s\n", to);
	if (strlen(to) + strlen("princess") > sizeof(to))
		printf("�߰�����");
	else{
		strcat(to, "princess");
		printf("%s", to);
	}*/
	
	//���ں� �ּҷ�x
	//strcmp ���ڿ��� 0=���� ����=str2 ���=str1
	/*char str1[10] = { "king" };
	char str2[10] = { "king" };
	if (!(strcmp(str1, str2)))
		printf("����\n");
	else
		printf("���ڿ��� �ٸ���\n");*/
	
	//���ڿ� �ޱ�
	/*char name[20];
	char teleno[15];
	char addre[50];
	printf("�̸�>>");
	scanf("%s%*c", name);//����
	printf("��ȣ>>");
	gets(teleno);
	printf("�ּ�>>");
	gets(addre);*/
	
	//2���� �迭 �ް� ���
	/*char names[3][20];//�� �̸� �� �̸�ũ������
	for (int i = 0; i < 3; i++)
		gets(names[i]);
	for (int i = 0; i < 3; i++)
		printf("%s\n", names[i]);*/

	//���ڿ� �ٲٱ�
	/*char first[10];
	char second[10];
	char temp[10];
	gets(first);
	gets(second);
	strcpy(temp, first);
	strcpy(first, second);
	strcpy(second, temp);
	printf("first: %s\nsecond: %s\n", first,second);*/












	return 0;
}