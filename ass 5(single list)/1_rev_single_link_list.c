#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* head = NULL;
int n_nodes;

void create_list(){
    struct node *newnode;
    struct node *ptr;

    int i;
    printf("enter no. of nodes to create : ");
    scanf("%d",&n_nodes);

    for(i=1 ; i<=n_nodes ; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter data for node %d : ",i);
        scanf("%d",&newnode->data);
        
        newnode->next = NULL;

        if(head == NULL){
            head = newnode;
            ptr = newnode;
        }

        else{
            ptr->next = newnode;
            ptr = newnode;
        }
    }

}

void traverse(){
    struct node* ptr = head;

    if(ptr == NULL)
    printf("\nList is empty");
    
    while(ptr != NULL){
        
        printf(" %d",ptr->data);
        ptr = ptr->next;
    }
}

void reverse(){
    
    struct node *p1 , *p2 , *p3;

    p1 = head;
    p2 = p1->next;
    p1->next = NULL;

    while(p2 != NULL){
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    head = p1;
}

int main(){

    create_list();
    printf("\nthe list is : ");

    traverse();
    printf("\nthe reversed list is : ");

    reverse();

    traverse();
    printf("\n");
    
    return 0;
}

//5 12 98 90 57 32
//67 y 89 y 62 y 0 y 9 y 21 y 300 n 