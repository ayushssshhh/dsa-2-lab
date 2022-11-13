#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

struct node* head = NULL;
int n;

void create_list(){
    int i;
    struct node *newnode , *ptr;

    printf("enter no of node to create : ");
    scanf("%d",&n);

    for(int i=1 ; i<=n ; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter DATA : ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        
        if(head == NULL){
            head = ptr = newnode;
        }

        else{
            ptr->next = newnode;
            ptr = newnode;
        }
    }

    //forward cir
    tail->next = head;

}

void traverse_f(){
    struct node* ptr = head;
    int i = 1;

    while(i <= n+n){
        printf(" %d",ptr->data);
        ptr = ptr->next;
        i++;
    }
}

int main(){
    
    printf("\n\n-----linked llist operation-------\n\n");

    printf("\n\n-------creation--------\n\n");
    create_list();

    printf("\n\n-------traversin--------\n\n");
    create_list();


    return 0;   

}

//1 5 98 9 23 75 82 y