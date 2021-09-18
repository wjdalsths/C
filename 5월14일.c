#include<stdio.h>
#pragma warning(disable:4996)
int get_integer(int n);
int main()
{
	//1문제 배열을 만들어서 반복문을 이용하여 출력
	//첫번째 행을 모두 1로 초기화 두번째 행부터채우기
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

	//2문제 10미만의 자연수 두 개를 입력받아서 첫번째항과 두번째항을 입력받은 수로 초기화한 후 세번째 항부터는 전전항과 전항의 합을 구하여 1의 자리로 채워서 10개를 출력하는 프로그램
	/*int score[10];
	printf("두 수 입력> ");
	scanf("%d %d", &score[0], &score[1]);
	int size = sizeof(score) / sizeof(int);
	for (int i = 2; i < size; i++)
		score[i] = (score[i - 2] + score[i - 1]) % 10;
	for (int i = 0; i < size; i++)
		printf("%d ", score[i]);*/

	//3문제 2행 3열 배열을 두개 선언하여 각각의 값을 입력 받은 후,두배열의 같은 위치끼리 곱하여 새로운 배열에 저장한 후 출력하는 프로그램
	/*int score[2][3];
	int score1[2][3];
	int new[2][3];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++) {
			printf("수 입력> ");
			scanf("%d", &score[i][j]);
		}
	printf("두번째 array\n");
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++) {
			printf("수 입력> ");
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

	//4문제 피보나치수열의 10,20,30,40번째 
	/*int arr[41] = { 0,1,1 };
	for (int i = 3; i < 41; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 1];
	}
	for (int i = 10; i < 41; i += 10)
	{
		printf("피보나치수열의 %d번째 항: %d\n", i,arr[i]);
	}*/

	//5문제 정수를 전달받아 출력 예와 같이'*'로 이루어진 직각삼각형을 출력하는 함수를 작성하고 입력받은 정수를 전달하여 출력하는 프로그램 작성
	/*int m;
	scanf("%d",&m);
	get_integer(m);*/

	//문자열 끝 Null '\0'







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