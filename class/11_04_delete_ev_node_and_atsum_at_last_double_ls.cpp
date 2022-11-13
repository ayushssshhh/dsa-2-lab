#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *tail = NULL;
struct node *head = NULL;

void create(){
    int n;
    printf("\nenter no. of node to create : ");
    scanf("%d",&n);

    printf("\nenter %d vlaue to be added in linked list : ",n);
    for(int i=0 ; i<n ; i++){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));

        scanf("%d",&newnode->data);
        newnode->next = newnode->prev = NULL;

        if(head == NULL)
        tail = head = newnode;

        else{
            newnode->prev = tail;
            tail = tail->next = newnode;
        }
    }
}

void dis(){
    struct node *ptr = head;

    printf("\nthe link list is :");
    while(ptr != NULL){
        printf(" %d",ptr->data);
        ptr = ptr->next;
    }
}


void del_ev(){
    struct node *ptr = head , *ptr1 , *newnode;
    int s = 0;
    
    while(ptr != NULL){
        if(ptr->data%2 == 0){
            s += ptr->data;

            if(ptr == head){
                head = head->next;
                head->prev = NULL;
            }

            else if(ptr == tail){
                tail = tail->prev;
                tail->next = NULL;
            }

            else{
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }
        }
        ptr = ptr->next;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    
    newnode->data = s;
    newnode->next = newnode->prev = NULL;
    
    newnode->prev = tail;
    tail = tail->next = newnode;
}


int main(){

    create();
    dis();
    del_ev();
    dis();

    return 0;
}