#include<stdio.h>
#include<string.h>
#include<time.h>
#pragma warning(disable:4996)
void swap();
int even();
void wordlist();
void name1();
void selection_sort();
void marge_sort();
int main()
{
	/*int x = 5, y = 10;
	int z = x + y;
	printf("%d", z);*/

	/*int A = 2, B = 3;
	printf("%d", (A+B)*2);*/

	/*int x = 1, y = 2;
	double z = 1.5;
	printf("%d\n", x);
	printf("%.2f\n", x + y);
	printf("%d\n",x + y + z);
	printf("%d\n", 2x);
	printf("%d\n",2 * x);
	printf("%d\n", 2.0 * x);
	printf("%.2f\n",x + 1.0);
	printf("%.2f\n", x - 1.0);
	printf("%.2f\n", x - 1);
	printf("%d\n", z - 0.5);
	printf("%.2f\n", xz);
	printf("%d", x * z);*/

	/*int a = 1, b = 2, c = 3;
	printf("%d\n", (b + c) * 2);
	printf("%d\n", ((b+c)*2)*((b + c) * 2));
	printf("%d", (((b + c) * 2) * ((b + c) * 2)) * ((b + c) * 2));*/

	/*int a = 3, b = 5, c = 7;
	a = b = c;
	printf("%d %d %d", a, b, c);*/

	/*int a = 3, b = 5, c = 7;
	b = b + 1;
	a = a + b;
	c = c + 1 + a;
	printf("%d %d %d", a, b, c);*/

	/*int a = 1, b = 2, c = 3;
	a += b;
	b += c;
	c++; c++;
	printf("%d %d %d", a, b, c);*/

	/*int a = 2, b = 4;
	double c = 1.6;
	b += a;
	double d = b / c;
	c = d++ + c;
	printf("%d %d %f %f", a, b, c, d);*/

	/*int a = 2; int b = 5;
	printf("%d\n", b - a);
	a++; b++;
	printf("%d\n", --b);
	b= b + b++;
	printf("%d",b);*/

	/*int a = 1, b = 2, c = 3;
	a += b++ + c;
	b += ++b + c;
	c += c++ + ++c;
	printf("%d %d %d", a, b, c);*/

	/*int a = 1;
	printf("%d\n", a++);
	printf("%d\n", a + (++a));
	printf("%d\n", a++ + ++a * a);*/

	//int a = 1;
	///*int b = ++a * ++a;
	//int c = ++a + a;*/
	//int b = ++a + ++a;
	//int c = b++ + ++a;
	//printf("%d", b+c);

	/*int a = 1, b = 2;
	a += b += 3;
	printf("%d %d\n", a, b);
	a *= a++ - a++ * b;
	printf("%d",a + b);*/

	/*char x = 'k', y = 'g';
	printf("%c %c %d %d", x, y, x, y);*/

	/*char a = 'a', b = 'b', c = 'c';
	printf("%d", a + b + c);*/

	/*char a = 'A';
	printf("%d\n", a++);
	printf("%c\n", ++a);
	printf("%c\n", a + 32);*/

	/*char a = 'A';
	printf("%d %c %d %c", a++, ++a, a++, a);*/

	//char str[12] = "strawberry";
	/*printf("%s\n", str);
	for (int i = 0; i < 12; i++)
		printf("%c", str[i]);*/
	/*for (int i = 0; i < 12; i++) {
		for (int j = i; str[j]!='\0'; j++) {
			printf("%c", str[j]);
		}printf("\n");
	}*/

	/*char *str1 = "BITCODING";
	char str2[10] = "HELLO";
	printf("%s %p\n", str1, str1);
	printf("%s %p\n", str2, str2);*/

	/*char str1[] = "BITCODING";
	char* p = strchr(str1,'B');
	printf("%d\n", strlen(str1));
	printf("%d %d", p - str1, strchr(str1, 'l')-str1);

	char* str2 = "ABCDEFG";
	char* s = strstr(str2, "CG");
	printf("%s %d %d\n", s, s);

	char* t = strstr(str2, "DE");
	printf("%s %d %d\n", t, t, t - str2);*/
	//인덱스를 알고 싶다면 str2를 빼야한다.

	/*char str1[] = "bac";
	char str2[] = "abc";
	char str3[] = "bad";
	char str4[] = "ABC";
	printf("%d\n", strcmp(str1, str2));
	printf("%d\n", strncmp(str1, str3, 2));
	printf("%d %d", strcmp(str2, str4), _stricmp(str2, str4));*/

	/*char str1[100] = "melon";
	char str2[100] = "melody";
	char str3[100] = "music";
	printf("%d\n", strspn(str1, str2));
	printf("%s\n", strcat(str2, str3));
	printf("%s\n", str2);
	printf("%s %s\n", strcpy(str2, str3), str2);*/

	/*char nation[6] = "Korea";
	printf("%s", nation);*/
	
	//구구단
	/*for (int i = 2; i < 10; i++)
	{	
		printf("\n   %d단\n",i);
		for (int j = 1; j < 10; j++) {
			printf("%d * %d = %d\n", i, j, i * j);
		}
	}*/
	
	/*int a=2, b=1;
	while (a<10)
	{
		printf("\n   %d단\n", a);
		b = 1;
		while (b<10)
		{
			printf("%d * %d = %d\n", a, b, a * b);
			b++;
		}
		a++;
	}*/
	
	/*for (int i = 1; i < 10; i++)
	{
		for (int j = 2; j < 10; j++) {
			printf("%d * %d = %d\t", j, i, i * j);
		}printf("\n");
	}*/
	
	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}printf("\n");
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j <2-i; j++)
			printf("*");
		printf("\n");
	}*/
	
	/*for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3 - i; j++)
				printf("*");
			printf("\n");
		}
	for (int i = 1; i < 3; i++) {
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}printf("\n");
	}*/
	
	/*float fNum = 3.14;
	printf("%d %d\n", (int)fNum, fNum);
	char s[10];
	sprintf(s, "%f", fNum);
	float fNum_2 = atof(s);
	printf("%s %f", s, fNum_2);*/
	
	/*int n,a=20,n1;
	scanf("%d", &n);
	n1 = n - 2017;
	a += n1;
	printf("%d년 지수의 나이는 %d세입니다",n,a);*/


	/*char a[30];
	gets(a);
	int n = strlen(a);
	printf("문장길이는%d입니다", n);*/


	/*int num;
	scanf("%d", &num);
	num % 3 == 0 && num % 4 != 0 ? printf("1") : printf("0");*/

	/*int num;
	scanf("%d", &num);
	printf("%o", 4 * num);*/
	
	//printf("\"C:\\Users\\dataset\"");

	/*char str[10] = "ABCDEFGH";
	printf("%c\n", str[5]);
	printf("%s", str[6]);*/
	
	/*int n;
	scanf("%d", &n);
	printf("%c %c", 64 + n, 96 + n);*/
	
	/*int n,a,b;
	scanf("%d", &n);
	a = n / 10000;
	n = n % 100;
	b = n / 10;
	printf("%d", a* b);*/

	
	/*int n;
	scanf("%d", &n);
	if (n % 2 == 0)
		printf("even number");
	else
		printf("odd number");*/

	/*int n;
	scanf("%d", &n);
	n = n / 10000;
	if (n > 18) {
		if (100 - n + 18 >= 65)
			printf("old");
	}*/
	
	//112
	
	/*int a, b;
	scanf("%d %d", &a, &b);
	if (a > b) a++;
	else if (a == b)b += a;*/

	/*char a;
	scanf("%c", &a);
	if (a == 'A' || a == 'B')
		printf("참 잘했습니다");
	else if (a == 'C' || a == 'D')
		printf("좀 더 노력하세요");
	else
		printf("다음 학기에 다시 수강하세요");*/

	/*int age; char y;
	scanf("%d", &age);
	if (age >= 12)
		printf("통과");
	else {
		printf("부모님과 동행? y,n ");
		scanf(" %c", &y);
		if (y == 'y')
			printf("통과");
		else
			printf("거절");
	}*/

	/*int a, b,t;
	if (b > a)
	{
		t = a;
		a = b;
		b = t;
	}
	printf("%d", a - b);*/

	/*int n, n1;
	char a;
	scanf("%d %c %d", &n, &a, &n1);
	if (a == '*')
		printf("%d", n * n1);
	else if (a == '+')
		printf("%d", n + n1);
	else if (a == '-')
		printf("%d", n - n1);
	else
		printf("%d", n / n1);*/

	/*int n, n1;
	char a;
	scanf("%d %c %d", &n, &a, &n1);
	switch (a)
	{
	case'+':printf("%d", n + n1); break;
	case'-':printf("%d", n - n1); break;
	case'*':printf("%d", n * n1); break;
	case'/':printf("%d", n / n1); break;
	default:printf("연산자가 잘못됨");break;
	}*/

	/*int i = 2;
	while (i<=20)
	{
		printf("%d ", i);
		i *= 2;
	}*/

	//134

	/*char c[20];
	gets(c);
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	printf("%s에서 구간[%d,%d]의 부분 문자열은",c,num1,num2);
	for (int i = num1; i <= num2; i++) {
		printf("%c", c[i]);
	}*/

	/*char a;
	while (1)
	{
		printf("Enter the alphabet:");
		scanf(" %c", &a);
		
		if (a == 'q')
		{
			printf("finish");
			break;
		}
	}*/

	/*int fn, sn,t;
	scanf("%d %d", &fn, &sn);
	if (fn > sn) {
		t = fn;
		fn = sn;
		sn = t;
	}
	while (fn<=sn)
	{
		if (fn % 5 == 0)
			printf("%d ", fn);
		fn++;
	}*/

	/*int c=0;
	for (int i = 1; i <=10000; i++)
	{
		if (i % 7 == 0)
			continue;
		c++;
	}printf("%d", c);*/

	/*int n,s=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		s += i;
	}printf("%d", s);*/
	
	/*int n, i, s=0;
	scanf("%d", &n);
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
			s = 1;
	}
	if (s)
		printf("소수x");
	else
		printf("소수");*/
	
	/*int n, n1=0,s=0;
	scanf("%d", &n);
	for (int i = 0; i < 6; i++) {
		n1 = n % 10;
		n = n / 10;
		s += n1;
	}printf("%d", s);*/

	/*char m[20];
	gets(m);
	for (int i = 0; m[i] != NULL; i++) {
		for (int j = 0; j <=i; j++) {
			printf("%c", m[j]);
		}printf("\n");
	}*/
	
	/*for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 10 - i; j++) {
			printf(" ");
		}
		for (int j = 0; j <= i; j++) {
			printf("*");
		}printf("\n");
	}*/
	
	/*for (int i = 0; i < 6; i++) {
		for (int j = 0; j <=2 * i; j++) {
			printf("*");
		}printf("\n");
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 11; j++)
			printf("*");
		printf("\n");
	}*/
		
	/*for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 10 - i; j++) {
			printf(" ");
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			printf("*");
		}printf("\n");
	}*/

	/*for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5 - i; j++) {
			printf(" ");
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			printf("*");
		}printf("\n");
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			printf(" ");
		}
		for (int j = 0; j < 11-((i+1)*2); j++) {
			printf("*");
		}printf("\n");
	}*/

	/*for (int i = 0; i <=10; i++) {
		for (int j = 0; j <= 10; j++) {
			if (3 * j + 2 * i == 10) {
				printf("x=%d y=%d\n", j, i);
			}
		}
	}*/
	
	/*for (int a = 0; a <= 100; a++) {
		for (int b = 0; b <= 100; b++) {
			for (int c = 0; c <= 100; c++) {
				if (a != b != c)
				{
					if (a + b + c == 100)
						printf("a=%d b=%d c=%d\n", a, b, c);
				}
			}
		}
	}*/

	/*int num = 5;
	if (num == 1)goto ONE;
	else if (num == 2)goto TWO;
	else goto FINISH;

	ONE:printf("1");
		goto FINISH;
	TWO:printf("2");
		goto FINISH;
	FINISH:printf("FINISH");*/


	/*int n,n1;
	scanf("%d", &n);
	n1 = n / 10;
	n = n % 10;
	if (n == n1)
		printf("십의 자리와 일의 자리가 같다");
	else
		printf("십의 자리와 일의 자리가 다르다");*/
	
	/*int p;
	scanf("%d", &p);
	if (p >= 200000)
		printf("지불금액=%f", (float)p * 0.85);
	else if (p >=50000)
		printf("지불금액=%f", (float)p * 0.9);
	else if (p >=10000)
		printf("지불금액=%f", (float)p * 0.95);
	else
		printf("지불금액=%d", p);*/
	
	/*int n,n1;
	scanf("%d", &n);
	n1 = n / 10;
	n = n % 10;
	if (n == 9 || n == 6 || n == 3)
		printf("짝");
	if (n1 == 9 || n1 == 6 || n1 == 3)
		printf("짝");*/

	/*int cnt = 0;
	for (int i = 2; i < 100; i++) {
		for (int j = 2; j < 100; j++) {
			if (i = j * j*0.5)
				cnt++;
		}
	}
	printf("%d", cnt);*/



	/*int x = 10,y=100;
	swap(&x, &y);
	printf("%d %d", x, y);*/

	/*int *num;
	int su = 6;
	num = &su;
	printf("%d\n", num);
	printf("%d\n", *num);

	printf("%d\n", su);
	printf("%p\n", &su);*/

	/*int a[] = { 1,2,3,4 };
	printf("*a = %u\n", *a);
	printf("*(a+1) = %u\n", *(a + 1));
	printf("*(a+1) = %u\n", *(a + 2));*/

	/*int a[] = { 1,2,3,4,5 };
	int* ptr = a;
	int sum=0;
	for (int i = 0; i < 5; i++) {
		if (*(ptr + i)%2 == 0)
			sum += *(ptr + i);
	}
	printf("%d", sum);*/

	/*int a[] = { 1,2,3,4,5 };
	int* ptr = a;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		if (ptr[i] % 2 == 0)
			sum += ptr[i];
	}
	printf("%d", sum);*/

	/*int a[] = { 1,2,3,4,5 };
	printf("%d", even(a));*/

	/*char* str = "BITCODING";
	printf("%s\n", str);
	printf("%c %c\n", *str, str[0]);
	printf("%c %c\n", *(str + 1), str[1]);*/
			
	//char* lang[3] = { "C","JAVA","PYTHON" };
	//
	//for (int i = 0; i < 3; i++)
	//	printf("%s ", /**(lang + i)*/lang[i]);

	/*int x = 10;
	int* intptr = &x;
	*intptr *= 10;
	printf("%d", *intptr + x);*/
	
	/*char* str = "ACEGI";
	printf("%s\n", str);
	printf("%c\n", *str);
	printf("%c\n", *str + 1);
	printf("%c\n", *(str + 3));*/
	
	/*int score;
	scanf("%d", &score);
	printf("%c", grede(score));*/
	
	/*int n;
	scanf("%d", &n);
	printf("%d", fun(n));*/

	/*char a[50];
	gets(a);
	wordlist(&a);*/

	/*char pass[20];
	while (1)
	{
		printf("암호 입력>> ");
		gets(pass);
		int ncnt=0,acnt=0,Acnt=0;
		for (int i = 0; pass[i] != NULL; i++) {
			if (pass[i] >= 97 && pass[i] <= 122) 
				acnt++;
			if (pass[i] >= 65 && pass[i] <= 90)
				Acnt++;
			if (pass[i] >= '0' && pass[i]<'10')
				ncnt++;
		}
		if (acnt == 0 || Acnt == 0 || ncnt == 0)
			printf("암호를 다시 만들라\n\n");
		else if (acnt + Acnt + ncnt < 6)
			printf("암호를 다시 만들라\n\n");
		else
		{
			printf("암호: %s", pass);
			break;
		}
	}*/
	
	/*int n;
	scanf("%d", &n);
	int r= num(n);
	if(r==1)
		printf("True");
	else
		printf("False");*/

	

	




	/*char name[50] = { "Son jeongmin" };
	printf("%s\n", name);
	int n = strlen(name);
	printf("문자열 길이: %d\n", n);
	name1(n,&name);*/

	/*int n0=0,n1=1;
	srand((unsigned)time(NULL));
	for (int i = 1; i < 100; i++) {
		if (rand() % 2 == 0)
			n0++;
		else
			n1++;
	}printf("앞면: %d, 뒷면: %d", n0, n1);*/
	
	/*int a,n;
	srand((unsigned)time(NULL));
	printf("0가위, 1바위, 2보 >");
	scanf("%d", &n);
	a = rand() % 3;
	if (a == n)
		printf("무승부\n");
	else if (n - a == 1||n-a==-2)
		printf("사람 승\n");
	else
		printf("컴 승\n");
	printf("사람:%d 컴:%d", n, a);*/

	/*int n, a, c=0;
	srand((unsigned)time(NULL));
	a = rand() % 100;
	while (1) {
		printf("숫자 >>");
		scanf("%d", &n);
		c++;
		if (n == a) {
			printf("정답\n");
			break;
		}
		else if (n > a)
			printf("DOWN\n");
		else if (n < a)
			printf("UP\n");
	}printf("%d\n", a);
	printf("시도 횟수: %d", c);*/
		

	//야구 게임
	/*int ai[3];
	srand((unsigned)time(NULL));
	int p[3];
	int st=0, ba=0;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			ai[i] = rand() % 9 + 1;
		}
		if (ai[0] == ai[1] || ai[1] == ai[2] || ai[2] == ai[0])
			continue;
		else
			break;
	}
	for (int i = 0; i < 3; i++) {
		printf("%d ", ai[i]);
	}
	while (1)
	{
		printf("숫자 3개(1~9) >>");
		scanf("%d %d %d", &p[0], &p[1], &p[2]);
		st = 0; ba = 0;
		for (int i = 0; i < 3; i++) {
			if (p[i] == ai[i]) {
				st++;
			}
			else if (p[i] != ai[i]) {
				for (int j = 0; j < 3; j++)
					if (p[i] == ai[j])
						ba++;
			}
			else
				break;
		}
		if (st == 3) {
			printf("%dstrike 승리\n", st);
			break;
		}
		else if (st > 0)
			printf("%dstrike\n", st);
		else if (ba > 0)
			printf("%dball\n", ba);
		else
			printf("3out");
	}*/
	
	//순차탐색
	/*int arr[] = {3, 5, 1, 7, 49, 26, 8, 11, 90, 99};
	int n;
	scanf("%d", &n);
	for (int i = 0; i < sizeof(arr)/sizeof(int); i++){
		if (arr[i] == n)
		{
			printf("%d방에서 %d을 찾음", i, n);
			return 0;
		}
	}printf("찾지 못함");*/

	//이분탐색
	/*int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n;
	int left = 0, right = sizeof(arr) / sizeof(int)-1,mid=0;
	scanf("%d", &n);
	while (left<=right)
	{
		mid = (left + right) / 2;
		if (n == arr[mid])
		{
			printf("%d방에서 값을 찾음", mid, n);
			return 0;
		}
		else if (n > arr[mid])
			left = mid+1;
		else if (n < arr[mid])
			right = mid-1;
	}printf("값을 찾지 못함");*/

	
	
	
	
	
	
	//선택정렬
	//int n[5] = { 3,5,1,2,0 };
	/*int min,t=0,p;
	for (int i = 0; i < 5; i++) {
		min = 99999;
		for (int j = i+1; j < 5; j++) {
			if (min > n[j]) {
				min = n[j];
				p = j;
			}
		}
		if (min < n[i]){
			t = n[i];
			n[i] = n[p];
			n[p] = t;
		}
	}	
	for (int i = 0; i < 5; i++)
		printf("%d ", n[i]);*/

	/*selection_sort(n);
	for (int i = 0; i < 5; i++)
		printf("%d ", n[i]);*/

	/*int a[] = { 8,9,3,7,6 };
	int a1[] = { 1,2,4,0,5 };
	marge_sort(a, a1);*/

		

	return 0;
}
void marge_sort(int *a,int *a1) {
	selection_sort(a);
	selection_sort(a1);
	int A[10],p=0,p1=0;
	for (int i = 0; i < 10; i++) {
		if (p >= 5) {
			A[i] = a1[p1++];
		}
		else if (p1 >= 5) {
			A[i] = a[p++];
		}
		else if (a[p] > a1[p1]) {
			A[i] = a1[p1++];
		}
		else if (a[p] < a1[p1]) {
			A[i] = a[p++];
		}
		if (sizeof(A) / sizeof(int) <= i)
			break;
	}
	for (int i = 0; i < 10 ; i++) {
		printf("%d ", A[i]);
	}

}
void selection_sort(int* n) {
	int min, t = 0, p;
	for (int i = 0; i < 5; i++) {
		min = 99999;
		for (int j = i + 1; j < 5; j++) {
			if (min > n[j]) {
				min = n[j];
				p = j;
			}
		}
		if (min < n[i]) {
			t = n[i];
			n[i] = n[p];
			n[p] = t;
		}
	}
}
void name1(int n,char*name) {
	for (int i = 0; i < n; i++) {
		printf("%s", name);
		printf("\n");
	}
}
int num1(int n) {
	int cnt, r = 1;
	for (int i = 0; i <= 5; i++) {
		int a = n;
		cnt = 0;
		
	}
}
int num(int n) {
	int n1,nu=n;
	int c1=0, c2=0, c3=0, c4=0, c5=0;
	for (int i = 0;nu>0; i++) {
		n1 = nu % 10;
		nu =  nu/ 10;
		switch (n1)
		{
		case 1:c1++; break;
		case 2:c2++; break;
		case 3:c3++; break;
		case 4:c4++; break;
		case 5:c5++; break;
		}
	}
	if (c1 == 1 && c2 == 1 && c3 == 1 && c4 == 1 && c5 == 1)
		return 1;
	else
		return 0;

}
void wordlist(char *str) {
	for (int i = 0;str[i]!=NULL; i++) {
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
	}
	for (int i = 0; str[i] != NULL; i++) {
		if (str[i] == ' ')
		{
			printf("\n");
			i++;
		}
		printf("%c", str[i]);
	}
}
int fun(int n) {
	int s=0;
	for (int i = 1; i <=n - 1; i++)
	{
		s += i % 5;
	}return s;
}
int grede(int score) {
	if (score >= 90 && score <= 100)
		return 'A';
	else if (score >= 80 && score < 90)
		return 'B';
	else if (score >= 70 && score < 80)
		return 'C';
	else if (score >= 60 && score < 70)
		return'D';
	else
		return 'F';
}
int even(int* ptr) {
	int sum=0;
	for (int i = 0; i < 5; i++) 
		if (ptr[i] % 2 == 0)
			sum += ptr[i];
	return sum;
}
void swap(int *x, int *y) {
	int t;
	t = *x;
	*x = *y;
	*y = t;
}