#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void create_list(){
    int n , i;
    struct node* newnode;

    printf("enter no of node to create : ");
    scanf("%d",&n);

    for(int i=1 ; i<=n ; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter DATA : ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }

        else{
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }
    }
}

void traverse_r(){
    struct node* ptr = tail;

    while(ptr != NULL){
        printf(" %d",ptr->data);
        ptr = ptr->prev;
    }
}

int main(){

            create_list();

            printf("\n\nthe link list in reversed fashion is : ");
            traverse_r();

    return 0;   

}

//1 5 98 9 23 75 82 y