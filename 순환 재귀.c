#include<stdio.h>
#pragma warning(disable:4996)
int fac(int n)
{
	if (n == 1)
		return(1);
	else 
		return n * fac(n - 1);
}
int get_integer()
{
	int n;
	printf("정수를 입력하세요 >>");
	scanf("%d", &n);
	return n;
}
int add(int n)
{
	if (n == 1)
		return 1;
	else
		return n + add(n - 1);
}
void bin(int n)
{
	
	if (n > 0)
		bin(n / 2);
	printf("%d", n % 2);
}
int main()
{
	/*int num;
	scanf("%d", &num);
	int f=fac(num);
	printf("%d", f);*/

	//1~입력수까지 더하기
	/*int n = get_integer();
	int s = add(n);
	printf("%d", s);*/

	//2진수로 바꾸기
	/*int n;
	printf("2진수로 바꿀 수>> ");
	scanf("%d", &n);
	bin(n);*/

	return 0;
}