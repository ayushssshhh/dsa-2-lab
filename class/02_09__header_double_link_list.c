#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head;
struct node* tail;
int n_node;

void create_double_list(){
    int n , i;
    struct node* newnode;

    printf("enter no of node to create : ");
    scanf("%d",&n_node);

    for(int i=1 ; i<=n_node ; i++){
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

    struct node* headernode = (struct node *)malloc(sizeof(struct node));

    //header node ka kahani
    headernode->data = n_node;
    headernode->next = head;
    headernode->prev = tail;
    tail = head = headernode;

}


void traversef(){
    struct node* ptr = head;

    printf("\ntotal no. of : %d\nthe link list : " , ptr->data);

    for(int i=1 ; i<= (n_node) ; i++){
        ptr = ptr->next;
        printf(" %d",ptr->data);
    }
}

void traverser(){
    struct node* ptr = tail;

    printf("\ntotal no. of : %d\nthe link list : " , ptr->data);

    for(int i=1 ; i<= (n_node) ; i++){
        ptr = ptr->prev;
        printf(" %d",ptr->data);
    }
}

int main(){

    create_double_list();

    printf("\n\nthe forward link list is : ");
    traversef();

    printf("\n\n\nthe reversed link list is : ");
    traverser();

    return 0;
}

//8 12 98 90 57 32 21 77 53