#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
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
int main() {
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
    
    
    
    node* temp = head;
    while (temp)
    {
        printf("%d\n", temp->data);
        temp = temp->link;
    }

    return 0;
}