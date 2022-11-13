#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coff;
    struct node* next;
};

struct node* head = NULL;
int n_node;


void create_list(){
    printf("enter the order of polynomial : ");
    scanf("%d",&n_node);
    n_node++;

    struct node *ptr , *newnode;

    for(int i=0 ; i<n_node ; i++){

        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->coff);

        newnode->next = NULL;

        if(head == NULL)
        ptr = head = newnode;

        else
        ptr = ptr->next = newnode;
    }
}


void dis(){
    struct node* ptr = head;

    for(int i=0 ; i<n_node ; i++){
        
        if(ptr->coff != 0)
        printf("+ %dx^%d ",ptr->coff , i);
    
        ptr = ptr->next;
    }
}

int main(){

    create_list();
    
    dis();

    return 0;
}