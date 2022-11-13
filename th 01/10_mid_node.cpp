#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* cr(){
    struct node *head = NULL , *ptr , *newnode;
    
    int n;
    printf("enter no. of node : ");
    scanf("%d",&n);

    for(int i=0 ; i<n ; i++){
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("enter data : ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;

        if(head == NULL)
        head = ptr = newnode;

        else
        ptr = ptr->next = newnode;
    }

    return head;
};

void dis(struct node *ptr){

    if(ptr == NULL){
        printf("\n\nthe list is empty");
        return;
    }


    printf("\nthe list is : ");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

void mid(struct node *ptr){
    if(ptr == NULL){
        printf("\n\nthe list is empty");
        return;
    }

    struct node *temp = ptr;
    while((ptr != NULL) && (ptr->next != NULL)){
        temp = temp->next;
        ptr = ptr->next->next;
    }



    printf("\n\nthe middle node is : %d",temp->data);
}

int main(){
    struct node *head = NULL;
    
    printf("\ncreate your list :-\n");
    head = cr();

    dis(head);

    mid(head);
    return 0;
}