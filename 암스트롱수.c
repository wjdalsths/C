#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	//4.�Ͻ�Ʈ�� ��:�ڸ����� ������ ���� ���������� ���� ��
	//153 ���ڸ������� �������� ���� �ڽŰ� �����Ƿ� �Ͻ�Ʈ�ռ�
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
		printf("�Ͻ�Ʈ�� ���̴�");
	else
		printf("�Ͻ�Ʈ�� ���� �ƴϴ�");*/
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