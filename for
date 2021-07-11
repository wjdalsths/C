#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	//문제1
	//for(i=1;무한반복;i++) for(; ;)
	int num,i,cnt=0;
	scanf("%d", &num);
	for  (i = 1; ; i++)
	{
		cnt = cnt + i;
		if (cnt >= num)
			break;
	}
	printf("%d\n", i);
	printf("%d", cnt);

	//문제2
	int num,i,sum=0,cnt=0;
	scanf("%d", &num);
	for (i = 1; ; i+=2)
	{
		cnt++;
		sum += i;
		if (sum >= num)
			break;
	}
	printf("%d\t", cnt);
	printf("%d", sum);
  return 0;
}
