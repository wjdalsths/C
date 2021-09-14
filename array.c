#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int main()
{
	/*int n[5][5];
	for (int i = 0; i < 5; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 5; j++) {
				if (i == 0)
					n[i][j] = j + 1;
				else
					n[i][j] = n[i-1][0] + j + 1;
			}
		}
		else if (i % 2 == 1) {
			for (int j = 0; j < 5; j++) {
				n[i][4 - j] = n[i-1][4]+j + 1;
			}
		}
	}*/






	/*int n2[5][5];
	for (int i = 0; i < 5; i++) {
		if (i == 0) {
			for (int j = 0; j < 5; j++) {
				n2[i][j] = j + 1;
			}
		}
		else if (i == 1) {
			for (int j = 0; j < 5; j++) {
				n2[j][4-i] = n2[i - 1][4] + j + 1;
			}
		}
		else if (i == 2) {
			for (int j = 0; j < 5; j++) {
				n2[4 - i][4 - j] = n2[4][4] + j + 1;
			}
		}
		else if (i == 3) {
			for (int j = 0; j < 5; j++) {
				
			}
		}
	}*/

	//int arr[101][101];
	//int N, M;
	//scanf("%d %d", &N, &M);
	//int i = 0, j = 0, a = 1;

	//for (i = 0; i < N; i++) {
	//	for (j = 0; j < M; j++) {
	//		arr[i][j] = 0;
	//	}
	//}
	////start포인트 설정
	//i = 0;
	//j = 0;
	//arr[i][j] = 1;
	//a = 2;

	//while (a <= N * M) {

	//	while (j + 1 < M && arr[i][j + 1] == 0) {
	//		j++;
	//		arr[i][j] = a;
	//		a++;
	//	}

	//	while (i + 1 < N && arr[i + 1][j] == 0) {
	//		i++;
	//		arr[i][j] = a;
	//		a++;
	//	}

	//	while (j - 1 >= 0 && arr[i][j - 1] == 0) {
	//		j--;
	//		arr[i][j] = a;
	//		a++;
	//	}
	//	while (i - 1 >= 0 && arr[i - 1][j] == 0) {
	//		i--;
	//		arr[i][j] = a;
	//		a++;
	//	}

	//}

	//for (i = 0; i < N; i++) {
	//	for (j = 0; j < M; j++) {
	//		printf("%6d", arr[i][j]);
	//	}
	//	printf("\n");
	//}



	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%3d", n[i][j]);
		}printf("\n");
	}
}