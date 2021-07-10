#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	//4.암스트롱 수:자리수의 세제곱 합이 원래정수와 같은 수
	//153 각자리숫자의 세제곱의 합이 자신과 같으므로 암스트롱수
	/*int num, sum=0, r,temp;
	printf("input number >>");
	scanf("%d", &num);
	temp = num;
	while (num)
	{
		r = num % 10;
		num = num / 10;
		sum = sum + (r * r * r);
	}
	if (temp == sum)
		printf("암스트롱 수이다");
	else
		printf("암스트롱 수가 아니다");*/
		/*int num, r, sum;
		for (int i = 100; i <= 1000; i++)
		{
			sum = 0;
			num = i;
			while (i)
			{
				r = num % 10;
				num /= 10;
				sum += r * r * r;
				if (num==0)
					break;
			}
			if(i == sum)
			printf("%d\n", i);
		}*/
	return 0;
}