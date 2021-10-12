#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void Printlist();
typedef struct listnode {
	int data;
	struct  listnode* link;
}node;

void fremove(node* head, node* f, node* p) {
	if (f == NULL)
		head = head->link;
	else
		f->link = p->link;
	free(p);
}
void rem(int de, node* head, node* tail) {
	node* temp = head;
	/*while (temp)
	{
		if (temp->data != de) {
			temp = temp->link;
		}
		else if (temp->data == de) {
			free(temp);
		}

	}*/
	while (temp) {
		if (temp->data == de) {
			temp = temp->link;
			continue;
		}
		printf("%d ", temp->data);
		if (temp != tail) printf("-> ");
		else break;
		temp = temp->link;
	}
}
node* rel(node* head, int data) {
	node* pre;
	node* removed;

	pre = head;
	while (pre != NULL) {
		//기존 lisd 10 20 30 40 삽입 : 15
		if (pre->data < data) {
			break;
		}
		pre = pre->link;
	}
	//삭제할 것이 없다
	if (head == NULL) {
		return NULL;
	}
	else if (pre == NULL) {
		removed = head;
		head = removed->link;
		free(removed);
	}
	//맨끝
	else if (pre->link == NULL) {
		free(pre);
	}
	//중간 값 삭제
	else {
		removed = pre->link;
		pre->link = removed->link;
		free(removed);
	}

	return head;
}

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
	//rem(de, head,tail);
	//rel(head, de);
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


	/* node* temp = head;
	 while (temp)
	 {
		 printf("%d\n", temp->data);
		 temp = temp->link;
	 }*/

	 //Printlist(head);

	return 0;
}
void Printlist(node* head) {
	/*for (node* i = head; i != NULL; i = i->link) {
		printf("%d -> ", i->data);
	}
	printf("NULL\n");*/
	node* temp = head;
	while (temp)
	{
		printf("%d\n", temp->data);
		temp = temp->link;
	}
}