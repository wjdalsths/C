#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h> 
#include <stdbool.h>
#pragma warning(disable: 4996)
#define up 72
#define down 80
#define right 77
#define left 75
#define WIDTH 10 
#define HEIGHT 20 
#define Y_Y 0 
#define X_X 1 
#define NULL 0  
#define false 0 
#define true 1 

int doa; //�׾����� ���׾����� ���, �׾����� 0, ������� 1
int belt_1[50];
int belt_2[50];//0�̸� ��, 1�̸� ��ֹ�
int playerpos;//1�̸� ��, 0�̸� �Ʒ�
int key;

int keyinput();
int getnumber();
void movebelt();
void draw();
int checkplayerpos();

int player[2];

#define MAX_X 40
#define MAX_Y 20
#define LETTER_CNT 1024
struct Node {
	int n;//����
	int x;//������ x��ǥ 
	int y;//������ y��ǥ
	int flag;//ȭ�鿡 �ִ��� ������ 0,1�� 
	int time;//��� �ð�
	int speed;//�ӵ�
};
int randx(int x, int y);

void mainMenu();
void levelMenu();
int gameStart();


void textcolor(int color_number);
int view()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}//Ŀ�� ���ֱ�
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void cursor(int n)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle;
	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void Init(int map[][WIDTH])
{
	player[X_X] = WIDTH - 5;
	player[Y_Y] = HEIGHT - 1;
}
int Nintendo_end()
{
	system("cls");
	Nintendo2();
	gotoxy(24, 4);
	char str12[50] = "�� ����, ���� ���ͺ��� ���� ������ �����ߴ�.";
	int size12;
	size12 = sizeof(str12) / sizeof(str12[0]);
	for (int i = 0; i < size12; i++)
	{
		Sleep(50);
		printf("%c", str12[i]);
	}Sleep(100);
	gotoxy(24, 5);
	char str13[50] = "������ Ʋ�� ���ȿ��� ������ �ϰ� �ʹٴ� ������";
	int size13;
	size13 = sizeof(str13) / sizeof(str13[0]);
	for (int i = 0; i < size13; i++)
	{
		Sleep(50);
		printf("%c", str13[i]);
	}Sleep(100);
	system("cls");
	Nintendo2();
	gotoxy(24, 4);
	char str14[40] = "���� ���� ������ �ϰ������ �ƴϿ���.";
	int size14;
	size14 = sizeof(str14) / sizeof(str14[0]);
	for (int i = 0; i < size14; i++)
	{
		Sleep(50);
		printf("%c", str14[i]);
	}Sleep(100);
	gotoxy(24, 5);
	char str15[30] = "�����ҿ��� ���� ������ ���ϰ�,";
	int size15;
	size15 = sizeof(str15) / sizeof(str15[0]);
	for (int i = 0; i < size15; i++)
	{
		Sleep(50);
		printf("%c", str15[i]);
	}
	gotoxy(24, 6);
	char str16[30] = "�濡 �� ħ�뿡 ������.";
	int size16;
	size16 = sizeof(str16) / sizeof(str16[0]);
	for (int i = 0; i < size16; i++)
	{
		Sleep(50);
		printf("%c", str16[i]);
	}Sleep(100);
	system("cls");
	Nintendo2();
	gotoxy(33, 10);
	char str17[50] = "[���� ���� 1] : ������� ����";
	int size17;
	size17 = sizeof(str17) / sizeof(str17[0]);
	for (int i = 0; i < size17; i++)
	{
		Sleep(50);
		printf("%c", str17[i]);
	}
	system("cls");
	Nintendo2();
	Sleep(100);
	gotoxy(23, 4);
	printf("��������  ��          ��  ��������");
	gotoxy(23, 5);
	printf("      ��        ��          ��  ��            ");
	gotoxy(23, 6);
	printf("      ��        ��          ��  ��            ");
	gotoxy(23, 7);
	printf("      ��        ��          ��  ��            ");
	gotoxy(23, 8);
	printf("      ��        ��          ��  ��            ");
	gotoxy(23, 9);
	printf("      ��        ��          ��  ��            ");
	gotoxy(23, 10);
	printf("      ��        ��������  ��������");
	gotoxy(23, 11);
	printf("      ��        ��          ��  ��            ");
	gotoxy(23, 12);
	printf("      ��        ��          ��  ��            ");
	gotoxy(23, 13);
	printf("      ��        ��          ��  ��            ");
	gotoxy(23, 14);
	printf("      ��        ��          ��  ��            ");
	gotoxy(23, 15);
	printf("      ��        ��          ��  ��            ");
	gotoxy(23, 16);
	printf("      ��        ��          ��  ��������");
	gotoxy(23, 26);
	printf("��������  ���         ��  ������    ");
	gotoxy(23, 27);
	printf("��              ���         ��  ��       ��   ");
	gotoxy(23, 28);
	printf("��              �� ��        ��  ��        ��  ");
	gotoxy(23, 29);
	printf("��              ��  ��       ��  ��         �� ");
	gotoxy(23, 30);
	printf("��              ��   ��      ��  ��          ��");
	gotoxy(23, 31);
	printf("��              ��    ��     ��  ��          ��");
	gotoxy(23, 32);
	printf("��������  ��     ��    ��  ��          ��");
	gotoxy(23, 33);
	printf("��              ��      ��   ��  ��          ��");
	gotoxy(23, 34);
	printf("��              ��       ��  ��  ��         �� ");
	gotoxy(23, 35);
	printf("��              ��        �� ��  ��        ��  ");
	gotoxy(23, 36);
	printf("��              ��         ���  ��       ��   ");
	gotoxy(23, 37);
	printf("��������  ��         ���  ������    ");
	gotoxy(50, 42);
	exit(0);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	view();
	Nintendo();
	return 0;
}
int start()
{
	view();
	char n;
	int fuc_check = 0;
	gotoxy(37, 10);
	Sleep(100);
	char str1[30] = "ȯ���մϴ�.";
	int size;
	size = sizeof(str1) / sizeof(str1[0]);
	for (int i = 0; i < size; i++)
	{
		Sleep(35);
		printf("%c", str1[i]);
	}
	Sleep(150);
	system("cls");
	Nintendo1();
	gotoxy(37, 10);
	char str2[30] = "�����Ͻðڽ��ϱ�?";
	int size1;
	size1 = sizeof(str2) / sizeof(str2[0]);
	for (int i = 0; i < size1; i++)
	{
		Sleep(35);
		printf("%c", str2[i]);
	}
	Sleep(150);
	gotoxy(37, 11);
	char str3[30] = "(S)��ư�� �����ÿ�.";
	int size2;
	size2 = sizeof(str3) / sizeof(str3[0]);
	for (int i = 0; i < size2; i++)
	{
		Sleep(35);
		printf("%c", str3[i]);
	}
	gotoxy(37, 12);
	scanf("%c", &n);
	if (!(n == 's' || n == 'S'))
	{
		fuc_check = game(1);
	}
	while (1)
	{
		if (fuc_check == 1)
		{
			introduction();
			system("cls");
		}
		else if (fuc_check == 2)
		{
			play_the_game();
			system("cls");
		}
		else if (fuc_check == 3)
		{
			Sources();
			system("cls");
		}

		fuc_check = game(1);
	}
}
int Nintendo1()
{
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                                                                                         ��\n");
	printf("��                                                                                         ��\n");
	printf("��                   ������������������������������������������������������������������������������������������������������                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��     ��  ��  ��    ��                                                 ��     ��  ��  ��    ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��     ��  ��  ��    ��                                                 ��     ��  ��  ��    ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ������������������������������������������������������������������������������������������������������                   ��\n");
	printf("��                                                                                         ��\n");
	printf("��                                                                                         ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��    ��                                                                               �� || ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                                                                                         ��\n");
	printf("��                                                                                         ��\n");
	printf("��                   ������������������������������������������������������������������������������������������������������                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��       ��������        ��\n");
	printf("��     ������������        ��                                                 ��       �� X��        ��\n");
	printf("��     �� �� ��        ��                                                 ��       ��������        ��\n");
	printf("��     ��    ��        ��                                                 ��   ��������    ��������    ��\n");
	printf("�� ����������    ����������    ��                                                 ��   �� Y��    �� A��    ��\n");
	printf("�� �� ��       �榭    ��                                                 ��   ��������    ��������    ��\n");
	printf("�� ����������    ����������    ��                                                 ��       ��������        ��\n");
	printf("��     ��    ��        ��                                                 ��       �� B��        ��\n");
	printf("��     �� �� ��        ��                                                 ��       ��������        ��\n");
	printf("��     ������������        ��                                                 �� ��return          ��\n");
	printf("��                   ��                                                 �� �� ����           ��\n");
	printf("��                   ������������������������������������������������������������������������������������������������������                   ��\n");
	printf("��                                                                                         ��\n");
	printf("��                                                                                         ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	memo();
	gotoxy(50, 42);
}
int Nintendo2()
{
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                                                                                         ��\n");
	printf("��                                                                                         ��\n");
	printf("��                   ������������������������������������������������������������������������������������������������������                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��     ��  ��  ��    ��                                                 ��     ��  ��  ��    ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��     ��  ��  ��    ��                                                 ��     ��  ��  ��    ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ������������������������������������������������������������������������������������������������������                   ��\n");
	printf("��                                                                                         ��\n");
	printf("��                                                                                         ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��    ��                                                                               �� || ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                                                                                         ��\n");
	printf("��                                                                                         ��\n");
	printf("��                   ������������������������������������������������������������������������������������������������������                   ��\n");
	printf("��                   ��                                                 ��                   ��\n");
	printf("��                   ��                                                 ��       ��������        ��\n");
	printf("��     ������������        ��                                                 ��       �� X��        ��\n");
	printf("��     �� �� ��        ��                                                 ��       ��������        ��\n");
	printf("��     ��    ��        ��                                                 ��   ��������    ��������    ��\n");
	printf("�� ����������    ����������    ��                                                 ��   �� Y��    �� A��    ��\n");
	printf("�� �� ��       �榭    ��                                                 ��   ��������    ��������    ��\n");
	printf("�� ����������    ����������    ��                                                 ��       ��������        ��\n");
	printf("��     ��    ��        ��                                                 ��       �� B��        ��\n");
	printf("��     �� �� ��        ��                                                 ��       ��������        ��\n");
	printf("��     ������������        ��                                                 �� ��return          ��\n");
	printf("��                   ��                                                 �� �� ����           ��\n");
	printf("��                   ������������������������������������������������������������������������������������������������������                   ��\n");
	printf("��                                                                                         ��\n");
	printf("��                                                                                         ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	gotoxy(50, 42);
}
int memo()
{
	char n;
	gotoxy(21, 26);
	printf("��������������������������������������������������������������������������������������������������\n");
	gotoxy(21, 27);
	printf("��                                               ��\n");
	gotoxy(21, 28);
	printf("��                                               ��\n");
	gotoxy(21, 29);
	printf("��������������������������������������������������������������������������������������������������\n");
	gotoxy(39, 27);
	printf("������Ʈ �Ұ���");
	gotoxy(21, 30);
	printf("��������������������������������������������������������������������������������������������������\n");
	gotoxy(21, 31);
	printf("��                                               ��\n");
	gotoxy(21, 32);
	printf("��                                               ��\n");
	gotoxy(21, 33);
	printf("��������������������������������������������������������������������������������������������������\n");
	gotoxy(45, 32);
	printf("����");
	gotoxy(21, 34);
	printf("��������������������������������������������������������������������������������������������������\n");
	gotoxy(21, 35);
	printf("��                                               ��\n");
	gotoxy(21, 36);
	printf("��                                               ��\n");
	gotoxy(21, 37);
	printf("��������������������������������������������������������������������������������������������������\n");
	gotoxy(45, 36);
	printf("��ó");
	gotoxy(50, 42);
}
int Nintendo()
{
	view();
	int Loop = 0;
	gotoxy(48, 10);
	printf("����������������������������������������\n");
	gotoxy(48, 11);
	printf("��                  ��\n");
	gotoxy(48, 12);
	printf("����������������������������������������\n");
	gotoxy(50, 11);
	char str[30] = "NINTENDO PROJECT";
	int size;
	size = sizeof(str) / sizeof(str[0]);
	for (int i = 0; i < size; i++)
	{
		Sleep(50);
		printf("%c", str[i]);
	}
	Sleep(150);
	system("cls");
	Nintendo1();
	memo();
	start();
}
int game(int z)
{
	int key;
	int x = 34, y = 27, check = 1;
	int j = 0;

	if (z == 1) {
		gotoxy(37, 12);
		char str[30] = "����â�� �����ϰڽ��ϴ�.";
		int size3;
		size3 = sizeof(str) / sizeof(str[0]);
		for (int i = 0; i < size3; i++)
		{
			Sleep(35);
			printf("%c", str[i]);

		}
		system("cls");
		Nintendo1();
		while (1)
		{
			cursor(0);
			gotoxy(x, y);
			printf(">>");
			key = getch();
			if (key == 224)
			{
				key = getch();
			}
			if (key == up && y > 27)
			{
				check--;
				y -= 4;
				gotoxy(x, y + 4); printf("  ");
				gotoxy(x, y); printf(">>");
			}
			else if (key == down && y < 35)
			{
				check++;

				y += 4;
				gotoxy(x, y - 4); printf("  ");
				gotoxy(x, y); printf(">>");
			}
			else if (key == right)
			{
				return check;
			}
		}
	}
}
int introduction()
{
	char e;
	system("cls");
	Nintendo2();
	gotoxy(22, 4);
	printf("������Ʈ �� : Nintendo game");
	gotoxy(22, 5);
	printf("�� �Ұ� : (���� ������ : ������,������)");
	gotoxy(22, 6);
	printf("������Ʈ �о� : ����");
	gotoxy(22, 7);
	printf("������Ʈ ��� : 2���� ���ϱ� ����, ���ϸ� ����");
	gotoxy(22, 8);
	printf("������Ʈ ������ : ����â�� �����Ͽ�����");
	gotoxy(40, 9);
	printf("�ѹ��� �����Ͽ��� ��(�ذ�)");
	gotoxy(45, 15);
	printf("���� ��ư : (e/E)");
	gotoxy(45, 16);
	printf("return ��ư : (r/R)");
	gotoxy(21, 26);
	scanf(" %c", &e);
	if (e == 'e' || e == 'E')
	{
		gotoxy(50, 42);
		exit(0);
	}
	else if (e == 'r' || e == 'R')
	{
		system("cls");
		game(0);
	}
}
int play_the_game()
{
	system("cls");
	Nintendo2();
	int fuc_check;
	fuc_check = Selection_Window(1);
	while (1)
	{
		if (fuc_check == 1)
		{
			Avoid_game();
			system("cls");
		}
		else if (fuc_check == 2)
		{
			nintendo_game();
			system("cls");
		}
		fuc_check = Selection_Window(1);
	}
}
int Selection_Window()
{
	system("cls");
	Nintendo2();
	int key;
	int x = 26, y = 12, check = 1;
	int j = 0;
	gotoxy(24, 11);
	printf("������������������������������������������\n");
	gotoxy(24, 12);
	printf("��                   ��\n");
	gotoxy(24, 13);
	printf("������������������������������������������");
	gotoxy(29, 12);
	printf("���ϱ� ����");
	gotoxy(50, 11);
	printf("����������������������������������������\n");
	gotoxy(50, 12);
	printf("��                  ��\n");
	gotoxy(50, 13);
	printf("����������������������������������������");
	gotoxy(56, 12);
	printf("Pokemon ����");
	while (1)
	{
		cursor(0);
		gotoxy(x, y);
		printf(">>");
		key = getch();
		if (key == 224)
		{
			key = getch();
		}
		if (key == right && x < 54)
		{
			check++;
			x += 28;
			gotoxy(x - 28, y); printf("  ");
			gotoxy(x, y); printf(">>");
		}
		else if (key == left && x > 26)
		{
			check--;
			x -= 28;
			gotoxy(x + 28, y); printf("  ");
			gotoxy(x, y); printf(">>");
		}
		else if (key == down)
		{
			return check;
		}
	}
}
int Sources()
{
	char e;
	system("cls");
	Nintendo2();
	gotoxy(22, 4);
	printf("��ó : Google,yotube");
	gotoxy(22, 5);
	gotoxy(45, 15);
	printf("���� ��ư : (e/E)");
	gotoxy(45, 16);
	printf("return ��ư : (r/R)");
	gotoxy(21, 26);
	scanf(" %c", &e);
	if (e == 'e' || e == 'E')
	{
		gotoxy(50, 42);
		exit(0);
	}
	else if (e == 'r' || e == 'R')
	{
		system("cls");
		game(0);
	}
}
int Avoid_game()
{
	system("cls");
	Nintendo2();
	gotoxy(50, 11);
	GameMenu();
}
int nintendo_game()
{
	system("cls");
	Nintendo2();
	gotoxy(50, 11);
	GameMenu1();
}
int GameMenu()
{
	system("cls");
	Nintendo2();
	int s;
	gotoxy(35, 8);
	printf("===���ϱ� ����====\n");
	gotoxy(35, 9);
	printf("  1.���� ����(���ϱ�1)\n");
	gotoxy(35, 10);
	printf("  2.���� ����(���ϱ�2)\n");
	gotoxy(35, 11);
	printf("  3.���� ����\n");
	gotoxy(35, 12);
	printf("  4.���� ����â ���Ʊ��\n");
	gotoxy(35, 13);
	scanf("%d", &s);
	if (s == 1)
	{
		int i, j;
		int nowtime;
		int pasttime;
		i = 0;
		j = 0;
		//�׾����� ���׾����� ���, �׾����� 0, ������� 1
		belt_1[0] = 0;
		belt_2[0] = 0;
		belt_1[1] = 0;
		belt_2[1] = 0;
		srand((unsigned)time(NULL));
		for (i = 3; i < 50; i++) {
			belt_1[i] = getnumber();
			belt_2[i] = getnumber();
			if (belt_1[i] == belt_2[i]) i--;
		}

		while (1) {
			nowtime = GetTickCount();
			pasttime = GetTickCount();
			while (nowtime - pasttime <= 500)
			{
				key = keyinput();
				if (key == 38) playerpos = 1;
				if (key == 40) playerpos = 0;
				draw();//ȭ�鿡 �÷��̾�� ���� ����Ѵ�.
				nowtime = GetTickCount();
			}
			movebelt();//���� ���� �����Ѵ�
			draw();//�� �� ������ ���
			doa = checkplayerpos();//�÷��̾��� ���� üũ�Ѵ�. ���� ��ֹ��� �÷��̾ ���� ��ġ�� �ִٸ� break
			if (doa == 0) break;//�̰� ����ϸ� �������� ��� �����ص���
		}
		gotoxy(33, 15);
		printf("�ε������ȴ�!");
		Sleep(1000);
		textcolor(7);
	}
	if (s == 2)
	{

		int select;
		int tmpScore = 0;
		int maxScore = 0;

		while (1)
		{
			system("cls");
			mainMenu();
			fflush(stdin); //���� �����ִ°�
			scanf("%d", &select);
			system("cls");

			switch (select)
			{
			case 1:
				tmpScore = gameStart();
				break;
			case 2:
				if (maxScore < tmpScore) maxScore = tmpScore;
				printf("  �ְ� ������ %d �Դϴ� \n", maxScore);
				system("pause");
				break;
			case 0:
				textcolor(7);
				return;
			default:
				break;
			}
		}
	}
	if (s == 3)
	{
		gotoxy(50, 42);
		exit(0);
	}
	else if (s == 4)
	{
		avoid_gameplay();
	}
}
int keyinput() {
	int nowkey;
	int nowtimeinkey;
	int pasttimeinkey;
	nowkey = 0;
	pasttimeinkey = GetTickCount();
	nowtimeinkey = GetTickCount();
	while (nowtimeinkey - pasttimeinkey <= 1000) {

		if (GetAsyncKeyState(38))
		{
			nowkey = 38;
			fflush(stdin);
		}
		if (GetAsyncKeyState(40))
		{
			nowkey = 40;
			fflush(stdin);
		}
		nowtimeinkey = GetTickCount();
	}

	return nowkey;
}
int getnumber() {
	int i;

	i = rand();
	if (i <= 32000) return 0;
	else return 1;
}
void movebelt() {
	int temp1, temp2;
	int i, j;
	for (i = 0; i < 49; i++) {
		j = i + 1;
		temp1 = belt_1[j];
		belt_1[j] = belt_1[i];
		belt_1[i] = temp1;
		temp2 = belt_2[j];
		belt_2[j] = belt_2[i];
		belt_2[i] = temp2;
	}
}
void draw() {
	int i;
	system("cls");
	Nintendo2();
	gotoxy(30, 4);
	printf("�� ���ϱ� ����!\n");;
	gotoxy(30, 5);
	printf("��,�Ʒ� ��ư���� ������ �� �ִ�.\n\n");;
	textcolor(3);
	gotoxy(30, 7);
	if (playerpos == 1)
	{
		printf("��");
	}
	else {
		if (belt_1[0] == 0) {
			printf("-");
		}
		if (belt_1[0] == 1)
		{
			printf("o");
		}
	}
	for (i = 1; i < 30; i++) {
		if (belt_1[i] == 0)
		{
			printf("-");
		}
		if (belt_1[i] == 1)
		{
			printf("o");
		}
	}
	printf("\n\n\n");
	gotoxy(30, 10);
	if (playerpos == 0)
	{
		printf("��");
	}
	else {
		if (belt_2[0] == 0)
		{
			printf("-");
		}
		if (belt_2[0] == 1)
		{
			printf("o");
		}
	}
	for (i = 1; i < 30; i++) {

		if (belt_2[i] == 0)
		{
			printf("-");
		}
		if (belt_2[i] == 1)
		{
			printf("o");
		}
	}
}
int checkplayerpos() {
	if (playerpos == 1) {
		if (belt_1[0] == 1) return 0;
	}
	else {
		if (belt_2[0] == 1) return 0;
	}
	return 1;
}
void mainMenu()
{
	Nintendo2();
	textcolor(11);
	gotoxy(25, 4);
	puts("������������������������������������������������������������������");
	gotoxy(25, 5);
	puts("��         ���� ���ϱ� ����      ��");
	gotoxy(25, 6);
	puts("��                               ��");
	gotoxy(25, 7);
	puts("��          0. ��     ��         ��");
	gotoxy(25, 8);
	puts("��                               ��");
	gotoxy(25, 9);
	puts("��          1. ���� �÷���       ��");
	gotoxy(25, 10);
	puts("��                               ��");
	gotoxy(25, 11);
	puts("��          2. �ְ� ����         ��");
	gotoxy(25, 12);
	puts("��                               ��");
	gotoxy(25, 13);
	puts("������������������������������������������������������������������");
	gotoxy(25, 14);
	printf(" Select > ");
}
void levelMenu()
{
	Nintendo2();
	textcolor(10);
	gotoxy(25, 4);
	puts("������������������������������������������������������������");
	gotoxy(25, 5);
	puts("��         ���̵� ����        ��");
	gotoxy(25, 6);
	puts("��                            ��");
	gotoxy(25, 7);
	puts("��         0. ����            ��");
	gotoxy(25, 8);
	puts("��                            ��");
	gotoxy(25, 9);
	puts("��         1. ����            ��");
	gotoxy(25, 10);
	puts("��                            ��");
	gotoxy(25, 11);
	puts("��         2. �߰�            ��");
	gotoxy(25, 12);
	puts("��                            ��");
	gotoxy(25, 13);
	puts("��         3. �����          ��");
	gotoxy(25, 14);
	puts("��                            ��");
	gotoxy(25, 15);
	puts("������������������������������������������������������������");
	gotoxy(25, 16);
	printf(" Select > ");
}
int gameStart()
{
	view();
	int select;
	struct Node letter[LETTER_CNT];
	int i;
	int randVar, speed1, speed2;
	char ch;
	int playerX = 22, playerY = 16;
	int score = 0;

	while (1)//�ӵ�����
	{
		levelMenu();
		fflush(stdin); scanf("%d", &select);
		system("cls");

		if (select == 1)
		{
			randVar = 20;
			speed1 = 10;
			speed2 = 20;
			break;
		}
		else if (select == 2)
		{
			randVar = 10;
			speed1 = 5;
			speed2 = 10;
			break;
		}
		else if (select == 3)
		{
			randVar = 5;
			speed1 = 2;
			speed2 = 5;
			break;
		}
		else if (select == 0) return 0;
		else     continue;
	}

	for (i = 0; i < LETTER_CNT; i++) letter[i].flag = 0;
	system("cls");
	Nintendo2();
	while (1)//���, ���, ����Ʈ, ������ ��ӹݺ�
	{
		if (randx(0, randVar) == 0)
		{
			for (i = 0; i < LETTER_CNT; i++)
			{
				if (letter[i].flag == 0)
				{
					letter[i].n = randx(1, 9);
					letter[i].flag = 1;
					letter[i].x = randx(21, 49);
					letter[i].y = 4;
					letter[i].time = randx(50, 200);
					letter[i].speed = randx(speed1, speed2);
					break;
				}
			}
		}

		for (i = 0; i < LETTER_CNT; i++)
		{
			if (letter[i].flag == 1)
			{
				if (--letter[i].time == 0)
				{
					letter[i].time = letter[i].speed;

					gotoxy(letter[i].x, letter[i].y);
					printf("%d", letter[i].n);
					/*gotoxy(letter[i].x, letter[i].y);
					printf(" ");*/
					printf("\b ");//�齺���̽���
					gotoxy(letter[i].x, ++letter[i].y);
					printf("%d", letter[i].n);

					if (letter[i].y == 16)
					{
						printf("\b ");
						letter[i].flag = 0;
						if (letter[i].x == playerX || letter[i].x == playerX + 1)
						{
							gotoxy(30, 26);
							system("pause");
							return score;

						}
						else
						{
							score++;
							gotoxy(40, 26);
							printf("���� : %d ", score);
						}
					}
				}
			}
		}
		Sleep(5);

		gotoxy(playerX, playerY);
		printf("��");

		if (kbhit())//kbhit ���ȴ��� �ȴ��ȴ��� ����
		{
			ch = getch();
			switch (ch)
			{
			case 75:
				if (playerX > 22)
				{

					playerX--;
					gotoxy(playerX, playerY);
					printf("��");
					gotoxy(playerX + 1, playerY);
					printf("  ");
				}
				break;
			case 77:
				if (playerX < 66)
				{

					playerX++;
					gotoxy(playerX, playerY);
					printf("��");
					gotoxy(playerX - 1, playerY);
					printf("  ");
				}
				break;
			default:
				break;
			}
		}
	}
}

int randx(int x, int y)
{
	static int flag = 0;
	int ra;
	if (flag == 0)
	{
		srand(time(NULL));
		rand();
		flag = 1;
	}
	ra = rand() % y + x;
	return ra;
}
void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
int avoid_gameplay()
{
	int e;
	gotoxy(45, 15);
	printf("���� ��ư : (e/E)");
	gotoxy(45, 16);
	printf("return ��ư : (r/R)");
	gotoxy(21, 26);
	scanf(" %c", &e);
	if (e == 'e' || e == 'E')
	{
		gotoxy(50, 42);
		exit(0);
	}
	else if (e == 'r' || e == 'R')
	{
		system("cls");
		game(0);
	}
}
int nintendo_gameplay()
{
	int e;
	gotoxy(45, 15);
	printf("���� ��ư : (e/E)");
	gotoxy(45, 16);
	printf("return ��ư : (r/R)");
	gotoxy(21, 26);
	scanf(" %c", &e);
	if (e == 'e' || e == 'E')
	{
		gotoxy(50, 42);
		exit(0);
	}
	else if (e == 'r' || e == 'R')
	{
		system("cls");
		game(0);
	}
}
int GameMenu1()
{
	int n;
	system("cls");
	Nintendo2();
	gotoxy(35, 7);
	printf("-------���ϸ�--------\n");
	gotoxy(33, 8);
	printf("  1.���� ����â ���Ʊ��\n");
	gotoxy(33, 9);
	printf("  2. ���ϸ� ���� â ����\n");
	gotoxy(33, 10);
	printf("  3. ���� ����\n");
	gotoxy(35, 11);
	scanf("%d", &n);
	if (n == 1)
	{
		nintendo_gameplay();
	}
	else if (n == 2)
	{
		system("cls");
		pokemon();
	}
	else
	{
		gotoxy(50, 42);
		exit(0);
	}
}
int pokemon()
{
	char a[30];
	char c[30];
	int level;
	int b;
	int n;
	int f;
	int t;
	int menu;
	system("cls");
	Nintendo2();
	gotoxy(30, 8);
	printf("[1.���ο� ������ �����Ͻðڽ��ϱ�?]");
	gotoxy(30, 9);
	printf("[2.�����ϱ�]");
	gotoxy(30, 10);
	scanf("%d", &n);
	if (n == 1)
	{
		system("cls");
		Nintendo2();
		Sleep(100);
		gotoxy(33, 10);
		printf("������ �ҷ��ɴϴ�.\n");
		Sleep(100);
		system("cls");
		Nintendo2();
		gotoxy(33, 10);
		printf("������ �ҷ��ɴϴ�..\n");
		system("cls");
		Nintendo2();
		gotoxy(33, 10);
		printf("������ �ҷ��ɴϴ�...\n");
		Sleep(100);
		system("cls");
		Nintendo2();
		gotoxy(33, 10);
		printf("������ �ҷ��ɴϴ�....\n");
		Sleep(100);
		system("cls");
		Nintendo2();
		gotoxy(33, 10);
		printf("������ �ҷ��ɴϴ�.....\n");
		Sleep(100);
		system("cls");
		Nintendo2();
		b = 1;
		char print_temp[200];
		char file_path[200];
		FILE* f;
		sprintf(file_path, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���ڻ�.txt");
		f = fopen(file_path, "r");
		gotoxy(100, 1);
		for (int i = 0; i < 40; i++)
		{
			gotoxy(100, i + 1);
			fgets(print_temp, 200, f);
			printf("%s", print_temp);
		}
		gotoxy(33, 15);
		char str[30] = "�ȳ� ���� ���ڻ��� ��";
		int size;
		size = sizeof(str) / sizeof(str[0]);
		for (int i = 0; i < size; i++)
		{
			Sleep(35);
			printf("%c", str[i]);
		}
		system("cls");
		Nintendo2();
		char print_temp1[200];
		char file_path1[200];
		FILE* f1;
		sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���ڻ�.txt");
		f1 = fopen(file_path1, "r");
		gotoxy(100, 1);
		for (int i = 0; i < 40; i++)
		{
			gotoxy(100, i + 1);
			fgets(print_temp, 200, f1);
			printf("%s", print_temp);
		}
		gotoxy(33, 15);
		char str1[30] = "��ε� ���ϸ� �ڻ��� �θ���";
		int size1;
		size1 = sizeof(str1) / sizeof(str1[0]);
		for (int i = 0; i < size1; i++)
		{
			Sleep(35);
			printf("%c", str1[i]);
		}
		Sleep(200);
		system("cls");
		Nintendo2();
		gotoxy(33, 13);
		char str2[30] = "�ʿ� ���� �˾� ����?";
		int size2;
		size2 = sizeof(str2) / sizeof(str2[0]);
		for (int i = 0; i < size2; i++)
		{
			Sleep(35);
			printf("%c", str2[i]);
		}
		char print_temp2[200];
		char file_path2[200];
		FILE* f2;
		sprintf(file_path2, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\1.txt");
		f2 = fopen(file_path2, "r");
		gotoxy(100, 1);
		for (int i = 0; i < 40; i++)
		{
			gotoxy(100, i + 1);
			fgets(print_temp, 200, f2);
			printf("%s", print_temp);
		}
		gotoxy(33, 14);
		char str3[30] = "�ʴ� ���ڴ� �ƴ� ���ڴ�?";
		int size3;
		size3 = sizeof(str3) / sizeof(str3[0]);
		for (int i = 0; i < size3; i++)
		{
			Sleep(35);
			printf("%c", str3[i]);
		}
		gotoxy(33, 15);
		printf("1.���� 2.����");
		gotoxy(33, 16);
		scanf("%d", &t);
		system("cls");
		Nintendo2();
		if (t == 1)
		{
			char print_temp[200];
			char file_path[200];
			FILE* f;
			sprintf(file_path, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\����.txt");
			f = fopen(file_path, "r");
			gotoxy(100, 1);
			for (int i = 0; i < 40; i++)
			{
				gotoxy(100, i + 1);
				fgets(print_temp, 200, f);
				printf("%s", print_temp);
			}
			gotoxy(33, 15);
			char str3[15] = "���ڷα���?";
			int size3;
			size3 = sizeof(str3) / sizeof(str3[0]);
			for (int i = 0; i < size3; i++)
			{
				Sleep(50);
				printf("%c", str3[i]);
			}
			Sleep(200);
		}
		if (t == 2)
		{
			char print_temp[200];
			char file_path[200];
			FILE* f;
			sprintf(file_path, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\����.txt");
			f = fopen(file_path, "r");
			gotoxy(100, 1);
			for (int i = 0; i < 35; i++)
			{
				gotoxy(100, i + 1);
				fgets(print_temp, 200, f);
				printf("%s", print_temp);
			}
			gotoxy(33, 15);
			char str3[15] = "���ڷα���?";
			int size3;
			size3 = sizeof(str3) / sizeof(str3[0]);
			for (int i = 0; i < size3; i++)
			{
				Sleep(35);
				printf("%c", str3[i]);
			}
			Sleep(200);
		}
		char n[30];
		system("cls");
		Nintendo2();
		gotoxy(33, 13);
		char str10[30] = "���� �̸��� �����̴�?";
		int size10;
		size10 = sizeof(str10) / sizeof(str10[0]);
		for (int i = 0; i < size10; i++)
		{
			Sleep(35);
			printf("%c", str10[i]);
		}
		gotoxy(33, 14);
		scanf("%s", n);
		gotoxy(33, 15);
		printf("���� �̸��� %s�̱���", n);
		Sleep(1000);
		system("cls");
		Nintendo2();
		char print_temp3[200];
		char file_path3[200];
		FILE* f3;
		sprintf(file_path, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���ϸ�.txt");
		f3 = fopen(file_path, "r");
		gotoxy(100, 1);
		for (int i = 0; i < 20; i++)
		{
			gotoxy(100, i + 1);
			fgets(print_temp, 200, f3);
			printf("%s", print_temp);
		}
		gotoxy(30, 15);
		char str7[30] = "�ʿ� �Բ��� ���ϸ��� ��󺼷�?";
		int size7;
		size7 = sizeof(str7) / sizeof(str7[0]);
		for (int i = 0; i < size7; i++)
		{
			Sleep(35);
			printf("%c", str7[i]);
		}
		gotoxy(39, 28);
		printf("[1]���̸�");
		gotoxy(39, 32);
		printf("[2]���α�");
		gotoxy(39, 36);
		printf("[3]�̻��ؾ�");
		gotoxy(39, 37);
		scanf("%d", &menu);
		if (menu == 1)
		{
			system("cls");
			Nintendo2();
			char print_temp[200];
			char file_path[200];
			FILE* f;
			sprintf(file_path, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���̸�.txt");
			f = fopen(file_path, "r");
			gotoxy(100, 1);
			for (int i = 0; i < 30; i++)
			{
				gotoxy(100, i + 1);
				fgets(print_temp, 200, f);
				printf("%s", print_temp);
			}
			gotoxy(33, 15);
			char str8[30] = "���̸��� �����߱���!";
			int size8;
			size8 = sizeof(str8) / sizeof(str8[0]);
			for (int i = 0; i < size8; i++)
			{
				Sleep(35);
				printf("%c", str8[i]);
			}
		}
		else if (menu == 2)
		{
			system("cls");
			Nintendo2();
			char print_temp[200];
			char file_path[200];
			FILE* f;
			sprintf(file_path, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���α�.txt");
			f = fopen(file_path, "r");
			gotoxy(100, 1);
			for (int i = 0; i < 30; i++)
			{
				gotoxy(100, i + 1);
				fgets(print_temp, 200, f);
				printf("%s", print_temp);
			}
			gotoxy(33, 15);
			char str9[30] = "���α⸦ �����߱���!";
			int size9;
			size9 = sizeof(str9) / sizeof(str9[0]);
			for (int i = 0; i < size9; i++)
			{
				Sleep(35);
				printf("%c", str9[i]);
			}
		}
		else if (menu == 3)
		{
			system("cls");
			Nintendo2();
			char print_temp[200];
			char file_path[200];
			FILE* f;
			sprintf(file_path, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\�̻��ؾ�.txt");
			f = fopen(file_path, "r");
			gotoxy(100, 1);
			for (int i = 0; i < 30; i++)
			{
				gotoxy(100, i + 1);
				fgets(print_temp, 200, f);
				printf("%s", print_temp);
			}
			gotoxy(33, 15);
			char str10[30] = "�̻��ؾ��� �����߱���!";
			int size10;
			size10 = sizeof(str10) / sizeof(str10[0]);
			for (int i = 0; i < size10; i++)
			{
				Sleep(35);
				printf("%c", str10[i]);
			}
		}
	}
	else
	{
		exit(0);
	}
	if (b == 1)
	{
		int u;
		system("cls");
		Nintendo2();
		gotoxy(33, 13);
		char str11[30] = "������ �� �غ� �Ǿ���?";
		int size11;
		size11 = sizeof(str11) / sizeof(str11[0]);
		for (int i = 0; i < size11; i++)
		{
			Sleep(35);
			printf("%c", str11[i]);
		}
		gotoxy(33, 14);
		printf("[1.��] [2.�ƴϿ�]");
		gotoxy(33, 15);
		scanf("%d", &u);
		if (u == 1)
		{
			int cash;
			int monsterball;
			int vulnerary;
			system("cls");
			Nintendo2();
			gotoxy(27, 13);
			char str11[50] = "������ �ʿ��� ĳ��,���ͺ�,��ó���� �ְڳ�";
			int size11;
			size11 = sizeof(str11) / sizeof(str11[0]);
			for (int i = 0; i < size11; i++)
			{
				Sleep(35);
				printf("%c", str11[i]);
			}
			cash = 10000;
			monsterball = 5;
			vulnerary = 5;
			gotoxy(33, 14);
			Sleep(1000);
			printf("ĳ�� %d�� �������ϴ�", cash);
			gotoxy(33, 15);
			Sleep(1000);
			printf("���ͺ� %d���� �������ϴ�", monsterball);
			gotoxy(33, 16);
			Sleep(1000);
			printf("��ó�� %d���� �������ϴ�", vulnerary);
			Sleep(1000);
			system("cls");
			Nintendo2();
			gotoxy(33, 4);
			printf("------player����-----");
			gotoxy(33, 5);
			printf("�̸� : ooo");
			gotoxy(33, 6);
			printf("ĳ�� : %d��", cash);
			gotoxy(33, 7);
			printf("���� : 0��");
			gotoxy(33, 8);
			printf("���ͺ� : %d��", monsterball);
			gotoxy(33, 9);
			printf("��ó�� : %d��", vulnerary);
			gotoxy(33, 10);
			printf("------���� ���ϸ� ����-----");
			if (menu == 1)
			{
				gotoxy(33, 11);
				printf("�̸� : ���̸�");
				gotoxy(33, 12);
				printf("HP : 100");
				gotoxy(33, 13);
				printf("power : 20");
			}
			if (menu == 2)
			{
				gotoxy(33, 11);
				printf("�̸� : ���α�");
				gotoxy(33, 12);
				printf("HP : 100");
				gotoxy(33, 13);
				printf("power : 20");
			}
			if (menu == 3)
			{
				gotoxy(33, 11);
				printf("�̸� : �̻��ؾ�");
				gotoxy(33, 12);
				printf("HP : 100");
				gotoxy(33, 13);
				printf("power : 20");
			}
			Sleep(2000);
			system("cls");
			Nintendo2();
			gotoxy(33, 13);
			int n;
			char str[50] = "��ſ� ������ �Ǳ⸦ ���ڳ�.^^";
			int size;
			size = sizeof(str) / sizeof(str[0]);
			for (int i = 0; i < size11; i++)
			{
				Sleep(35);
				printf("%c", str[i]);
			}
		r:
			gotoxy(33, 14);
			printf("������ �̵��Ͻðڽ��ϱ�?");
			gotoxy(33, 15);
			printf("(1)yes,(2)no");
			gotoxy(33, 16);
			scanf("%d", &n);
			if (n == 1)
			{
				char u;
			e:
				system("cls");
				Nintendo2();
				gotoxy(21, 4);
				printf("-------------------------------------------------");
				gotoxy(23, 5);
				printf("(A) ���ϸ� ���� (B) ����� (X) ���� (Y) ü����");
				gotoxy(40, 11);
				printf("�� X ��");
				gotoxy(40, 12);
				printf("Y �� A");
				gotoxy(40, 13);
				printf("�� B ��");
				gotoxy(40, 14);
				scanf(" %c", &u);
				if (u == 'a' || u == 'A')
				{
					system("cls");
					Nintendo2();
					Sleep(100);
					gotoxy(33, 10);
					printf("���ϸ� ���� �̵���.\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("���ϸ� ���� �̵���..\n");
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("���ϸ� ���� �̵���...\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("���ϸ� ���� �̵���....\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("���ϸ� ���� �̵���.....\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					gotoxy(33, 11);
					printf("���ϸ� ���� ����");
					Sleep(500);
					system("cls");
					Nintendo2();
					char print_temp[200];
					char file_path[200];
					FILE* f;
					sprintf(file_path, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���ϸ� ����.txt");
					f = fopen(file_path, "r");
					for (int i = 0; i < 25; i++)
					{
						gotoxy(100, i + 1);
						fgets(print_temp, 200, f);
						printf("%s", print_temp);
					}
					char c;
					gotoxy(32, 11);
					printf("���ϸ��� ȸ���Ͻðڽ��ϱ�?");
					gotoxy(33, 12);
					printf("(y/n)");
					gotoxy(33, 13);
					scanf(" %c", &c);
					if (c == 'y')
					{
						system("cls");
						Nintendo2();
						Sleep(100);
						gotoxy(33, 10);
						printf("��ó ȸ����.\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("��ó ȸ����..\n");
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("��ó ȸ����...\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("��ó ȸ����....\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("��ó ȸ����.....\n");
						system("cls");
						Nintendo2();
						gotoxy(33, 15);
						int n;
						char str[50] = "����� ���ϸ��� ��� ȸ��Ǿ����ϴ�.";
						int size;
						size = sizeof(str) / sizeof(str[0]);
						for (int i = 0; i < size11; i++)
						{
							Sleep(35);
							printf("%c", str[i]);
						}
						goto e;
					}
					if (c == 'n')
					{
						system("cls");
						Nintendo2();
						gotoxy(33, 15);
						printf("������ �̿����ּ���..");
						Sleep(1000);
						goto e;
					}
				}
				else if (u == 'b' || u == 'B')
				{
					srand((unsigned)time(NULL));
					int random = 0;
					random = rand() % 3 + 1;
					if (random == 1)
					{
						system("cls");
						Nintendo2();
						Sleep(100);
						gotoxy(33, 10);
						printf("Ǯ ���� Ž����.\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("Ǯ ���� Ž����..\n");
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("Ǯ ���� Ž����...\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("Ǯ ���� Ž����....\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("Ǯ ���� Ž����.....\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						char print_temp[200];
						char file_path[200];
						FILE* f;
						sprintf(file_path, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\����.txt");
						f = fopen(file_path, "r");
						gotoxy(100, 1);
						for (int i = 0; i < 50; i++)
						{
							gotoxy(100, i + 1);
							fgets(print_temp, 200, f);
							printf("%s", print_temp);
						}
						gotoxy(33, 11);
						char str[50] = "�߻��� ������ ��Ÿ����!!";
						int size;
						size = sizeof(str) / sizeof(str[0]);
						for (int i = 0; i < size; i++)
						{
							Sleep(50);
							printf("%c", str[i]);
						}Sleep(100);
						if (menu == 1)
						{
							system("cls");
							Nintendo2();
							char print_temp1[200];
							char file_path1[200];
							FILE* f1;
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���̸�.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "���� ���̸�!!";
							int size1;
							size1 = sizeof(str1) / sizeof(str1[0]);
							for (int i = 0; i < size1; i++)
							{
								Sleep(50);
								printf("%c", str1[i]);
							}Sleep(100);
						}
						if (menu == 2)
						{
							system("cls");
							Nintendo2();
							char print_temp1[200];
							char file_path1[200];
							FILE* f1;
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���α�.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "���� ���α�!!";
							int size1;
							size1 = sizeof(str1) / sizeof(str1[0]);
							for (int i = 0; i < size1; i++)
							{
								Sleep(50);
								printf("%c", str1[i]);
							}Sleep(100);
						}
						if (menu == 3)
						{
							system("cls");
							Nintendo2();
							char print_temp1[200];
							char file_path1[200];
							FILE* f1;
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\�̻��ؾ�.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "���� �̻��ؾ�!!";
							int size1;
							size1 = sizeof(str1) / sizeof(str1[0]);
							for (int i = 0; i < size1; i++)
							{
								Sleep(50);
								printf("%c", str1[i]);
							}Sleep(100);
						}
						gotoxy(33, 12);
						char str2[50] = "� �ൿ�� �Ͻðڽ��ϱ�?";
						int size2;
						size2 = sizeof(str2) / sizeof(str2[0]);
						for (int i = 0; i < size2; i++)
						{
							Sleep(50);
							printf("%c", str2[i]);
						}Sleep(100);
						int r;
						gotoxy(40, 28);
						printf("[1] ��Ʋ");
						gotoxy(22, 35);
						printf("[2] ����");
						gotoxy(40, 35);
						printf("[3] ��������");
						gotoxy(58, 35);
						printf("[4] ���ϸ�");
						gotoxy(33, 13);
						scanf("%d", &r);
						if (r == 1)
						{
							if (menu == 1)
							{
								system("cls");
								Nintendo2();
								int level = 5;
								int hp = 20;
								int hp2 = 15;
								int n;
								char print_temp1[200];
								char file_path1[200];
								FILE* f1;
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���̸�.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===���̸�===");
								gotoxy(22, 30);
								printf("[1] �����ġ��");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("���̸��� �����ġ��");
									gotoxy(33, 15);
									printf("������ ������ 8 �� �Ծ���.");
									gotoxy(33, 16);
									printf("������ hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									system("cls");
									Nintendo2();
									gotoxy(33, 14);
									printf("������ ������ȭ");
									gotoxy(33, 15);
									printf("���̸��� ������ 6�� �Ծ���.");
									gotoxy(33, 16);
									printf("���̸��� hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
									int r;
								f:
									system("cls");
									Nintendo2();
									gotoxy(33, 12);
									char str2[50] = "� �ൿ�� �Ͻðڽ��ϱ�?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] ��Ʋ");
									gotoxy(22, 35);
									printf("[2] ����");
									gotoxy(40, 35);
									printf("[3] ��������");
									gotoxy(58, 35);
									printf("[4] ���ϸ�");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 13);
										printf("���̸��� �����ġ��");
										gotoxy(33, 14);
										printf("������ ������ 8 �� �Ծ���.");
										gotoxy(33, 15);
										printf("������ hp : [7]->[0]");
										gotoxy(33, 16);
										printf("������ ��������!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���̸�.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20�� ����ġ�� ������ϴ�.");
										gotoxy(33, 15);
										char str2[50] = "���̸��� ���� 7�� �Ǿ����ϴ�.";
										int size2;
										size2 = sizeof(str2) / sizeof(str2[0]);
										for (int i = 0; i < size2; i++)
										{
											Sleep(50);
											printf("%c", str2[i]);
										}Sleep(100);
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("��ſ� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										system("cls");
										Nintendo2();
										int n;
										gotoxy(40, 28);
										printf("==����==");
										gotoxy(40, 29);
										printf("[1] ���ϸ� �� : 5��");
										gotoxy(40, 30);
										printf("[2] ��ó�� : 5��");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("���ϸ��� ����Ͽ���");
											gotoxy(33, 16);
											printf("��");
											Sleep(1000);
											gotoxy(35, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�߻� ������ ��Ҵ�!");
											Sleep(100);
											gotoxy(33, 16);
											printf("������ ��� �˴ϴ�.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("��ſ� �����̿���.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ȸ������ ����Ͽ����ϴ�.");
											gotoxy(33, 16);
											printf("���̸��� hp�� ��� ȸ���Ǿ����ϴ�.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�߻� �������� ���� �����ƴ�!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�ƽ��� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("���ϸ��� �����ϴ�!!");
										Sleep(1000);
										goto f;
									}
								}
							}
							if (menu == 2)
							{
								system("cls");
								Nintendo2();
								int level = 5;
								int hp = 20;
								int hp2 = 15;
								int n;
								char print_temp1[200];
								char file_path1[200];
								FILE* f1;
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���α�.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===���α�===");
								gotoxy(22, 30);
								printf("[1] �����ġ��");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("���α��� �����ġ��");
									gotoxy(33, 15);
									printf("������ ������ 8 �� �Ծ���.");
									gotoxy(33, 16);
									printf("������ hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									system("cls");
									Nintendo2();
									gotoxy(33, 14);
									printf("������ ������ȭ");
									gotoxy(33, 15);
									printf("���α�� ������ 6�� �Ծ���.");
									gotoxy(33, 16);
									printf("���α��� hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
									int r;
								t:
									system("cls");
									Nintendo2();
									gotoxy(33, 12);
									char str2[50] = "� �ൿ�� �Ͻðڽ��ϱ�?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] ��Ʋ");
									gotoxy(22, 35);
									printf("[2] ����");
									gotoxy(40, 35);
									printf("[3] ��������");
									gotoxy(58, 35);
									printf("[4] ���ϸ�");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 13);
										printf("���α��� �����ġ��");
										gotoxy(33, 14);
										printf("������ ������ 8 �� �Ծ���.");
										gotoxy(33, 15);
										printf("������ hp : [7]->[0]");
										gotoxy(33, 16);
										printf("������ ��������!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���α�.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20�� ����ġ�� ������ϴ�.");
										gotoxy(33, 15);
										char str2[50] = "���α�� ���� 7�� �Ǿ����ϴ�.";
										int size2;
										size2 = sizeof(str2) / sizeof(str2[0]);
										for (int i = 0; i < size2; i++)
										{
											Sleep(50);
											printf("%c", str2[i]);
										}Sleep(100);
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("��ſ� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										system("cls");
										Nintendo2();
										int n;
										gotoxy(40, 28);
										printf("==����==");
										gotoxy(40, 29);
										printf("[1] ���ϸ� �� : 5��");
										gotoxy(40, 30);
										printf("[2] ��ó�� : 5��");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("���ϸ��� ����Ͽ���");
											gotoxy(33, 16);
											printf("��");
											Sleep(1000);
											gotoxy(35, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�߻� ������ ��Ҵ�!");
											Sleep(1000);
											gotoxy(33, 16);
											printf("������ ��� �˴ϴ�.");
											Sleep(100);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("��ſ� �����̿���.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ȸ������ ����Ͽ����ϴ�.");
											gotoxy(33, 16);
											printf("���̸��� hp�� ��� ȸ���Ǿ����ϴ�.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�߻� �������� ���� �����ƴ�!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�ƽ��� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("���ϸ��� �����ϴ�!!");
										Sleep(1000);
										goto t;
									}
								}
							}
							if (menu == 3)
							{
								system("cls");
								Nintendo2();
								int level = 5;
								int hp = 20;
								int hp2 = 15;
								int n;
								char print_temp1[200];
								char file_path1[200];
								FILE* f1;
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\�̻��ؾ�.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===�̻��ؾ�===");
								gotoxy(22, 30);
								printf("[1] �����ġ��");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("�̻��ؾ��� �����ġ��");
									gotoxy(33, 15);
									printf("������ ������ 8 �� �Ծ���.");
									gotoxy(33, 16);
									printf("������ hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									gotoxy(33, 14);
									printf("������ ������ȭ");
									gotoxy(33, 15);
									printf("�̻��ؾ��� ������ 6�� �Ծ���.");
									gotoxy(33, 16);
									printf("�̻��ؾ��� hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
								x:
									system("cls");
									Nintendo2();
									int r;
									gotoxy(33, 12);
									char str2[50] = "� �ൿ�� �Ͻðڽ��ϱ�?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] ��Ʋ");
									gotoxy(22, 35);
									printf("[2] ����");
									gotoxy(40, 35);
									printf("[3] ��������");
									gotoxy(58, 35);
									printf("[4] ���ϸ�");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 13);
										printf("�̻��ؾ��� �����ġ��");
										gotoxy(33, 14);
										printf("������ ������ 8 �� �Ծ���.");
										gotoxy(33, 15);
										printf("������ hp : [7]->[0]");
										gotoxy(33, 16);
										printf("������ ��������!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\�̻��ؾ�.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20�� ����ġ�� ������ϴ�.");
										gotoxy(33, 15);
										char str2[50] = "�̻��ؾ��� ���� 7�� �Ǿ����ϴ�.";
										int size2;
										size2 = sizeof(str2) / sizeof(str2[0]);
										for (int i = 0; i < size2; i++)
										{
											Sleep(50);
											printf("%c", str2[i]);
										}Sleep(100);
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("��ſ� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										system("cls");
										Nintendo2();
										int n;
										gotoxy(40, 28);
										printf("==����==");
										gotoxy(40, 29);
										printf("[1] ���ϸ� �� : 5��");
										gotoxy(40, 30);
										printf("[2] ��ó�� : 5��");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("���ϸ��� ����Ͽ���");
											gotoxy(33, 16);
											printf("��");
											Sleep(1000);
											gotoxy(35, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�߻� ������ ��Ҵ�!");
											Sleep(100);
											gotoxy(33, 16);
											printf("������ ��� �˴ϴ�.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("��ſ� �����̿���.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ȸ������ ����Ͽ����ϴ�.");
											gotoxy(33, 16);
											printf("���̸��� hp�� ��� ȸ���Ǿ����ϴ�.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�߻� �������� ���� �����ƴ�!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�ƽ��� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("���ϸ��� �����ϴ�!!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										goto x;
									}
								}
							}
						}
					}
					if (random == 2)
					{
						system("cls");
						Nintendo2();
						Sleep(100);
						gotoxy(33, 10);
						printf("Ǯ ���� Ž����.\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("Ǯ ���� Ž����..\n");
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("Ǯ ���� Ž����...\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("Ǯ ���� Ž����....\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("Ǯ ���� Ž����.....\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						char print_temp[200];
						char file_path[200];
						FILE* f;
						sprintf(file_path, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\����.txt");
						f = fopen(file_path, "r");
						gotoxy(100, 1);
						for (int i = 0; i < 35; i++)
						{
							gotoxy(100, i + 1);
							fgets(print_temp, 200, f);
							printf("%s", print_temp);
						}
						gotoxy(33, 11);
						char str[50] = "�߻��� ������ ��Ÿ����!!";
						int size;
						size = sizeof(str) / sizeof(str[0]);
						for (int i = 0; i < size; i++)
						{
							Sleep(50);
							printf("%c", str[i]);
						}Sleep(100);
						if (menu == 1)
						{
							system("cls");
							Nintendo2();
							char print_temp1[200];
							char file_path1[200];
							FILE* f1;
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���̸�.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "���� ���̸�!!";
							int size1;
							size1 = sizeof(str1) / sizeof(str1[0]);
							for (int i = 0; i < size1; i++)
							{
								Sleep(50);
								printf("%c", str1[i]);
							}Sleep(100);
						}
						if (menu == 2)
						{
							system("cls");
							Nintendo2();
							char print_temp1[200];
							char file_path1[200];
							FILE* f1;
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���α�.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "���� ���α�!!";
							int size1;
							size1 = sizeof(str1) / sizeof(str1[0]);
							for (int i = 0; i < size1; i++)
							{
								Sleep(50);
								printf("%c", str1[i]);
							}Sleep(100);
						}
						if (menu == 3)
						{
							system("cls");
							Nintendo2();
							char print_temp1[200];
							char file_path1[200];
							FILE* f1;
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\�̻��ؾ�.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "���� �̻��ؾ�!!";
							int size1;
							size1 = sizeof(str1) / sizeof(str1[0]);
							for (int i = 0; i < size1; i++)
							{
								Sleep(50);
								printf("%c", str1[i]);
							}Sleep(100);
						}
						gotoxy(33, 12);
						char str2[50] = "� �ൿ�� �Ͻðڽ��ϱ�?";
						int size2;
						size2 = sizeof(str2) / sizeof(str2[0]);
						for (int i = 0; i < size2; i++)
						{
							Sleep(50);
							printf("%c", str2[i]);
						}Sleep(100);
						int r;
						gotoxy(40, 28);
						printf("[1] ��Ʋ");
						gotoxy(22, 35);
						printf("[2] ����");
						gotoxy(40, 35);
						printf("[3] ��������");
						gotoxy(58, 35);
						printf("[4] ���ϸ�");
						gotoxy(33, 13);
						scanf("%d", &r);
						if (r == 1)
						{
							if (menu == 1)
							{
								system("cls");
								Nintendo2();
								int level = 5;
								int hp = 20;
								int hp2 = 15;
								int n;
								char print_temp1[200];
								char file_path1[200];
								FILE* f1;
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���̸�.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===���̸�===");
								gotoxy(22, 30);
								printf("[1] �����ġ��");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("���̸��� �����ġ��");
									gotoxy(33, 15);
									printf("������ ������ 8 �� �Ծ���.");
									gotoxy(33, 16);
									printf("������ hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									system("cls");
									Nintendo2();
									gotoxy(33, 14);
									printf("������ ������ȭ");
									gotoxy(33, 15);
									printf("���̸��� ������ 6�� �Ծ���.");
									gotoxy(33, 16);
									printf("���̸��� hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
									int r;
								o:
									system("cls");
									Nintendo2();
									gotoxy(33, 12);
									char str2[50] = "� �ൿ�� �Ͻðڽ��ϱ�?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] ��Ʋ");
									gotoxy(22, 35);
									printf("[2] ����");
									gotoxy(40, 35);
									printf("[3] ��������");
									gotoxy(58, 35);
									printf("[4] ���ϸ�");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										gotoxy(33, 13);
										printf("���̸��� �����ġ��");
										gotoxy(33, 14);
										printf("������ ������ 8 �� �Ծ���.");
										gotoxy(33, 15);
										printf("������ hp : [7]->[0]");
										gotoxy(33, 16);
										printf("������ ��������!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���̸�.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20�� ����ġ�� ������ϴ�.");
										gotoxy(33, 15);
										char str2[50] = "���̸��� ���� 7�� �Ǿ����ϴ�.";
										int size2;
										size2 = sizeof(str2) / sizeof(str2[0]);
										for (int i = 0; i < size2; i++)
										{
											Sleep(50);
											printf("%c", str2[i]);
										}Sleep(100);
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("��ſ� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										int n;
										system("cls");
										Nintendo2();
										gotoxy(40, 28);
										printf("==����==");
										gotoxy(40, 29);
										printf("[1] ���ϸ� �� : 5��");
										gotoxy(40, 30);
										printf("[2] ��ó�� : 5��");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("���ϸ��� ����Ͽ���");
											gotoxy(33, 16);
											printf("��");
											Sleep(1000);
											gotoxy(35, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�߻� ������ ��Ҵ�!");
											Sleep(100);
											gotoxy(33, 16);
											printf("������ ��� �˴ϴ�.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("��ſ� �����̿���.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ȸ������ ����Ͽ����ϴ�.");
											gotoxy(33, 16);
											printf("���̸��� hp�� ��� ȸ���Ǿ����ϴ�.");
										}
									}
									if (b == 3)
									{
										gotoxy(33, 15);
										printf("�߻� ������ ���� �����ƴ�!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�ƽ��� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("���ϸ��� �����ϴ�!!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										goto o;
									}
								}
							}
							if (menu == 2)
							{
								system("cls");
								Nintendo2();
								int level = 5;
								int hp = 20;
								int hp2 = 15;
								int n;
								char print_temp1[200];
								char file_path1[200];
								FILE* f1;
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���α�.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===���α�===");
								gotoxy(22, 30);
								printf("[1] �����ġ��");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("���α��� �����ġ��");
									gotoxy(33, 15);
									printf("������ ������ 8 �� �Ծ���.");
									gotoxy(33, 16);
									printf("������ hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									system("cls");
									Nintendo2();
									gotoxy(33, 14);
									printf("������ ������ȭ");
									gotoxy(33, 15);
									printf("���α�� ������ 6�� �Ծ���.");
									gotoxy(33, 16);
									printf("���α��� hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
									int r;
								v:
									system("cls");
									Nintendo2();
									gotoxy(33, 12);
									char str2[50] = "� �ൿ�� �Ͻðڽ��ϱ�?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] ��Ʋ");
									gotoxy(22, 35);
									printf("[2] ����");
									gotoxy(40, 35);
									printf("[3] ��������");
									gotoxy(58, 35);
									printf("[4] ���ϸ�");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										gotoxy(33, 13);
										printf("���α��� �����ġ��");
										gotoxy(33, 14);
										printf("������ ������ 8 �� �Ծ���.");
										gotoxy(33, 15);
										printf("������ hp : [7]->[0]");
										gotoxy(33, 16);
										printf("������ ��������!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���α�.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20�� ����ġ�� ������ϴ�.");
										gotoxy(33, 15);
										char str2[50] = "���α�� ���� 7�� �Ǿ����ϴ�.";
										int size2;
										size2 = sizeof(str2) / sizeof(str2[0]);
										for (int i = 0; i < size2; i++)
										{
											Sleep(50);
											printf("%c", str2[i]);
										}Sleep(100);
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("��ſ� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										int n;
										system("cls");
										Nintendo2();
										gotoxy(40, 28);
										printf("==����==");
										gotoxy(40, 29);
										printf("[1] ���ϸ� �� : 5��");
										gotoxy(40, 30);
										printf("[2] ��ó�� : 5��");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("���ϸ��� ����Ͽ���");
											gotoxy(33, 16);
											printf("��");
											Sleep(1000);
											gotoxy(35, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�߻� ������ ��Ҵ�!");
											Sleep(100);
											gotoxy(33, 16);
											printf("������ ��� �˴ϴ�.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("��ſ� �����̿���.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ȸ������ ����Ͽ����ϴ�.");
											gotoxy(33, 16);
											printf("���̸��� hp�� ��� ȸ���Ǿ����ϴ�.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�߻� ������ ���� �����ƴ�!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�ƽ��� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("���ϸ��� �����ϴ�!!");
										Sleep(1000);
										goto v;
									}
								}
							}
							if (menu == 3)
							{
								system("cls");
								Nintendo2();
								int level = 5;
								int hp = 20;
								int hp2 = 15;
								int n;
								char print_temp1[200];
								char file_path1[200];
								FILE* f1;
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\�̻��ؾ�.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===�̻��ؾ�===");
								gotoxy(22, 30);
								printf("[1] �����ġ��");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("�̻��ؾ��� �����ġ��");
									gotoxy(33, 15);
									printf("������ ������ 8 �� �Ծ���.");
									gotoxy(33, 16);
									printf("������ hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									gotoxy(33, 14);
									printf("������ ������ȭ");
									gotoxy(33, 15);
									printf("�̻��ؾ��� ������ 6�� �Ծ���.");
									gotoxy(33, 16);
									printf("�̻��ؾ��� hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
								h:
									system("cls");
									Nintendo2();
									int r;
									gotoxy(33, 12);
									char str2[50] = "� �ൿ�� �Ͻðڽ��ϱ�?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] ��Ʋ");
									gotoxy(22, 35);
									printf("[2] ����");
									gotoxy(40, 35);
									printf("[3] ��������");
									gotoxy(58, 35);
									printf("[4] ���ϸ�");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										gotoxy(33, 13);
										printf("�̻��ؾ��� �����ġ��");
										gotoxy(33, 14);
										printf("������ ������ 8 �� �Ծ���.");
										gotoxy(33, 15);
										printf("������ hp : [7]->[0]");
										gotoxy(33, 16);
										printf("������ ��������!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\�̻��ؾ�.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20�� ����ġ�� ������ϴ�.");
										gotoxy(33, 15);
										char str2[50] = "�̻��ؾ��� ���� 7�� �Ǿ����ϴ�.";
										int size2;
										size2 = sizeof(str2) / sizeof(str2[0]);
										for (int i = 0; i < size2; i++)
										{
											Sleep(50);
											printf("%c", str2[i]);
										}Sleep(100);
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("��ſ� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										int n;
										system("cls");
										Nintendo2();
										gotoxy(40, 28);
										printf("==����==");
										gotoxy(40, 29);
										printf("[1] ���ϸ� �� : 5��");
										gotoxy(40, 30);
										printf("[2] ��ó�� : 5��");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("���ϸ��� ����Ͽ���");
											gotoxy(33, 16);
											printf("��");
											Sleep(1000);
											gotoxy(35, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�߻� ������ ��Ҵ�!");
											Sleep(100);
											gotoxy(33, 16);
											printf("������ ��� �˴ϴ�.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("��ſ� �����̿���.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ȸ������ ����Ͽ����ϴ�.");
											gotoxy(33, 16);
											printf("���̸��� hp�� ��� ȸ���Ǿ����ϴ�.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�߻� ������ ���� �����ƴ�!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�ƽ��� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("���ϸ��� �����ϴ�!!");
										Sleep(1000);
										goto h;
									}
								}
							}
						}
					}
					if (random == 3)
					{
						system("cls");
						Nintendo2();
						Sleep(100);
						gotoxy(33, 10);
						printf("Ǯ ���� Ž����.\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("Ǯ ���� Ž����..\n");
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("Ǯ ���� Ž����...\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("Ǯ ���� Ž����....\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("Ǯ ���� Ž����.....\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						char print_temp[200];
						char file_path[200];
						FILE* f;
						sprintf(file_path, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\ĳ����.txt");
						f = fopen(file_path, "r");
						gotoxy(100, 1);
						for (int i = 0; i < 40; i++)
						{
							gotoxy(100, i + 1);
							fgets(print_temp, 200, f);
							printf("%s", print_temp);
						}
						gotoxy(33, 11);
						char str[50] = "�߻��� ĳ���ǰ� ��Ÿ����!!";
						int size;
						size = sizeof(str) / sizeof(str[0]);
						for (int i = 0; i < size; i++)
						{
							Sleep(50);
							printf("%c", str[i]);
						}Sleep(100);
						if (menu == 1)
						{
							system("cls");
							Nintendo2();
							char print_temp1[200];
							char file_path1[200];
							FILE* f1;
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���̸�.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "���� ���̸�!!";
							int size1;
							size1 = sizeof(str1) / sizeof(str1[0]);
							for (int i = 0; i < size1; i++)
							{
								Sleep(50);
								printf("%c", str1[i]);
							}Sleep(100);
						}
						if (menu == 2)
						{
							system("cls");
							Nintendo2();
							char print_temp1[200];
							char file_path1[200];
							FILE* f1;
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���α�.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "���� ���α�!!";
							int size1;
							size1 = sizeof(str1) / sizeof(str1[0]);
							for (int i = 0; i < size1; i++)
							{
								Sleep(50);
								printf("%c", str1[i]);
							}Sleep(100);
						}
						if (menu == 3)
						{
							system("cls");
							Nintendo2();
							char print_temp1[200];
							char file_path1[200];
							FILE* f1;
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\�̻��ؾ�.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "���� �̻��ؾ�!!";
							int size1;
							size1 = sizeof(str1) / sizeof(str1[0]);
							for (int i = 0; i < size1; i++)
							{
								Sleep(50);
								printf("%c", str1[i]);
							}Sleep(100);
						}
						gotoxy(33, 12);
						char str2[50] = "� �ൿ�� �Ͻðڽ��ϱ�?";
						int size2;
						size2 = sizeof(str2) / sizeof(str2[0]);
						for (int i = 0; i < size2; i++)
						{
							Sleep(50);
							printf("%c", str2[i]);
						}Sleep(100);
						int r;
						gotoxy(40, 28);
						printf("[1] ��Ʋ");
						gotoxy(22, 35);
						printf("[2] ����");
						gotoxy(40, 35);
						printf("[3] ��������");
						gotoxy(58, 35);
						printf("[4] ���ϸ�");
						gotoxy(33, 13);
						scanf("%d", &r);
						if (r == 1)
						{
							if (menu == 1)
							{
								system("cls");
								Nintendo2();
								int level = 5;
								int hp = 20;
								int hp2 = 15;
								int n;
								char print_temp1[200];
								char file_path1[200];
								FILE* f1;
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���̸�.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===���̸�===");
								gotoxy(22, 30);
								printf("[1] �����ġ��");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("���̸��� �����ġ��");
									gotoxy(33, 15);
									printf("ĳ���Ǵ� ������ 8 �� �Ծ���.");
									gotoxy(33, 16);
									printf("ĳ������ hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									system("cls");
									Nintendo2();
									gotoxy(33, 14);
									printf("ĳ������ �����ġ��");
									gotoxy(33, 15);
									printf("���̸��� ������ 6�� �Ծ���.");
									gotoxy(33, 16);
									printf("���̸��� hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
									int r;
								l:
									system("cls");
									Nintendo2();
									gotoxy(33, 12);
									char str2[50] = "� �ൿ�� �Ͻðڽ��ϱ�?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] ��Ʋ");
									gotoxy(22, 35);
									printf("[2] ����");
									gotoxy(40, 35);
									printf("[3] ��������");
									gotoxy(58, 35);
									printf("[4] ���ϸ�");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 13);
										printf("���̸��� �����ġ��");
										gotoxy(33, 14);
										printf("ĳ���Ǵ� ������ 8 �� �Ծ���.");
										gotoxy(33, 15);
										printf("ĳ������ hp : [7]->[0]");
										gotoxy(33, 16);
										printf("ĳ���Ǵ� ��������!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���̸�.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20�� ����ġ�� ������ϴ�.");
										gotoxy(33, 15);
										char str2[50] = "���̸��� ���� 7�� �Ǿ����ϴ�.";
										int size2;
										size2 = sizeof(str2) / sizeof(str2[0]);
										for (int i = 0; i < size2; i++)
										{
											Sleep(50);
											printf("%c", str2[i]);
										}Sleep(100);
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("��ſ� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										int n;
										system("cls");
										Nintendo2();
										gotoxy(40, 28);
										printf("==����==");
										gotoxy(33, 29);
										printf("[1] ���ϸ� �� : 5��");
										gotoxy(33, 30);
										printf("[2] ��ó�� : 5��");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("���ϸ� ���� ����Ͽ���");
											gotoxy(33, 16);
											printf("��");
											Sleep(1000);
											gotoxy(35, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�߻� ĳ���Ǹ� ��Ҵ�!");
											Sleep(100);
											gotoxy(33, 16);
											printf("������ ��� �˴ϴ�.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("��ſ� �����̿���.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ȸ������ ����Ͽ����ϴ�.");
											gotoxy(33, 16);
											printf("���̸��� hp�� ��� ȸ���Ǿ����ϴ�.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�߻� ĳ���Ƿ� ���� �����ƴ�!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�ƽ��� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("���ϸ��� �����ϴ�!!");
										Sleep(1000);
										goto l;

									}
								}
							}
							if (menu == 2)
							{
								system("cls");
								Nintendo2();
								int level = 5;
								int hp = 20;
								int hp2 = 15;
								int n;
								char print_temp1[200];
								char file_path1[200];
								FILE* f1;
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���α�.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===���α�===");
								gotoxy(22, 30);
								printf("[1] �����ġ��");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("���α��� �����ġ��");
									gotoxy(33, 15);
									printf("ĳ���Ǵ� ������ 8 �� �Ծ���.");
									gotoxy(33, 16);
									printf("ĳ������ hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									system("cls");
									Nintendo2();
									gotoxy(33, 14);
									printf("ĳ������ �����ġ��");
									gotoxy(33, 15);
									printf("���α�� ������ 6�� �Ծ���.");
									gotoxy(33, 16);
									printf("���α��� hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
									int r;
								p:
									system("cls");
									Nintendo2();
									gotoxy(33, 12);
									char str2[50] = "� �ൿ�� �Ͻðڽ��ϱ�?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] ��Ʋ");
									gotoxy(22, 35);
									printf("[2] ����");
									gotoxy(40, 35);
									printf("[3] ��������");
									gotoxy(58, 35);
									printf("[4] ���ϸ�");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										gotoxy(33, 13);
										printf("���α��� �����ġ��");
										gotoxy(33, 14);
										printf("ĳ���Ǵ� ������ 8 �� �Ծ���.");
										gotoxy(33, 15);
										printf("ĳ������ hp : [7]->[0]");
										gotoxy(33, 16);
										printf("ĳ���Ǵ� ��������!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\���α�.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20�� ����ġ�� ������ϴ�.");
										gotoxy(33, 15);
										char str2[50] = "���α�� ���� 7�� �Ǿ����ϴ�.";
										int size2;
										size2 = sizeof(str2) / sizeof(str2[0]);
										for (int i = 0; i < size2; i++)
										{
											Sleep(50);
											printf("%c", str2[i]);
										}Sleep(100);
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("��ſ� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										int n;
										system("cls");
										Nintendo2();
										gotoxy(40, 28);
										printf("==����==");
										gotoxy(40, 29);
										printf("[1] ���ϸ� �� : 5��");
										gotoxy(40, 30);
										printf("[2] ��ó�� : 5��");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("���ϸ��� ����Ͽ���");
											gotoxy(33, 16);
											printf("��");
											Sleep(1000);
											gotoxy(35, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�߻� ĳ���Ǹ� ��Ҵ�!");
											Sleep(100);
											gotoxy(33, 16);
											printf("������ ��� �˴ϴ�.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("��ſ� �����̿���.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ȸ������ ����Ͽ����ϴ�.");
											gotoxy(33, 16);
											printf("���̸��� hp�� ��� ȸ���Ǿ����ϴ�.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�߻� ĳ���Ƿ� ���� �����ƴ�!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�ƽ��� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("���ϸ��� �����ϴ�!!");
										Sleep(1000);
										goto p;
									}
								}
							}
							if (menu == 3)
							{
								system("cls");
								Nintendo2();
								int level = 5;
								int hp = 20;
								int hp2 = 15;
								int n;
								char print_temp1[200];
								char file_path1[200];
								FILE* f1;
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\�̻��ؾ�.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===�̻��ؾ�===");
								gotoxy(22, 30);
								printf("[1] �����ġ��");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("�̻��ؾ��� �����ġ��");
									gotoxy(33, 15);
									printf("ĳ���Ǵ� ������ 8 �� �Ծ���.");
									gotoxy(33, 16);
									printf("ĳ������ hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									gotoxy(33, 14);
									printf("ĳ������ ������ȭ");
									gotoxy(33, 15);
									printf("�̻��ؾ��� ������ 6�� �Ծ���.");
									gotoxy(33, 16);
									printf("�̻��ؾ��� hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
								w:
									system("cls");
									Nintendo2();
									int r;
									gotoxy(33, 12);
									char str2[50] = "� �ൿ�� �Ͻðڽ��ϱ�?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] ��Ʋ");
									gotoxy(22, 35);
									printf("[2] ����");
									gotoxy(40, 35);
									printf("[3] ��������");
									gotoxy(58, 35);
									printf("[4] ���ϸ�");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										gotoxy(33, 13);
										printf("�̻��ؾ��� �����ġ��");
										gotoxy(33, 14);
										printf("ĳ���Ǵ� ������ 8 �� �Ծ���.");
										gotoxy(33, 15);
										printf("ĳ������ hp : [7]->[0]");
										gotoxy(33, 16);
										printf("ĳ������ ��������!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(��������Ʈ)\\�̻��ؾ�.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20�� ����ġ�� ������ϴ�.");
										gotoxy(33, 15);
										char str2[50] = "�̻��ؾ��� ���� 7�� �Ǿ����ϴ�.";
										int size2;
										size2 = sizeof(str2) / sizeof(str2[0]);
										for (int i = 0; i < size2; i++)
										{
											Sleep(50);
											printf("%c", str2[i]);
										}Sleep(100);
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("��ſ� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										int n;
										system("cls");
										Nintendo2();
										gotoxy(40, 28);
										printf("==����==");
										gotoxy(40, 29);
										printf("[1] ���ϸ� �� : 5��");
										gotoxy(40, 30);
										printf("[2] ��ó�� : 5��");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("���ϸ��� ����Ͽ���");
											gotoxy(33, 16);
											printf("��");
											Sleep(1000);
											gotoxy(35, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											gotoxy(37, 16);
											printf("��");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�߻� ĳ���Ǹ� ��Ҵ�!");
											Sleep(100);
											gotoxy(33, 16);
											printf("������ ��� �˴ϴ�.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("��ſ� �����̿���.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ȸ������ ����Ͽ����ϴ�.");
											gotoxy(33, 16);
											printf("���̸��� hp�� ��� ȸ���Ǿ����ϴ�.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�߻� ĳ���Ƿ� ���� �����ƴ�!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("�ƽ��� �����̿���.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("���ϸ��� �����ϴ�!!");
										Sleep(1000);
										goto w;
									}
								}
							}
						}
					}
				}
				else if (u == 'x' || u == 'X')
				{
					int s;
					system("cls");
					Nintendo2();
					Sleep(100);
					gotoxy(33, 10);
					printf("���� �̵� ��.\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("���� �̵� ��..\n");
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("���� �̵� ��...\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("���� �̵� ��....\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("���� �̵� ��.....\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					int c;
					gotoxy(32, 11);
					printf("������ ��ðڽ��ϱ�?");
					gotoxy(35, 28);
					printf("[1] ���ϸ� ��");
					gotoxy(35, 32);
					printf("[2] ȸ����");
					gotoxy(35, 33);
					scanf("%d", &c);
					if (c == 1)
					{
						int cash = 10000;
						int ball;
						system("cls");
						Nintendo2();
						gotoxy(33, 15);
						printf("���ϸ� �� ��� �����Ͻðڽ��ϱ�?");
						system("cls");
						Nintendo2();
						gotoxy(33, 15);
						printf("���ϸ� �� �ϳ��� 1000��");
						gotoxy(33, 28);
						printf("[1].1��");
						gotoxy(33, 30);
						printf("[2].5��");
						gotoxy(33, 32);
						printf("[3].10��");
						gotoxy(33, 16);
						scanf("%d", &ball);
						if (ball == 1)
						{
							system("cls");
							Nintendo2();
							gotoxy(33, 15);
							printf("9000�� ���ҽ��ϴ�.");
							Sleep(1000);
							cash -= 1000;
							goto e;
						}
						if (ball == 2)
						{
							system("cls");
							Nintendo2();
							gotoxy(33, 15);
							printf("5000�� ���ҽ��ϴ�.");
							cash -= 5000;
							Sleep(1000);
							goto e;
						}
						if (ball == 3)
						{
							system("cls");
							Nintendo2();
							gotoxy(33, 15);
							printf("0�� ���ҽ��ϴ�.");
							Sleep(1000);
							cash -= 10000;
						}
						if (cash == 0)
						{
							gotoxy(33, 15);
							printf("���̻� �� �� �����ϴ�");
							Sleep(1000);
							goto e;
						}
					}
					if (c == 2)
					{
						int cash = 10000;
						int cu;
						system("cls");
						Nintendo2();
						gotoxy(33, 15);
						printf("ȸ���� ��� �����Ͻðڽ��ϱ�?");
						system("cls");
						Nintendo2();
						gotoxy(33, 15);
						printf("ȸ���� �ϳ��� 1000��");
						gotoxy(33, 28);
						printf("[1].1��");
						gotoxy(33, 30);
						printf("[2].5��");
						gotoxy(33, 32);
						printf("[3].10��");
						gotoxy(33, 16);
						scanf("%d", &cu);
						if (cu == 1)
						{
							system("cls");
							Nintendo2();
							gotoxy(33, 15);
							printf("9000�� ���ҽ��ϴ�.");
							cash -= 1000;
							Sleep(1000);
							goto e;
						}
						if (cu == 2)
						{
							system("cls");
							Nintendo2();
							gotoxy(33, 15);
							printf("5000�� ���ҽ��ϴ�.");
							cash -= 5000;
							Sleep(1000);
							goto e;
						}
						if (cu == 3)
						{
							system("cls");
							Nintendo2();
							gotoxy(33, 15);
							printf("0�� ���ҽ��ϴ�.");
							cash -= 10000;
							Sleep(1000);
						}
						if (cash == 0)
						{
							gotoxy(33, 15);
							printf("���̻� �� �� �����ϴ�");
							Sleep(100);
							Sleep(1000);
							goto e;
						}
					}
				}
				else if (u == 'y' || u == 'Y')
				{
					system("cls");
					Nintendo2();
					gotoxy(24, 4);
					char str[50] = "���� ü������ �� �� ����!!";
					int size;
					size = sizeof(str) / sizeof(str[0]);
					for (int i = 0; i < size; i++)
					{
						Sleep(50);
						printf("%c", str[i]);
					}Sleep(100);
					goto e;
				}
			}
			if (n == 2)
			{
				system("cls");
				Nintendo2();
				Sleep(1000);
				gotoxy(33, 14);
				printf("���ݴ� �ִٰ� ������...");
				Sleep(1000);
				gotoxy(33, 15);
				printf("�׷� ������ ���߿� ����..");
				Sleep(2000);
				system("cls");
				Nintendo2();
				Sleep(2000);
				gotoxy(33, 15);
				printf("����� ���̽��ϱ�?");
				Sleep(1000);
				gotoxy(32, 16);
				printf("����� ���̴ٸ� ������ �����ϰڽ��ϴ�.");
				Sleep(2000);
				system("cls");
				Nintendo2();
				goto r;
			}
		}
		if (u == 2)
		{
			Nintendo_end();
		}
	}
	gotoxy(50, 42);
	exit(0);
}
