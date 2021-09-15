#include <stdio.h> 
int main() 
{ 
	int a, b, c; 
	int cnt=0;
	for(a = 1; a <= 100; a++) { 
		for(b = a; b <= 100; b++) { 
			for(c = b; c <= 100; c++) { 
				if((a * a + b * b) == (c * c)) { 
					printf("(%d, %d, %d)\n", a, b, c); 
					cnt++;
				} 
			} 
		} 
	} 
	printf("%d", cnt);
	return 0; 
}

