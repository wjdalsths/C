#include<stdio.h>
#pragma warning(disable:4996)
int get_integer(int n);
int main()
{
	//1���� �迭�� ���� �ݺ����� �̿��Ͽ� ���
	//ù��° ���� ��� 1�� �ʱ�ȭ �ι�° �����ä���
	/*int arr[5][5] = { 1,1,1,1,1 };
	int i, j;
	for (i = 1; i < 5; i++)
	{
		arr[i][0] = 1;
		for (j = 1; j < 5; j++)
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}*/

	//2���� 10�̸��� �ڿ��� �� ���� �Է¹޾Ƽ� ù��°�װ� �ι�°���� �Է¹��� ���� �ʱ�ȭ�� �� ����° �׺��ʹ� �����װ� ������ ���� ���Ͽ� 1�� �ڸ��� ä���� 10���� ����ϴ� ���α׷�
	/*int score[10];
	printf("�� �� �Է�> ");
	scanf("%d %d", &score[0], &score[1]);
	int size = sizeof(score) / sizeof(int);
	for (int i = 2; i < size; i++)
		score[i] = (score[i - 2] + score[i - 1]) % 10;
	for (int i = 0; i < size; i++)
		printf("%d ", score[i]);*/

	//3���� 2�� 3�� �迭�� �ΰ� �����Ͽ� ������ ���� �Է� ���� ��,�ι迭�� ���� ��ġ���� ���Ͽ� ���ο� �迭�� ������ �� ����ϴ� ���α׷�
	/*int score[2][3];
	int score1[2][3];
	int new[2][3];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++) {
			printf("�� �Է�> ");
			scanf("%d", &score[i][j]);
		}
	printf("�ι�° array\n");
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++) {
			printf("�� �Է�> ");
			scanf("%d", &score1[i][j]);
		}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			new[i][j] = score[i][j] * score1[i][j];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", new[i][j]);
		}printf("\n");
	}*/

	//4���� �Ǻ���ġ������ 10,20,30,40��° 
	/*int arr[41] = { 0,1,1 };
	for (int i = 3; i < 41; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 1];
	}
	for (int i = 10; i < 41; i += 10)
	{
		printf("�Ǻ���ġ������ %d��° ��: %d\n", i,arr[i]);
	}*/

	//5���� ������ ���޹޾� ��� ���� ����'*'�� �̷���� �����ﰢ���� ����ϴ� �Լ��� �ۼ��ϰ� �Է¹��� ������ �����Ͽ� ����ϴ� ���α׷� �ۼ�
	/*int m;
	scanf("%d",&m);
	get_integer(m);*/

	//���ڿ� �� Null '\0'







}
int get_integer(int n)
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return n;
}