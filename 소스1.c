#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void selection_sort();
void marge_sort();

int main()
{
	int a[] = { 8,9,3,7,6 };
	int a1[] = { 1,2,4,0,5 };
	marge_sort(a, a1);

	return 0;
}
void marge_sort(int* a, int* a1) {
	selection_sort(a);
	selection_sort(a1);
	int A[10], p = 0, p1 = 0;
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
	for (int i = 0; i < 10; i++) {
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