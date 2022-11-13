#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(){

    struct node *temp;
    char ch;
    int i=1;

    printf("\n\n-----enter data in your linked list------\n\n");
    do{
        struct node *newnode = (struct node*)malloc(sizeof(struct node));

        printf("enter data %d : ",i++);
        scanf("%d",&newnode->data);
        newnode->next = NULL;

        if(head == NULL){
            head = newnode;
            temp = newnode;
        }

        else{
            temp->next = newnode;
            temp = newnode;
        }

        printf("do you want to continue ???\n\npress y or Y to to continue or any other key to exit : ");
        scanf(" %c",&ch);
    }while((ch == 'y') || (ch == 'Y'));
}


void travese(){
    printf("\n\nthe linked list is : ");
    struct node *ptr;
    ptr = head;
    while (ptr!=NULL){
        printf("%d ----> ",ptr->data);
        ptr = ptr->next;
    }
}

int main(){

    create();
    travese();

    return 0;
}