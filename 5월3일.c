#include<stdio.h>
#pragma warning(disable:4996)
void func(int n) 
{
	if (n <= 0)
		return;//끝내는것  void 리턴값이없으므로 return만씀
	printf("%3d", n);
	func(n - 1);
}
void func2(int n)
{
	if (n <= 0)
		return;
	func2(n - 1);
	printf("%3d", n);
}
void numb(int n)
{
	if (n > 0)
		numb(n / 2);
	printf("%d", n % 2);
}
int gcd(int x, int y)
{
	if (y == 0)
		return x;
	gcd(y, x % y);
}
int x;
void sub();
int main() 
{

	/*func(10);
	printf("\n");
	func2(10);*/

	//numb(14);

	/*int n=gcd(18 ,15);
	printf("%d", n);*/

	for (x = 0; x < 10; x++)
		sub();






}
void sub()
{
	for (x = 0; x < 10; x++)
		printf("*");
}