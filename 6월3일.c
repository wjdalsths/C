#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int main()
{
	//배열
	/*char c[10] = { "gwangju" };
	int size = sizeof(c);
	int si = sizeof(c) / 10;
	printf("%d %d\n", size, si);
	printf("%p %p\n", c, &c[0]);
	printf("%d\n", strlen(c));*/
	//문자열 길이 strlen()
	//%p 주소
	
	//strcat(to,"문자열")to에 문자열을 붙여줌
	//strcpy(to,from)to에 from 저장
	/*char from[10] = { "king" };
	char to[10];
	strcpy(to, from);
	printf("%s\n", to);
	strcat(to, "dom");
	printf("%s\n", to);
	if (strlen(to) + strlen("princess") > sizeof(to))
		printf("추가실패");
	else{
		strcat(to, "princess");
		printf("%s", to);
	}*/
	
	//문자비교 주소로x
	//strcmp 문자열비교 0=같다 음수=str2 양수=str1
	/*char str1[10] = { "king" };
	char str2[10] = { "king" };
	if (!(strcmp(str1, str2)))
		printf("같다\n");
	else
		printf("문자열이 다르다\n");*/
	
	//문자열 받기
	/*char name[20];
	char teleno[15];
	char addre[50];
	printf("이름>>");
	scanf("%s%*c", name);//엔터
	printf("번호>>");
	gets(teleno);
	printf("주소>>");
	gets(addre);*/
	
	//2차원 배열 받고 출력
	/*char names[3][20];//행 이름 열 이름크기제안
	for (int i = 0; i < 3; i++)
		gets(names[i]);
	for (int i = 0; i < 3; i++)
		printf("%s\n", names[i]);*/

	//문자열 바꾸기
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