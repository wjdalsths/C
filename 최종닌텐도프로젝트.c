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

int doa; //避歷朝雖 寰避歷朝雖 轎溘, 避歷戲賊 0, 髦懊戲賊 1
int belt_1[50];
int belt_2[50];//0檜賊 望, 1檜賊 濰擁僭
int playerpos;//1檜賊 嬪, 0檜賊 嬴楚
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
	int n;//璋濠
	int x;//雲橫韓 x謝ル 
	int y;//雲橫韓 y謝ル
	int flag;//�飛橦� 氈朝雖 橈朝雖 0,1煎 
	int time;//渠晦 衛除
	int speed;//樓紫
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
}//醴憮 橈擁晦
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
	char str12[50] = "斜 牖除, 釭朝 跨蝶攪獐擊 頂溥 場戲貊 儅陝ц棻.";
	int size12;
	size12 = sizeof(str12) / sizeof(str12[0]);
	for (int i = 0; i < size12; i++)
	{
		Sleep(50);
		printf("%c", str12[i]);
	}Sleep(100);
	gotoxy(24, 5);
	char str13[50] = "縑橫鐘 ぎ堅 餵寰縑憮 啪歜擊 ж堅 談棻朝 儅陝擊";
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
	char str14[40] = "釭朝 雖旎 賅я擊 ж堅談擎啪 嬴棲艘棻.";
	int size14;
	size14 = sizeof(str14) / sizeof(str14[0]);
	for (int i = 0; i < size14; i++)
	{
		Sleep(50);
		printf("%c", str14[i]);
	}Sleep(100);
	gotoxy(24, 5);
	char str15[30] = "翱掘模縑憮 釭諦 餵戲煎 щж堅,";
	int size15;
	size15 = sizeof(str15) / sizeof(str15[0]);
	for (int i = 0; i < size15; i++)
	{
		Sleep(50);
		printf("%c", str15[i]);
	}
	gotoxy(24, 6);
	char str16[30] = "寞縑 菟橫陛 藹渠縑 援錫棻.";
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
	char str17[50] = "[�鰽� 縛註 1] : 賅я評孺 橈棻";
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
	printf("﹥﹥﹥﹥﹥﹥﹥  ﹥          ﹥  ﹥﹥﹥﹥﹥﹥﹥");
	gotoxy(23, 5);
	printf("      ﹥        ﹥          ﹥  ﹥            ");
	gotoxy(23, 6);
	printf("      ﹥        ﹥          ﹥  ﹥            ");
	gotoxy(23, 7);
	printf("      ﹥        ﹥          ﹥  ﹥            ");
	gotoxy(23, 8);
	printf("      ﹥        ﹥          ﹥  ﹥            ");
	gotoxy(23, 9);
	printf("      ﹥        ﹥          ﹥  ﹥            ");
	gotoxy(23, 10);
	printf("      ﹥        ﹥﹥﹥﹥﹥﹥﹥  ﹥﹥﹥﹥﹥﹥﹥");
	gotoxy(23, 11);
	printf("      ﹥        ﹥          ﹥  ﹥            ");
	gotoxy(23, 12);
	printf("      ﹥        ﹥          ﹥  ﹥            ");
	gotoxy(23, 13);
	printf("      ﹥        ﹥          ﹥  ﹥            ");
	gotoxy(23, 14);
	printf("      ﹥        ﹥          ﹥  ﹥            ");
	gotoxy(23, 15);
	printf("      ﹥        ﹥          ﹥  ﹥            ");
	gotoxy(23, 16);
	printf("      ﹥        ﹥          ﹥  ﹥﹥﹥﹥﹥﹥﹥");
	gotoxy(23, 26);
	printf("﹥﹥﹥﹥﹥﹥﹥  ﹥﹥         ﹥  ﹥﹥﹥﹥﹥    ");
	gotoxy(23, 27);
	printf("﹥              ﹥﹥         ﹥  ﹥       ﹥   ");
	gotoxy(23, 28);
	printf("﹥              ﹥ ﹥        ﹥  ﹥        ﹥  ");
	gotoxy(23, 29);
	printf("﹥              ﹥  ﹥       ﹥  ﹥         ﹥ ");
	gotoxy(23, 30);
	printf("﹥              ﹥   ﹥      ﹥  ﹥          ﹥");
	gotoxy(23, 31);
	printf("﹥              ﹥    ﹥     ﹥  ﹥          ﹥");
	gotoxy(23, 32);
	printf("﹥﹥﹥﹥﹥﹥﹥  ﹥     ﹥    ﹥  ﹥          ﹥");
	gotoxy(23, 33);
	printf("﹥              ﹥      ﹥   ﹥  ﹥          ﹥");
	gotoxy(23, 34);
	printf("﹥              ﹥       ﹥  ﹥  ﹥         ﹥ ");
	gotoxy(23, 35);
	printf("﹥              ﹥        ﹥ ﹥  ﹥        ﹥  ");
	gotoxy(23, 36);
	printf("﹥              ﹥         ﹥﹥  ﹥       ﹥   ");
	gotoxy(23, 37);
	printf("﹥﹥﹥﹥﹥﹥﹥  ﹥         ﹥﹥  ﹥﹥﹥﹥﹥    ");
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
	char str1[30] = "�紊腎桭炴�.";
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
	char str2[30] = "褒чж衛啊蝗棲梱?";
	int size1;
	size1 = sizeof(str2) / sizeof(str2[0]);
	for (int i = 0; i < size1; i++)
	{
		Sleep(35);
		printf("%c", str2[i]);
	}
	Sleep(150);
	gotoxy(37, 11);
	char str3[30] = "(S)幗が擊 援腦衛螃.";
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
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                                                                                         早\n");
	printf("早                                                                                         早\n");
	printf("早                   旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早     Ⅸ  Ⅸ  Ⅸ    早                                                 早     Ⅸ  Ⅸ  Ⅸ    早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早     Ⅸ  Ⅸ  Ⅸ    早                                                 早     Ⅸ  Ⅸ  Ⅸ    早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭                   早\n");
	printf("早                                                                                         早\n");
	printf("早                                                                                         早\n");
	printf("曳收收收收有收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收有收收收收朽\n");
	printf("早    早                                                                               早 || 早\n");
	printf("曳收收收收朴收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朴收收收收朽\n");
	printf("早                                                                                         早\n");
	printf("早                                                                                         早\n");
	printf("早                   旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早       旨收收旬        早\n");
	printf("早     旨收收收收旬        早                                                 早       早 X早        早\n");
	printf("早     早 ∟ 早        早                                                 早       曲收收旭        早\n");
	printf("早     早    早        早                                                 早   旨收收旬    旨收收旬    早\n");
	printf("早 旨收收收旭    曲收收收旬    早                                                 早   早 Y早    早 A早    早\n");
	printf("早 早 ∠       ⊥早    早                                                 早   曲收收旭    曲收收旭    早\n");
	printf("早 曲收收收旬    旨收收收旭    早                                                 早       旨收收旬        早\n");
	printf("早     早    早        早                                                 早       早 B早        早\n");
	printf("早     早 ⊿ 早        早                                                 早       曲收收旭        早\n");
	printf("早     曲收收收收旭        早                                                 早 佺return          早\n");
	printf("早                   早                                                 早 供 謙猿           早\n");
	printf("早                   曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭                   早\n");
	printf("早                                                                                         早\n");
	printf("早                                                                                         早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	memo();
	gotoxy(50, 42);
}
int Nintendo2()
{
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                                                                                         早\n");
	printf("早                                                                                         早\n");
	printf("早                   旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早     Ⅸ  Ⅸ  Ⅸ    早                                                 早     Ⅸ  Ⅸ  Ⅸ    早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早     Ⅸ  Ⅸ  Ⅸ    早                                                 早     Ⅸ  Ⅸ  Ⅸ    早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭                   早\n");
	printf("早                                                                                         早\n");
	printf("早                                                                                         早\n");
	printf("曳收收收收有收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收有收收收收朽\n");
	printf("早    早                                                                               早 || 早\n");
	printf("曳收收收收朴收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朴收收收收朽\n");
	printf("早                                                                                         早\n");
	printf("早                                                                                         早\n");
	printf("早                   旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬                   早\n");
	printf("早                   早                                                 早                   早\n");
	printf("早                   早                                                 早       旨收收旬        早\n");
	printf("早     旨收收收收旬        早                                                 早       早 X早        早\n");
	printf("早     早 ∟ 早        早                                                 早       曲收收旭        早\n");
	printf("早     早    早        早                                                 早   旨收收旬    旨收收旬    早\n");
	printf("早 旨收收收旭    曲收收收旬    早                                                 早   早 Y早    早 A早    早\n");
	printf("早 早 ∠       ⊥早    早                                                 早   曲收收旭    曲收收旭    早\n");
	printf("早 曲收收收旬    旨收收收旭    早                                                 早       旨收收旬        早\n");
	printf("早     早    早        早                                                 早       早 B早        早\n");
	printf("早     早 ⊿ 早        早                                                 早       曲收收旭        早\n");
	printf("早     曲收收收收旭        早                                                 早 佺return          早\n");
	printf("早                   早                                                 早 供 謙猿           早\n");
	printf("早                   曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭                   早\n");
	printf("早                                                                                         早\n");
	printf("早                                                                                         早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	gotoxy(50, 42);
}
int memo()
{
	char n;
	gotoxy(21, 26);
	printf("忙收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收忖\n");
	gotoxy(21, 27);
	printf("弛                                               弛\n");
	gotoxy(21, 28);
	printf("弛                                               弛\n");
	gotoxy(21, 29);
	printf("戌收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收戎\n");
	gotoxy(39, 27);
	printf("Щ煎薛お 模偃憮");
	gotoxy(21, 30);
	printf("忙收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收忖\n");
	gotoxy(21, 31);
	printf("弛                                               弛\n");
	gotoxy(21, 32);
	printf("弛                                               弛\n");
	gotoxy(21, 33);
	printf("戌收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收戎\n");
	gotoxy(45, 32);
	printf("啪歜");
	gotoxy(21, 34);
	printf("忙收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收忖\n");
	gotoxy(21, 35);
	printf("弛                                               弛\n");
	gotoxy(21, 36);
	printf("弛                                               弛\n");
	gotoxy(21, 37);
	printf("戌收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收戎\n");
	gotoxy(45, 36);
	printf("轎籀");
	gotoxy(50, 42);
}
int Nintendo()
{
	view();
	int Loop = 0;
	gotoxy(48, 10);
	printf("忙收收收收收收收收收收收收收收收收收收忖\n");
	gotoxy(48, 11);
	printf("弛                  弛\n");
	gotoxy(48, 12);
	printf("戌收收收收收收收收收收收收收收收收收收戎\n");
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
		char str[30] = "摹鷗璽擊 褒чж啊蝗棲棻.";
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
	printf("Щ煎薛お 貲 : Nintendo game");
	gotoxy(22, 5);
	printf("ぜ 模偃 : (偃嫦 霤罹濠 : 螃嶸雙,槳薑團)");
	gotoxy(22, 6);
	printf("Щ煎薛お 碟撿 : 啪歜");
	gotoxy(22, 7);
	printf("Щ煎薛お 晦棟 : 2偃曖 Яж晦 啪歜, ん鰍跨 啪歜");
	gotoxy(22, 8);
	printf("Щ煎薛お 僥薯薄 : 摹鷗璽擊 褒чж艘擊陽");
	gotoxy(40, 9);
	printf("и廓渦 褒чж罹撿 л(п唸)");
	gotoxy(45, 15);
	printf("謙猿 幗が : (e/E)");
	gotoxy(45, 16);
	printf("return 幗が : (r/R)");
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
	printf("忙收收收收收收收收收收收收收收收收收收收忖\n");
	gotoxy(24, 12);
	printf("弛                   弛\n");
	gotoxy(24, 13);
	printf("戌收收收收收收收收收收收收收收收收收收收戎");
	gotoxy(29, 12);
	printf("Яж晦 啪歜");
	gotoxy(50, 11);
	printf("忙收收收收收收收收收收收收收收收收收收忖\n");
	gotoxy(50, 12);
	printf("弛                  弛\n");
	gotoxy(50, 13);
	printf("戌收收收收收收收收收收收收收收收收收收戎");
	gotoxy(56, 12);
	printf("Pokemon 啪歜");
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
	printf("轎籀 : Google,yotube");
	gotoxy(22, 5);
	gotoxy(45, 15);
	printf("謙猿 幗が : (e/E)");
	gotoxy(45, 16);
	printf("return 幗が : (r/R)");
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
	printf("===Яж晦 啪歜====\n");
	gotoxy(35, 9);
	printf("  1.啪歜 衛濛(Яж晦1)\n");
	gotoxy(35, 10);
	printf("  2.啪歜 衛濛(Яж晦2)\n");
	gotoxy(35, 11);
	printf("  3.啪歜 謙猿\n");
	gotoxy(35, 12);
	printf("  4.啪歜 摹鷗璽 給嬴晦晦\n");
	gotoxy(35, 13);
	scanf("%d", &s);
	if (s == 1)
	{
		int i, j;
		int nowtime;
		int pasttime;
		i = 0;
		j = 0;
		//避歷朝雖 寰避歷朝雖 轎溘, 避歷戲賊 0, 髦懊戲賊 1
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
				draw();//�飛橦� Ы溯檜橫諦 錳蒂 轎溘и棻.
				nowtime = GetTickCount();
			}
			movebelt();//錳曖 高擊 滲唳и棻
			draw();//錳 高 滲唳�� 轎溘
			doa = checkplayerpos();//Ы溯檜橫曖 高擊 羹觼и棻. 錳縑 濰擁僭婁 Ы溯檜橫陛 偽擎 嬪纂縑 氈棻賊 break
			if (doa == 0) break;//檜剪 鱔婁ж賊 寰避擎匙 啗樓 霞чп紫脾
		}
		gotoxy(33, 15);
		printf("睡詠⑵幗溜棻!");
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
			fflush(stdin); //幗ぷ 雖錶輿朝匙
			scanf("%d", &select);
			system("cls");

			switch (select)
			{
			case 1:
				tmpScore = gameStart();
				break;
			case 2:
				if (maxScore < tmpScore) maxScore = tmpScore;
				printf("  譆堅 薄熱朝 %d 殮棲棻 \n", maxScore);
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
	printf("錳 Яж晦 啪歜!\n");;
	gotoxy(30, 5);
	printf("嬪,嬴楚 幗が戲煎 遺霜橾 熱 氈棻.\n\n");;
	textcolor(3);
	gotoxy(30, 7);
	if (playerpos == 1)
	{
		printf("Ⅱ");
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
		printf("Ⅱ");
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
	puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
	gotoxy(25, 5);
	puts("早         璋濠 Яж晦 啪歜      早");
	gotoxy(25, 6);
	puts("早                               早");
	gotoxy(25, 7);
	puts("早          0. 謙     猿         早");
	gotoxy(25, 8);
	puts("早                               早");
	gotoxy(25, 9);
	puts("早          1. 啪歜 Ы溯檜       早");
	gotoxy(25, 10);
	puts("早                               早");
	gotoxy(25, 11);
	puts("早          2. 譆堅 薄熱         早");
	gotoxy(25, 12);
	puts("早                               早");
	gotoxy(25, 13);
	puts("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
	gotoxy(25, 14);
	printf(" Select > ");
}
void levelMenu()
{
	Nintendo2();
	textcolor(10);
	gotoxy(25, 4);
	puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
	gotoxy(25, 5);
	puts("早         陪檜紫 摹鷗        早");
	gotoxy(25, 6);
	puts("早                            早");
	gotoxy(25, 7);
	puts("早         0. 詭檣            早");
	gotoxy(25, 8);
	puts("早                            早");
	gotoxy(25, 9);
	puts("早         1. 蓮遺            早");
	gotoxy(25, 10);
	puts("早                            早");
	gotoxy(25, 11);
	puts("早         2. 醞除            早");
	gotoxy(25, 12);
	puts("早                            早");
	gotoxy(25, 13);
	puts("早         3. 橫溥遺          早");
	gotoxy(25, 14);
	puts("早                            早");
	gotoxy(25, 15);
	puts("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
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

	while (1)//樓紫褻瞰
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
	while (1)//轎溘, 渠晦, 蝶Яお, 遺霜歜 啗樓奩犒
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
					printf("\b ");//寥蝶む檜蝶夥
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
							printf("薄熱 : %d ", score);
						}
					}
				}
			}
		}
		Sleep(5);

		gotoxy(playerX, playerY);
		printf("十");

		if (kbhit())//kbhit 揚溜朝雖 寰揚溜朝雖 鼻鷓
		{
			ch = getch();
			switch (ch)
			{
			case 75:
				if (playerX > 22)
				{

					playerX--;
					gotoxy(playerX, playerY);
					printf("十");
					gotoxy(playerX + 1, playerY);
					printf("  ");
				}
				break;
			case 77:
				if (playerX < 66)
				{

					playerX++;
					gotoxy(playerX, playerY);
					printf("十");
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
	printf("謙猿 幗が : (e/E)");
	gotoxy(45, 16);
	printf("return 幗が : (r/R)");
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
	printf("謙猿 幗が : (e/E)");
	gotoxy(45, 16);
	printf("return 幗が : (r/R)");
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
	printf("-------ん鰍跨--------\n");
	gotoxy(33, 8);
	printf("  1.啪歜 摹鷗璽 給嬴晦晦\n");
	gotoxy(33, 9);
	printf("  2. ん鰍跨 啪歜 璽 褒ч\n");
	gotoxy(33, 10);
	printf("  3. 啪歜 謙猿\n");
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
	printf("[1.億煎遴 賅я擊 衛濛ж衛啊蝗棲梱?]");
	gotoxy(30, 9);
	printf("[2.謙猿ж晦]");
	gotoxy(30, 10);
	scanf("%d", &n);
	if (n == 1)
	{
		system("cls");
		Nintendo2();
		Sleep(100);
		gotoxy(33, 10);
		printf("啪歜擊 碳楝褫棲棻.\n");
		Sleep(100);
		system("cls");
		Nintendo2();
		gotoxy(33, 10);
		printf("啪歜擊 碳楝褫棲棻..\n");
		system("cls");
		Nintendo2();
		gotoxy(33, 10);
		printf("啪歜擊 碳楝褫棲棻...\n");
		Sleep(100);
		system("cls");
		Nintendo2();
		gotoxy(33, 10);
		printf("啪歜擊 碳楝褫棲棻....\n");
		Sleep(100);
		system("cls");
		Nintendo2();
		gotoxy(33, 10);
		printf("啪歜擊 碳楝褫棲棻.....\n");
		Sleep(100);
		system("cls");
		Nintendo2();
		b = 1;
		char print_temp[200];
		char file_path[200];
		FILE* f;
		sprintf(file_path, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\螃夢餌.txt");
		f = fopen(file_path, "r");
		gotoxy(100, 1);
		for (int i = 0; i < 40; i++)
		{
			gotoxy(100, i + 1);
			fgets(print_temp, 200, f);
			printf("%s", print_temp);
		}
		gotoxy(33, 15);
		char str[30] = "寰喟 釭朝 螃夢餌塭堅 п";
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
		sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\螃夢餌.txt");
		f1 = fopen(file_path1, "r");
		gotoxy(100, 1);
		for (int i = 0; i < 40; i++)
		{
			gotoxy(100, i + 1);
			fgets(print_temp, 200, f1);
			printf("%s", print_temp);
		}
		gotoxy(33, 15);
		char str1[30] = "賅舒菟 ん鰍跨 夢餌塭堅 睡腦雖";
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
		char str2[30] = "傘縑 渠п 憲嬴 獐梱?";
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
		sprintf(file_path2, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\1.txt");
		f2 = fopen(file_path2, "r");
		gotoxy(100, 1);
		for (int i = 0; i < 40; i++)
		{
			gotoxy(100, i + 1);
			fgets(print_temp, 200, f2);
			printf("%s", print_temp);
		}
		gotoxy(33, 14);
		char str3[30] = "傘朝 陴濠棲 嬴椒 罹濠棲?";
		int size3;
		size3 = sizeof(str3) / sizeof(str3[0]);
		for (int i = 0; i < size3; i++)
		{
			Sleep(35);
			printf("%c", str3[i]);
		}
		gotoxy(33, 15);
		printf("1.陴濠 2.罹濠");
		gotoxy(33, 16);
		scanf("%d", &t);
		system("cls");
		Nintendo2();
		if (t == 1)
		{
			char print_temp[200];
			char file_path[200];
			FILE* f;
			sprintf(file_path, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\陴濠.txt");
			f = fopen(file_path, "r");
			gotoxy(100, 1);
			for (int i = 0; i < 40; i++)
			{
				gotoxy(100, i + 1);
				fgets(print_temp, 200, f);
				printf("%s", print_temp);
			}
			gotoxy(33, 15);
			char str3[15] = "陴濠煎掘釭?";
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
			sprintf(file_path, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\罹濠.txt");
			f = fopen(file_path, "r");
			gotoxy(100, 1);
			for (int i = 0; i < 35; i++)
			{
				gotoxy(100, i + 1);
				fgets(print_temp, 200, f);
				printf("%s", print_temp);
			}
			gotoxy(33, 15);
			char str3[15] = "罹濠煎掘釭?";
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
		char str10[30] = "傘曖 檜葷擎 鼠歙檜棲?";
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
		printf("傘曖 檜葷擎 %s檜掘釭", n);
		Sleep(1000);
		system("cls");
		Nintendo2();
		char print_temp3[200];
		char file_path3[200];
		FILE* f3;
		sprintf(file_path, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\ん鰍跨.txt");
		f3 = fopen(file_path, "r");
		gotoxy(100, 1);
		for (int i = 0; i < 20; i++)
		{
			gotoxy(100, i + 1);
			fgets(print_temp, 200, f3);
			printf("%s", print_temp);
		}
		gotoxy(30, 15);
		char str7[30] = "傘諦 л眷й ん鰍跨擊 埤塭獐楚?";
		int size7;
		size7 = sizeof(str7) / sizeof(str7[0]);
		for (int i = 0; i < size7; i++)
		{
			Sleep(35);
			printf("%c", str7[i]);
		}
		gotoxy(39, 28);
		printf("[1]だ檜葬");
		gotoxy(39, 32);
		printf("[2]窒睡晦");
		gotoxy(39, 36);
		printf("[3]檜鼻п噢");
		gotoxy(39, 37);
		scanf("%d", &menu);
		if (menu == 1)
		{
			system("cls");
			Nintendo2();
			char print_temp[200];
			char file_path[200];
			FILE* f;
			sprintf(file_path, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\だ檜葬.txt");
			f = fopen(file_path, "r");
			gotoxy(100, 1);
			for (int i = 0; i < 30; i++)
			{
				gotoxy(100, i + 1);
				fgets(print_temp, 200, f);
				printf("%s", print_temp);
			}
			gotoxy(33, 15);
			char str8[30] = "だ檜葬蒂 摹鷗ц掘釭!";
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
			sprintf(file_path, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\窒睡晦.txt");
			f = fopen(file_path, "r");
			gotoxy(100, 1);
			for (int i = 0; i < 30; i++)
			{
				gotoxy(100, i + 1);
				fgets(print_temp, 200, f);
				printf("%s", print_temp);
			}
			gotoxy(33, 15);
			char str9[30] = "窒睡晦蒂 摹鷗ц掘釭!";
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
			sprintf(file_path, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\檜鼻п噢.txt");
			f = fopen(file_path, "r");
			gotoxy(100, 1);
			for (int i = 0; i < 30; i++)
			{
				gotoxy(100, i + 1);
				fgets(print_temp, 200, f);
				printf("%s", print_temp);
			}
			gotoxy(33, 15);
			char str10[30] = "檜鼻п噢蒂 摹鷗ц掘釭!";
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
		char str11[30] = "賅я擊 й 遽綠陛 腎歷棲?";
		int size11;
		size11 = sizeof(str11) / sizeof(str11[0]);
		for (int i = 0; i < size11; i++)
		{
			Sleep(35);
			printf("%c", str11[i]);
		}
		gotoxy(33, 14);
		printf("[1.啻] [2.嬴棲螃]");
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
			char str11[50] = "罹薑縑 в蹂и 議衛,跨蝶攪獐,鼻籀擒擊 輿啊啻";
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
			printf("議衛 %d錳 歷歷蝗棲棻", cash);
			gotoxy(33, 15);
			Sleep(1000);
			printf("跨蝶攪獐 %d偃蒂 歷歷蝗棲棻", monsterball);
			gotoxy(33, 16);
			Sleep(1000);
			printf("鼻籀擒 %d偃蒂 歷歷蝗棲棻", vulnerary);
			Sleep(1000);
			system("cls");
			Nintendo2();
			gotoxy(33, 4);
			printf("------player薑爾-----");
			gotoxy(33, 5);
			printf("檜葷 : ooo");
			gotoxy(33, 6);
			printf("議衛 : %d錳", cash);
			gotoxy(33, 7);
			printf("察雖 : 0偃");
			gotoxy(33, 8);
			printf("跨蝶攪獐 : %d偃", monsterball);
			gotoxy(33, 9);
			printf("鼻籀擒 : %d偃", vulnerary);
			gotoxy(33, 10);
			printf("------翕ч ん鰍跨 薑爾-----");
			if (menu == 1)
			{
				gotoxy(33, 11);
				printf("檜葷 : だ檜葬");
				gotoxy(33, 12);
				printf("HP : 100");
				gotoxy(33, 13);
				printf("power : 20");
			}
			if (menu == 2)
			{
				gotoxy(33, 11);
				printf("檜葷 : 窒睡晦");
				gotoxy(33, 12);
				printf("HP : 100");
				gotoxy(33, 13);
				printf("power : 20");
			}
			if (menu == 3)
			{
				gotoxy(33, 11);
				printf("檜葷 : 檜鼻п噢");
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
			char str[50] = "闌剪遴 罹薑檜 腎晦蒂 網啊啻.^^";
			int size;
			size = sizeof(str) / sizeof(str[0]);
			for (int i = 0; i < size11; i++)
			{
				Sleep(35);
				printf("%c", str[i]);
			}
		r:
			gotoxy(33, 14);
			printf("葆擊煎 檜翕ж衛啊蝗棲梱?");
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
				printf("(A) ん鰍跨 撫攪 (B) 餌傖攪 (X) 鼻薄 (Y) 羹幫婦");
				gotoxy(40, 11);
				printf("﹤ X ﹤");
				gotoxy(40, 12);
				printf("Y ﹤ A");
				gotoxy(40, 13);
				printf("﹤ B ﹤");
				gotoxy(40, 14);
				scanf(" %c", &u);
				if (u == 'a' || u == 'A')
				{
					system("cls");
					Nintendo2();
					Sleep(100);
					gotoxy(33, 10);
					printf("ん鰍跨 撫攪 檜翕醞.\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("ん鰍跨 撫攪 檜翕醞..\n");
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("ん鰍跨 撫攪 檜翕醞...\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("ん鰍跨 撫攪 檜翕醞....\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("ん鰍跨 撫攪 檜翕醞.....\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					gotoxy(33, 11);
					printf("ん鰍跨 撫攪 紫雜");
					Sleep(500);
					system("cls");
					Nintendo2();
					char print_temp[200];
					char file_path[200];
					FILE* f;
					sprintf(file_path, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\ん鰍跨 撫攪.txt");
					f = fopen(file_path, "r");
					for (int i = 0; i < 25; i++)
					{
						gotoxy(100, i + 1);
						fgets(print_temp, 200, f);
						printf("%s", print_temp);
					}
					char c;
					gotoxy(32, 11);
					printf("ん鰍跨擊 �蛹嘎牮簸睍懂炱�?");
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
						printf("鼻籀 �蛹嘗�.\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("鼻籀 �蛹嘗�..\n");
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("鼻籀 �蛹嘗�...\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("鼻籀 �蛹嘗�....\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("鼻籀 �蛹嘗�.....\n");
						system("cls");
						Nintendo2();
						gotoxy(33, 15);
						int n;
						char str[50] = "渡褐曖 ん鰍跨檜 賅舒 �虜騊Ц�蝗棲棻.";
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
						printf("棻擠縑 檜辨п輿撮蹂..");
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
						printf("ヴ 膛擊 鬚я醞.\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("ヴ 膛擊 鬚я醞..\n");
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("ヴ 膛擊 鬚я醞...\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("ヴ 膛擊 鬚я醞....\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("ヴ 膛擊 鬚я醞.....\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						char print_temp[200];
						char file_path[200];
						FILE* f;
						sprintf(file_path, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\窒滇.txt");
						f = fopen(file_path, "r");
						gotoxy(100, 1);
						for (int i = 0; i < 50; i++)
						{
							gotoxy(100, i + 1);
							fgets(print_temp, 200, f);
							printf("%s", print_temp);
						}
						gotoxy(33, 11);
						char str[50] = "撿儅曖 窒滇檜 釭顫陬棻!!";
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
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\だ檜葬.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "陛嫁 だ檜葬!!";
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
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\窒睡晦.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "陛嫁 窒睡晦!!";
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
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\檜鼻п噢.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "陛嫁 檜鼻п噢!!";
							int size1;
							size1 = sizeof(str1) / sizeof(str1[0]);
							for (int i = 0; i < size1; i++)
							{
								Sleep(50);
								printf("%c", str1[i]);
							}Sleep(100);
						}
						gotoxy(33, 12);
						char str2[50] = "橫雯 ч翕擊 ж衛啊蝗棲梱?";
						int size2;
						size2 = sizeof(str2) / sizeof(str2[0]);
						for (int i = 0; i < size2; i++)
						{
							Sleep(50);
							printf("%c", str2[i]);
						}Sleep(100);
						int r;
						gotoxy(40, 28);
						printf("[1] 寡ぎ");
						gotoxy(22, 35);
						printf("[2] 陛寞");
						gotoxy(40, 35);
						printf("[3] 紫蜂除棻");
						gotoxy(58, 35);
						printf("[4] ん鰍跨");
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
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\だ檜葬.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===だ檜葬===");
								gotoxy(22, 30);
								printf("[1] 跺鱔夢纂晦");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("だ檜葬曖 跺鱔夢纂晦");
									gotoxy(33, 15);
									printf("窒滇擎 等嘐雖 8 擊 殮歷棻.");
									gotoxy(33, 16);
									printf("窒滇曖 hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									system("cls");
									Nintendo2();
									gotoxy(33, 14);
									printf("窒滇曖 瞪惜戮��");
									gotoxy(33, 15);
									printf("だ檜葬朝 等嘐雖 6擊 殮歷棻.");
									gotoxy(33, 16);
									printf("だ檜葬曖 hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
									int r;
								f:
									system("cls");
									Nintendo2();
									gotoxy(33, 12);
									char str2[50] = "橫雯 ч翕擊 ж衛啊蝗棲梱?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] 寡ぎ");
									gotoxy(22, 35);
									printf("[2] 陛寞");
									gotoxy(40, 35);
									printf("[3] 紫蜂除棻");
									gotoxy(58, 35);
									printf("[4] ん鰍跨");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 13);
										printf("だ檜葬曖 跺鱔夢纂晦");
										gotoxy(33, 14);
										printf("窒滇擎 等嘐雖 8 擊 殮歷棻.");
										gotoxy(33, 15);
										printf("窒滇曖 hp : [7]->[0]");
										gotoxy(33, 16);
										printf("窒滇擎 噙楝螺棻!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\だ檜葬.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20曖 唳я纂蒂 橢歷蝗棲棻.");
										gotoxy(33, 15);
										char str2[50] = "だ檜葬朝 溯漣 7檜 腎歷蝗棲棻.";
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
										printf("闌剪遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										system("cls");
										Nintendo2();
										int n;
										gotoxy(40, 28);
										printf("==陛寞==");
										gotoxy(40, 29);
										printf("[1] ん鰍跨 獐 : 5偃");
										gotoxy(40, 30);
										printf("[2] 鼻籀擒 : 5偃");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ん鰍跨獐擊 餌辨ж艘棻");
											gotoxy(33, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(35, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≠");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("撿儅 窒滇擊 濩懊棻!");
											Sleep(100);
											gotoxy(33, 16);
											printf("紫馬縑 蛔煙 腌棲棻.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("闌剪遴 賅я檜艘棻.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�蛹嗾鈶� 餌辨ж艘蝗棲棻.");
											gotoxy(33, 16);
											printf("だ檜葬曖 hp陛 賅舒 �蛹僱Ц�蝗棲棻.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("撿儅 窒滇戲煎 睡攪 紫蜂蟻棻!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("嬴蓮遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("ん鰍跨檜 橈蝗棲棻!!");
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
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\窒睡晦.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===窒睡晦===");
								gotoxy(22, 30);
								printf("[1] 跺鱔夢纂晦");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("窒睡晦曖 跺鱔夢纂晦");
									gotoxy(33, 15);
									printf("窒滇擎 等嘐雖 8 擊 殮歷棻.");
									gotoxy(33, 16);
									printf("窒滇曖 hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									system("cls");
									Nintendo2();
									gotoxy(33, 14);
									printf("窒滇曖 瞪惜戮��");
									gotoxy(33, 15);
									printf("窒睡晦朝 等嘐雖 6擊 殮歷棻.");
									gotoxy(33, 16);
									printf("窒睡晦曖 hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
									int r;
								t:
									system("cls");
									Nintendo2();
									gotoxy(33, 12);
									char str2[50] = "橫雯 ч翕擊 ж衛啊蝗棲梱?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] 寡ぎ");
									gotoxy(22, 35);
									printf("[2] 陛寞");
									gotoxy(40, 35);
									printf("[3] 紫蜂除棻");
									gotoxy(58, 35);
									printf("[4] ん鰍跨");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 13);
										printf("窒睡晦曖 跺鱔夢纂晦");
										gotoxy(33, 14);
										printf("窒滇擎 等嘐雖 8 擊 殮歷棻.");
										gotoxy(33, 15);
										printf("窒滇曖 hp : [7]->[0]");
										gotoxy(33, 16);
										printf("窒滇擎 噙楝螺棻!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\窒睡晦.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20曖 唳я纂蒂 橢歷蝗棲棻.");
										gotoxy(33, 15);
										char str2[50] = "窒睡晦朝 溯漣 7檜 腎歷蝗棲棻.";
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
										printf("闌剪遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										system("cls");
										Nintendo2();
										int n;
										gotoxy(40, 28);
										printf("==陛寞==");
										gotoxy(40, 29);
										printf("[1] ん鰍跨 獐 : 5偃");
										gotoxy(40, 30);
										printf("[2] 鼻籀擒 : 5偃");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ん鰍跨獐擊 餌辨ж艘棻");
											gotoxy(33, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(35, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≠");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("撿儅 窒滇擊 濩懊棻!");
											Sleep(1000);
											gotoxy(33, 16);
											printf("紫馬縑 蛔煙 腌棲棻.");
											Sleep(100);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("闌剪遴 賅я檜艘棻.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�蛹嗾鈶� 餌辨ж艘蝗棲棻.");
											gotoxy(33, 16);
											printf("だ檜葬曖 hp陛 賅舒 �蛹僱Ц�蝗棲棻.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("撿儅 窒滇戲煎 睡攪 紫蜂蟻棻!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("嬴蓮遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("ん鰍跨檜 橈蝗棲棻!!");
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
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\檜鼻п噢.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===檜鼻п噢===");
								gotoxy(22, 30);
								printf("[1] 跺鱔夢纂晦");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("檜鼻п噢曖 跺鱔夢纂晦");
									gotoxy(33, 15);
									printf("窒滇擎 等嘐雖 8 擊 殮歷棻.");
									gotoxy(33, 16);
									printf("窒滇曖 hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									gotoxy(33, 14);
									printf("窒滇曖 瞪惜戮��");
									gotoxy(33, 15);
									printf("檜鼻п噢朝 等嘐雖 6擊 殮歷棻.");
									gotoxy(33, 16);
									printf("檜鼻п噢曖 hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
								x:
									system("cls");
									Nintendo2();
									int r;
									gotoxy(33, 12);
									char str2[50] = "橫雯 ч翕擊 ж衛啊蝗棲梱?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] 寡ぎ");
									gotoxy(22, 35);
									printf("[2] 陛寞");
									gotoxy(40, 35);
									printf("[3] 紫蜂除棻");
									gotoxy(58, 35);
									printf("[4] ん鰍跨");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 13);
										printf("檜鼻п噢曖 跺鱔夢纂晦");
										gotoxy(33, 14);
										printf("窒滇擎 等嘐雖 8 擊 殮歷棻.");
										gotoxy(33, 15);
										printf("窒滇曖 hp : [7]->[0]");
										gotoxy(33, 16);
										printf("窒滇擎 噙楝螺棻!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\檜鼻п噢.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20曖 唳я纂蒂 橢歷蝗棲棻.");
										gotoxy(33, 15);
										char str2[50] = "檜鼻п噢朝 溯漣 7檜 腎歷蝗棲棻.";
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
										printf("闌剪遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										system("cls");
										Nintendo2();
										int n;
										gotoxy(40, 28);
										printf("==陛寞==");
										gotoxy(40, 29);
										printf("[1] ん鰍跨 獐 : 5偃");
										gotoxy(40, 30);
										printf("[2] 鼻籀擒 : 5偃");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ん鰍跨獐擊 餌辨ж艘棻");
											gotoxy(33, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(35, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≠");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("撿儅 窒滇擊 濩懊棻!");
											Sleep(100);
											gotoxy(33, 16);
											printf("紫馬縑 蛔煙 腌棲棻.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("闌剪遴 賅я檜艘棻.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�蛹嗾鈶� 餌辨ж艘蝗棲棻.");
											gotoxy(33, 16);
											printf("だ檜葬曖 hp陛 賅舒 �蛹僱Ц�蝗棲棻.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("撿儅 窒滇戲煎 睡攪 紫蜂蟻棻!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("嬴蓮遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("ん鰍跨檜 橈蝗棲棻!!");
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
						printf("ヴ 膛擊 鬚я醞.\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("ヴ 膛擊 鬚я醞..\n");
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("ヴ 膛擊 鬚я醞...\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("ヴ 膛擊 鬚я醞....\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("ヴ 膛擊 鬚я醞.....\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						char print_temp[200];
						char file_path[200];
						FILE* f;
						sprintf(file_path, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\掘掘.txt");
						f = fopen(file_path, "r");
						gotoxy(100, 1);
						for (int i = 0; i < 35; i++)
						{
							gotoxy(100, i + 1);
							fgets(print_temp, 200, f);
							printf("%s", print_temp);
						}
						gotoxy(33, 11);
						char str[50] = "撿儅曖 掘掘陛 釭顫陬棻!!";
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
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\だ檜葬.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "陛嫁 だ檜葬!!";
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
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\窒睡晦.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "陛嫁 窒睡晦!!";
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
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\檜鼻п噢.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "陛嫁 檜鼻п噢!!";
							int size1;
							size1 = sizeof(str1) / sizeof(str1[0]);
							for (int i = 0; i < size1; i++)
							{
								Sleep(50);
								printf("%c", str1[i]);
							}Sleep(100);
						}
						gotoxy(33, 12);
						char str2[50] = "橫雯 ч翕擊 ж衛啊蝗棲梱?";
						int size2;
						size2 = sizeof(str2) / sizeof(str2[0]);
						for (int i = 0; i < size2; i++)
						{
							Sleep(50);
							printf("%c", str2[i]);
						}Sleep(100);
						int r;
						gotoxy(40, 28);
						printf("[1] 寡ぎ");
						gotoxy(22, 35);
						printf("[2] 陛寞");
						gotoxy(40, 35);
						printf("[3] 紫蜂除棻");
						gotoxy(58, 35);
						printf("[4] ん鰍跨");
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
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\だ檜葬.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===だ檜葬===");
								gotoxy(22, 30);
								printf("[1] 跺鱔夢纂晦");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("だ檜葬曖 跺鱔夢纂晦");
									gotoxy(33, 15);
									printf("掘掘朝 等嘐雖 8 擊 殮歷棻.");
									gotoxy(33, 16);
									printf("窒滇曖 hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									system("cls");
									Nintendo2();
									gotoxy(33, 14);
									printf("掘掘曖 瞪惜戮��");
									gotoxy(33, 15);
									printf("だ檜葬朝 等嘐雖 6擊 殮歷棻.");
									gotoxy(33, 16);
									printf("だ檜葬曖 hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
									int r;
								o:
									system("cls");
									Nintendo2();
									gotoxy(33, 12);
									char str2[50] = "橫雯 ч翕擊 ж衛啊蝗棲梱?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] 寡ぎ");
									gotoxy(22, 35);
									printf("[2] 陛寞");
									gotoxy(40, 35);
									printf("[3] 紫蜂除棻");
									gotoxy(58, 35);
									printf("[4] ん鰍跨");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										gotoxy(33, 13);
										printf("だ檜葬曖 跺鱔夢纂晦");
										gotoxy(33, 14);
										printf("掘掘朝 等嘐雖 8 擊 殮歷棻.");
										gotoxy(33, 15);
										printf("掘掘曖 hp : [7]->[0]");
										gotoxy(33, 16);
										printf("掘掘朝 噙楝螺棻!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\だ檜葬.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20曖 唳я纂蒂 橢歷蝗棲棻.");
										gotoxy(33, 15);
										char str2[50] = "だ檜葬朝 溯漣 7檜 腎歷蝗棲棻.";
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
										printf("闌剪遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										int n;
										system("cls");
										Nintendo2();
										gotoxy(40, 28);
										printf("==陛寞==");
										gotoxy(40, 29);
										printf("[1] ん鰍跨 獐 : 5偃");
										gotoxy(40, 30);
										printf("[2] 鼻籀擒 : 5偃");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ん鰍跨獐擊 餌辨ж艘棻");
											gotoxy(33, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(35, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≠");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("撿儅 掘掘蒂 濩懊棻!");
											Sleep(100);
											gotoxy(33, 16);
											printf("紫馬縑 蛔煙 腌棲棻.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("闌剪遴 賅я檜艘棻.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�蛹嗾鈶� 餌辨ж艘蝗棲棻.");
											gotoxy(33, 16);
											printf("だ檜葬曖 hp陛 賅舒 �蛹僱Ц�蝗棲棻.");
										}
									}
									if (b == 3)
									{
										gotoxy(33, 15);
										printf("撿儅 掘掘煎 睡攪 紫蜂蟻棻!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("嬴蓮遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("ん鰍跨檜 橈蝗棲棻!!");
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
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\窒睡晦.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===窒睡晦===");
								gotoxy(22, 30);
								printf("[1] 跺鱔夢纂晦");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("窒睡晦曖 跺鱔夢纂晦");
									gotoxy(33, 15);
									printf("掘掘朝 等嘐雖 8 擊 殮歷棻.");
									gotoxy(33, 16);
									printf("掘掘曖 hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									system("cls");
									Nintendo2();
									gotoxy(33, 14);
									printf("掘掘曖 瞪惜戮��");
									gotoxy(33, 15);
									printf("窒睡晦朝 等嘐雖 6擊 殮歷棻.");
									gotoxy(33, 16);
									printf("窒睡晦曖 hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
									int r;
								v:
									system("cls");
									Nintendo2();
									gotoxy(33, 12);
									char str2[50] = "橫雯 ч翕擊 ж衛啊蝗棲梱?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] 寡ぎ");
									gotoxy(22, 35);
									printf("[2] 陛寞");
									gotoxy(40, 35);
									printf("[3] 紫蜂除棻");
									gotoxy(58, 35);
									printf("[4] ん鰍跨");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										gotoxy(33, 13);
										printf("窒睡晦曖 跺鱔夢纂晦");
										gotoxy(33, 14);
										printf("掘掘朝 等嘐雖 8 擊 殮歷棻.");
										gotoxy(33, 15);
										printf("掘掘曖 hp : [7]->[0]");
										gotoxy(33, 16);
										printf("掘掘朝 噙楝螺棻!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\窒睡晦.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20曖 唳я纂蒂 橢歷蝗棲棻.");
										gotoxy(33, 15);
										char str2[50] = "窒睡晦朝 溯漣 7檜 腎歷蝗棲棻.";
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
										printf("闌剪遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										int n;
										system("cls");
										Nintendo2();
										gotoxy(40, 28);
										printf("==陛寞==");
										gotoxy(40, 29);
										printf("[1] ん鰍跨 獐 : 5偃");
										gotoxy(40, 30);
										printf("[2] 鼻籀擒 : 5偃");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ん鰍跨獐擊 餌辨ж艘棻");
											gotoxy(33, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(35, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≠");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("撿儅 掘掘蒂 濩懊棻!");
											Sleep(100);
											gotoxy(33, 16);
											printf("紫馬縑 蛔煙 腌棲棻.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("闌剪遴 賅я檜艘棻.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�蛹嗾鈶� 餌辨ж艘蝗棲棻.");
											gotoxy(33, 16);
											printf("だ檜葬曖 hp陛 賅舒 �蛹僱Ц�蝗棲棻.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("撿儅 掘掘煎 睡攪 紫蜂蟻棻!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("嬴蓮遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("ん鰍跨檜 橈蝗棲棻!!");
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
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\檜鼻п噢.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===檜鼻п噢===");
								gotoxy(22, 30);
								printf("[1] 跺鱔夢纂晦");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("檜鼻п噢曖 跺鱔夢纂晦");
									gotoxy(33, 15);
									printf("掘掘朝 等嘐雖 8 擊 殮歷棻.");
									gotoxy(33, 16);
									printf("掘掘曖 hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									gotoxy(33, 14);
									printf("掘掘曖 瞪惜戮��");
									gotoxy(33, 15);
									printf("檜鼻п噢朝 等嘐雖 6擊 殮歷棻.");
									gotoxy(33, 16);
									printf("檜鼻п噢曖 hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
								h:
									system("cls");
									Nintendo2();
									int r;
									gotoxy(33, 12);
									char str2[50] = "橫雯 ч翕擊 ж衛啊蝗棲梱?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] 寡ぎ");
									gotoxy(22, 35);
									printf("[2] 陛寞");
									gotoxy(40, 35);
									printf("[3] 紫蜂除棻");
									gotoxy(58, 35);
									printf("[4] ん鰍跨");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										gotoxy(33, 13);
										printf("檜鼻п噢曖 跺鱔夢纂晦");
										gotoxy(33, 14);
										printf("掘掘朝 等嘐雖 8 擊 殮歷棻.");
										gotoxy(33, 15);
										printf("掘掘曖 hp : [7]->[0]");
										gotoxy(33, 16);
										printf("掘掘擎 噙楝螺棻!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\檜鼻п噢.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20曖 唳я纂蒂 橢歷蝗棲棻.");
										gotoxy(33, 15);
										char str2[50] = "檜鼻п噢朝 溯漣 7檜 腎歷蝗棲棻.";
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
										printf("闌剪遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										int n;
										system("cls");
										Nintendo2();
										gotoxy(40, 28);
										printf("==陛寞==");
										gotoxy(40, 29);
										printf("[1] ん鰍跨 獐 : 5偃");
										gotoxy(40, 30);
										printf("[2] 鼻籀擒 : 5偃");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ん鰍跨獐擊 餌辨ж艘棻");
											gotoxy(33, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(35, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≠");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("撿儅 掘掘蒂 濩懊棻!");
											Sleep(100);
											gotoxy(33, 16);
											printf("紫馬縑 蛔煙 腌棲棻.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("闌剪遴 賅я檜艘棻.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�蛹嗾鈶� 餌辨ж艘蝗棲棻.");
											gotoxy(33, 16);
											printf("だ檜葬曖 hp陛 賅舒 �蛹僱Ц�蝗棲棻.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("撿儅 掘掘煎 睡攪 紫蜂蟻棻!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("嬴蓮遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("ん鰍跨檜 橈蝗棲棻!!");
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
						printf("ヴ 膛擊 鬚я醞.\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("ヴ 膛擊 鬚я醞..\n");
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("ヴ 膛擊 鬚я醞...\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("ヴ 膛擊 鬚я醞....\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						gotoxy(33, 10);
						printf("ヴ 膛擊 鬚я醞.....\n");
						Sleep(100);
						system("cls");
						Nintendo2();
						char print_temp[200];
						char file_path[200];
						FILE* f;
						sprintf(file_path, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\議攪Я.txt");
						f = fopen(file_path, "r");
						gotoxy(100, 1);
						for (int i = 0; i < 40; i++)
						{
							gotoxy(100, i + 1);
							fgets(print_temp, 200, f);
							printf("%s", print_temp);
						}
						gotoxy(33, 11);
						char str[50] = "撿儅曖 議攪Я陛 釭顫陬棻!!";
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
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\だ檜葬.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "陛嫁 だ檜葬!!";
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
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\窒睡晦.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "陛嫁 窒睡晦!!";
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
							sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\檜鼻п噢.txt");
							f1 = fopen(file_path1, "r");
							gotoxy(100, 1);
							for (int i = 0; i < 30; i++)
							{
								gotoxy(100, i + 1);
								fgets(print_temp1, 200, f1);
								printf("%s", print_temp1);
							}
							gotoxy(33, 11);
							char str1[50] = "陛嫁 檜鼻п噢!!";
							int size1;
							size1 = sizeof(str1) / sizeof(str1[0]);
							for (int i = 0; i < size1; i++)
							{
								Sleep(50);
								printf("%c", str1[i]);
							}Sleep(100);
						}
						gotoxy(33, 12);
						char str2[50] = "橫雯 ч翕擊 ж衛啊蝗棲梱?";
						int size2;
						size2 = sizeof(str2) / sizeof(str2[0]);
						for (int i = 0; i < size2; i++)
						{
							Sleep(50);
							printf("%c", str2[i]);
						}Sleep(100);
						int r;
						gotoxy(40, 28);
						printf("[1] 寡ぎ");
						gotoxy(22, 35);
						printf("[2] 陛寞");
						gotoxy(40, 35);
						printf("[3] 紫蜂除棻");
						gotoxy(58, 35);
						printf("[4] ん鰍跨");
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
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\だ檜葬.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===だ檜葬===");
								gotoxy(22, 30);
								printf("[1] 跺鱔夢纂晦");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("だ檜葬曖 跺鱔夢纂晦");
									gotoxy(33, 15);
									printf("議攪Я朝 等嘐雖 8 擊 殮歷棻.");
									gotoxy(33, 16);
									printf("議攪Я曖 hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									system("cls");
									Nintendo2();
									gotoxy(33, 14);
									printf("議攪Я曖 跺鱔夢纂晦");
									gotoxy(33, 15);
									printf("だ檜葬朝 等嘐雖 6擊 殮歷棻.");
									gotoxy(33, 16);
									printf("だ檜葬曖 hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
									int r;
								l:
									system("cls");
									Nintendo2();
									gotoxy(33, 12);
									char str2[50] = "橫雯 ч翕擊 ж衛啊蝗棲梱?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] 寡ぎ");
									gotoxy(22, 35);
									printf("[2] 陛寞");
									gotoxy(40, 35);
									printf("[3] 紫蜂除棻");
									gotoxy(58, 35);
									printf("[4] ん鰍跨");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 13);
										printf("だ檜葬曖 跺鱔夢纂晦");
										gotoxy(33, 14);
										printf("議攪Я朝 等嘐雖 8 擊 殮歷棻.");
										gotoxy(33, 15);
										printf("議攪Я曖 hp : [7]->[0]");
										gotoxy(33, 16);
										printf("議攪Я朝 噙楝螺棻!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\だ檜葬.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20曖 唳я纂蒂 橢歷蝗棲棻.");
										gotoxy(33, 15);
										char str2[50] = "だ檜葬朝 溯漣 7檜 腎歷蝗棲棻.";
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
										printf("闌剪遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										int n;
										system("cls");
										Nintendo2();
										gotoxy(40, 28);
										printf("==陛寞==");
										gotoxy(33, 29);
										printf("[1] ん鰍跨 獐 : 5偃");
										gotoxy(33, 30);
										printf("[2] 鼻籀擒 : 5偃");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ん鰍跨 獐擊 餌辨ж艘棻");
											gotoxy(33, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(35, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≠");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("撿儅 議攪Я蒂 濩懊棻!");
											Sleep(100);
											gotoxy(33, 16);
											printf("紫馬縑 蛔煙 腌棲棻.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("闌剪遴 賅я檜艘棻.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�蛹嗾鈶� 餌辨ж艘蝗棲棻.");
											gotoxy(33, 16);
											printf("だ檜葬曖 hp陛 賅舒 �蛹僱Ц�蝗棲棻.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("撿儅 議攪Я煎 睡攪 紫蜂蟻棻!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("嬴蓮遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("ん鰍跨檜 橈蝗棲棻!!");
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
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\窒睡晦.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===窒睡晦===");
								gotoxy(22, 30);
								printf("[1] 跺鱔夢纂晦");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("窒睡晦曖 跺鱔夢纂晦");
									gotoxy(33, 15);
									printf("議攪Я朝 等嘐雖 8 擊 殮歷棻.");
									gotoxy(33, 16);
									printf("議攪Я曖 hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									system("cls");
									Nintendo2();
									gotoxy(33, 14);
									printf("議攪Я曖 跺鱔夢纂晦");
									gotoxy(33, 15);
									printf("窒睡晦朝 等嘐雖 6擊 殮歷棻.");
									gotoxy(33, 16);
									printf("窒睡晦曖 hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
									int r;
								p:
									system("cls");
									Nintendo2();
									gotoxy(33, 12);
									char str2[50] = "橫雯 ч翕擊 ж衛啊蝗棲梱?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] 寡ぎ");
									gotoxy(22, 35);
									printf("[2] 陛寞");
									gotoxy(40, 35);
									printf("[3] 紫蜂除棻");
									gotoxy(58, 35);
									printf("[4] ん鰍跨");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										gotoxy(33, 13);
										printf("窒睡晦曖 跺鱔夢纂晦");
										gotoxy(33, 14);
										printf("議攪Я朝 等嘐雖 8 擊 殮歷棻.");
										gotoxy(33, 15);
										printf("議攪Я曖 hp : [7]->[0]");
										gotoxy(33, 16);
										printf("議攪Я朝 噙楝螺棻!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\窒睡晦.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20曖 唳я纂蒂 橢歷蝗棲棻.");
										gotoxy(33, 15);
										char str2[50] = "窒睡晦朝 溯漣 7檜 腎歷蝗棲棻.";
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
										printf("闌剪遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										int n;
										system("cls");
										Nintendo2();
										gotoxy(40, 28);
										printf("==陛寞==");
										gotoxy(40, 29);
										printf("[1] ん鰍跨 獐 : 5偃");
										gotoxy(40, 30);
										printf("[2] 鼻籀擒 : 5偃");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ん鰍跨獐擊 餌辨ж艘棻");
											gotoxy(33, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(35, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≠");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("撿儅 議攪Я蒂 濩懊棻!");
											Sleep(100);
											gotoxy(33, 16);
											printf("紫馬縑 蛔煙 腌棲棻.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("闌剪遴 賅я檜艘棻.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�蛹嗾鈶� 餌辨ж艘蝗棲棻.");
											gotoxy(33, 16);
											printf("だ檜葬曖 hp陛 賅舒 �蛹僱Ц�蝗棲棻.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("撿儅 議攪Я煎 睡攪 紫蜂蟻棻!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("嬴蓮遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("ん鰍跨檜 橈蝗棲棻!!");
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
								sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\檜鼻п噢.txt");
								f1 = fopen(file_path1, "r");
								gotoxy(100, 1);
								for (int i = 0; i < 30; i++)
								{
									gotoxy(100, i + 1);
									fgets(print_temp1, 200, f1);
									printf("%s", print_temp1);
								}
								gotoxy(39, 28);
								printf("===檜鼻п噢===");
								gotoxy(22, 30);
								printf("[1] 跺鱔夢纂晦");
								gotoxy(33, 13);
								scanf("%d", &n);
								if (n == 1)
								{
									gotoxy(33, 14);
									printf("檜鼻п噢曖 跺鱔夢纂晦");
									gotoxy(33, 15);
									printf("議攪Я朝 等嘐雖 8 擊 殮歷棻.");
									gotoxy(33, 16);
									printf("議攪Я曖 hp : [15]->[7]");
									Sleep(1000);
									hp2 -= 8;
									gotoxy(33, 14);
									printf("議攪Я曖 瞪惜戮��");
									gotoxy(33, 15);
									printf("檜鼻п噢朝 等嘐雖 6擊 殮歷棻.");
									gotoxy(33, 16);
									printf("檜鼻п噢曖 hp : [20]->[14]");
									Sleep(1000);
									hp -= 6;
								w:
									system("cls");
									Nintendo2();
									int r;
									gotoxy(33, 12);
									char str2[50] = "橫雯 ч翕擊 ж衛啊蝗棲梱?";
									int size2;
									size2 = sizeof(str2) / sizeof(str2[0]);
									for (int i = 0; i < size2; i++)
									{
										Sleep(50);
										printf("%c", str2[i]);
									}Sleep(100);
									int b;
									gotoxy(40, 28);
									printf("[1] 寡ぎ");
									gotoxy(22, 35);
									printf("[2] 陛寞");
									gotoxy(40, 35);
									printf("[3] 紫蜂除棻");
									gotoxy(58, 35);
									printf("[4] ん鰍跨");
									gotoxy(33, 13);
									scanf("%d", &b);
									if (b == 1)
									{
										gotoxy(33, 13);
										printf("檜鼻п噢曖 跺鱔夢纂晦");
										gotoxy(33, 14);
										printf("議攪Я朝 等嘐雖 8 擊 殮歷棻.");
										gotoxy(33, 15);
										printf("議攪Я曖 hp : [7]->[0]");
										gotoxy(33, 16);
										printf("議攪Я擎 噙楝螺棻!");
										Sleep(1000);
										system("cls");
										Nintendo2();
										char print_temp1[200];
										char file_path1[200];
										FILE* f1;
										sprintf(file_path1, "C:\\Users\\user\\source\\repos\\(ぜЩ煎薛お)\\檜鼻п噢.txt");
										f1 = fopen(file_path1, "r");
										gotoxy(100, 1);
										for (int i = 0; i < 30; i++)
										{
											gotoxy(100, i + 1);
											fgets(print_temp1, 200, f1);
											printf("%s", print_temp1);
										}
										gotoxy(33, 14);
										printf("20曖 唳я纂蒂 橢歷蝗棲棻.");
										gotoxy(33, 15);
										char str2[50] = "檜鼻п噢朝 溯漣 7檜 腎歷蝗棲棻.";
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
										printf("闌剪遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 2)
									{
										int n;
										system("cls");
										Nintendo2();
										gotoxy(40, 28);
										printf("==陛寞==");
										gotoxy(40, 29);
										printf("[1] ん鰍跨 獐 : 5偃");
										gotoxy(40, 30);
										printf("[2] 鼻籀擒 : 5偃");
										gotoxy(33, 16);
										scanf("%d", &n);
										if (n == 1)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("ん鰍跨獐擊 餌辨ж艘棻");
											gotoxy(33, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(35, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≧");
											Sleep(1000);
											gotoxy(37, 16);
											printf("≠");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("撿儅 議攪Я蒂 濩懊棻!");
											Sleep(100);
											gotoxy(33, 16);
											printf("紫馬縑 蛔煙 腌棲棻.");
											Sleep(1000);
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("闌剪遴 賅я檜艘棻.");
											gotoxy(50, 42);
											exit(0);
										}
										if (n == 2)
										{
											system("cls");
											Nintendo2();
											gotoxy(33, 15);
											printf("�蛹嗾鈶� 餌辨ж艘蝗棲棻.");
											gotoxy(33, 16);
											printf("だ檜葬曖 hp陛 賅舒 �蛹僱Ц�蝗棲棻.");
										}
									}
									if (b == 3)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("撿儅 議攪Я煎 睡攪 紫蜂蟻棻!");
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("嬴蓮遴 賅я檜艘棻.");
										gotoxy(50, 42);
										exit(0);
									}
									if (b == 4)
									{
										system("cls");
										Nintendo2();
										gotoxy(33, 15);
										printf("ん鰍跨檜 橈蝗棲棻!!");
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
					printf("鼻薄 檜翕 醞.\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("鼻薄 檜翕 醞..\n");
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("鼻薄 檜翕 醞...\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("鼻薄 檜翕 醞....\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					gotoxy(33, 10);
					printf("鼻薄 檜翕 醞.....\n");
					Sleep(100);
					system("cls");
					Nintendo2();
					int c;
					gotoxy(32, 11);
					printf("鼠歷擊 餌衛啊蝗棲梱?");
					gotoxy(35, 28);
					printf("[1] ん鰍跨 獐");
					gotoxy(35, 32);
					printf("[2] �蛹嗾�");
					gotoxy(35, 33);
					scanf("%d", &c);
					if (c == 1)
					{
						int cash = 10000;
						int ball;
						system("cls");
						Nintendo2();
						gotoxy(33, 15);
						printf("ん鰍跨 獐 賃偃蒂 掘殮ж衛啊蝗棲梱?");
						system("cls");
						Nintendo2();
						gotoxy(33, 15);
						printf("ん鰍跨 獐 ж釭縑 1000錳");
						gotoxy(33, 28);
						printf("[1].1偃");
						gotoxy(33, 30);
						printf("[2].5偃");
						gotoxy(33, 32);
						printf("[3].10偃");
						gotoxy(33, 16);
						scanf("%d", &ball);
						if (ball == 1)
						{
							system("cls");
							Nintendo2();
							gotoxy(33, 15);
							printf("9000錳 陴懊蝗棲棻.");
							Sleep(1000);
							cash -= 1000;
							goto e;
						}
						if (ball == 2)
						{
							system("cls");
							Nintendo2();
							gotoxy(33, 15);
							printf("5000錳 陴懊蝗棲棻.");
							cash -= 5000;
							Sleep(1000);
							goto e;
						}
						if (ball == 3)
						{
							system("cls");
							Nintendo2();
							gotoxy(33, 15);
							printf("0錳 陴懊蝗棲棻.");
							Sleep(1000);
							cash -= 10000;
						}
						if (cash == 0)
						{
							gotoxy(33, 15);
							printf("渦檜鼻 髦 熱 橈蝗棲棻");
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
						printf("�蛹嗾� 賃偃蒂 掘殮ж衛啊蝗棲梱?");
						system("cls");
						Nintendo2();
						gotoxy(33, 15);
						printf("�蛹嗾� ж釭縑 1000錳");
						gotoxy(33, 28);
						printf("[1].1偃");
						gotoxy(33, 30);
						printf("[2].5偃");
						gotoxy(33, 32);
						printf("[3].10偃");
						gotoxy(33, 16);
						scanf("%d", &cu);
						if (cu == 1)
						{
							system("cls");
							Nintendo2();
							gotoxy(33, 15);
							printf("9000錳 陴懊蝗棲棻.");
							cash -= 1000;
							Sleep(1000);
							goto e;
						}
						if (cu == 2)
						{
							system("cls");
							Nintendo2();
							gotoxy(33, 15);
							printf("5000錳 陴懊蝗棲棻.");
							cash -= 5000;
							Sleep(1000);
							goto e;
						}
						if (cu == 3)
						{
							system("cls");
							Nintendo2();
							gotoxy(33, 15);
							printf("0錳 陴懊蝗棲棻.");
							cash -= 10000;
							Sleep(1000);
						}
						if (cash == 0)
						{
							gotoxy(33, 15);
							printf("渦檜鼻 髦 熱 橈蝗棲棻");
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
					char str[50] = "嬴霜 羹幫婦擎 陞 熱 橈橫!!";
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
				printf("褻旎渦 氈棻陛 陛撿雖...");
				Sleep(1000);
				gotoxy(33, 15);
				printf("斜楚 賅я擎 釭醞縑 ж濠..");
				Sleep(2000);
				system("cls");
				Nintendo2();
				Sleep(2000);
				gotoxy(33, 15);
				printf("醱碟�� 蓮樟蝗棲梱?");
				Sleep(1000);
				gotoxy(32, 16);
				printf("醱碟�� 蓮樟棻賊 賅я擊 衛濛ж啊蝗棲棻.");
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
