#include <stdio.h>
#include <stdlib.h>

struct node{
    int coff;
    int x;
    int y;
    struct node *next; 
};

struct node* cr(){
    struct node *head = NULL , *ptr , *newnode;

    int n;
    printf("enter no. of terms in your polynominal : ");
    scanf("%d",&n);

    for(int i=0 ; i<n ; i++){
        printf("\n");
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("enter the coff of x and y : ");
        scanf("%d",&newnode->coff);
        printf("enter the power of x and y respectively : ");
        scanf("%d%d",&newnode->x , &newnode->y);
        newnode->next = NULL;

        if(head == NULL)
            head = ptr = newnode;

        else
            ptr = ptr->next = newnode; 
    }
    return head;
}

void dis(struct node *ptr){
    
    if(ptr == NULL){
        printf("\n\nthe list is empty");
        return;
    }

    while (ptr != NULL){
        printf("+%dx^%dy^%d ",ptr->coff , ptr->x , ptr->y);
        ptr = ptr->next; 
    }   
}

int main(){
    printf("\n\nenter your polynomial\n");
    
    struct node *head = NULL;
    head = cr();
    printf("\n\nthe polynomial is : ");
    dis(head);
    return 0;
}

//3 78 2 3 54 1 2 89 0 1