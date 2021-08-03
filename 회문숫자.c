#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	//2.회문숫자: 어느쪽으로 읽든지 똑같은 수(예:131,2112)
	/*int num, sum=0, r,temp;
	printf("input number >>");
	scanf("%d", &num);
	temp = num;
	while (num)
	{
		r = num % 10;
		num = num / 10;
		sum = sum*10 + r;
	}
	if (temp == sum)
		printf("회문숫자");
	else
		printf("회문숫자가 아니다");*/

		//3.입력받은 숫자를 거꾸로 출력(예:1234>4321)
		/*int num, r, reverse=0;
		printf("input number >>");
		scanf("%d", &num);
		while (num)
		{
			r = num % 10;
			num = num / 10;
			reverse = reverse * 10 + r;
		}
		printf("반전된 수 %d", reverse);*/
	 
}
