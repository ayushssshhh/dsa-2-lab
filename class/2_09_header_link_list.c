#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head;
int n_node;

void create_header_list(){
    printf("enter no. of nodes to be created :" );
    scanf("%d",&n_node);

    struct node *ptr , *headernode;
    headernode = (struct node*)malloc(sizeof(struct node));

    headernode->data = n_node;
    headernode->next = NULL;
    ptr = head = headernode;

    for(int i=1 ; i<=n_node ; i++){
        struct node *newnode = (struct node*)malloc(sizeof(struct node));

        printf("enter data for node %d : ",i);
        scanf("%d",&newnode->data);
        newnode->next = NULL;

        ptr = ptr->next = newnode;
    }
}

void traverse(){
    struct node* ptr = head;

    printf("\n\ntotal no. of : %d\nthe link list : " , ptr->data);

    for(int i=1 ; i<= (n_node) ; i++){
        ptr = ptr->next;
        printf(" %d",ptr->data);
    }
}

int main(){

    create_header_list();

    printf("\n");
    traverse();

    return 0;
}

//8 12 98 90 57 32 21 77 53