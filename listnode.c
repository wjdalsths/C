#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void Printlist();
typedef struct listnode {
	int data;
	struct  listnode* link;
}node;

int main() {
	int de = 0;
	node* head = NULL;
	node* tail = NULL;

	/*newnode->data = 10;
	newnode->link = NULL;*/
	int n;
	while (1)
	{
		node* newnode = (node*)malloc(sizeof(node));
		scanf_s("%d", &n);
		if (n < 0)
			break;
		else
		{
			newnode->data = n;
			newnode->link = NULL;

			if (head == NULL) {
				head = newnode;
				//tail = newnode;
			}
			else {
				/*tail->link = newnode;
				tail = newnode;*/
				newnode->link = head;
				head = newnode;
			}
		}
	}

	printf("지울 값>> ");
	scanf_s("%d", &de);
	
	node* tem = head;
	while (tem) {
		if (tem->data == de) {
			tem = tem->link;
			continue;
		}
		printf("%d ", tem->data);
		if (tem != tail) printf("-> ");
		else break;
		tem = tem->link;
	}
	printf("NULL\n");


	

	return 0;
}
