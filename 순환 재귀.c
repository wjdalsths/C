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
	printf("������ �Է��ϼ��� >>");
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

	//1~�Է¼����� ���ϱ�
	/*int n = get_integer();
	int s = add(n);
	printf("%d", s);*/

	//2������ �ٲٱ�
	/*int n;
	printf("2������ �ٲ� ��>> ");
	scanf("%d", &n);
	bin(n);*/

	return 0;
}