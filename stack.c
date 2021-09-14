#include<stdio.h>
#pragma warning(disable:4996)

#define STACK_SIZE 5
typedef int element;
element stack[STACK_SIZE];
static int top = -1;
void push(element item) {
	if (top >= STACK_SIZE - 1) {
		printf("STack is Full \n");
		return;
	}
	else stack[++top] = item;
}
element pop() {
	if (top == -1) {
		printf("Stack is Empty \n");
		return 0;
	}
	else return stack[top--];
}
element peek() {
	if (top == -1) {
		printf("Stack is Empty \n");
	}
	else return stack[top];
}
int main()
{
	push(10);
	push(20);
	push(30);	
	push(40);
	pop();
	pop();
	push(50);
	push(60);
	push(70);
	for (int i = STACK_SIZE-1; i >= 0; i--) {
		printf("%d : %d \n", i, stack[i]);
	}
}

