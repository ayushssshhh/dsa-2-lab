#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int pow;
    struct node *next;
};

struct node* cr(){
    struct node *newnode , *ptr, *head = NULL;
    ptr = head;

    for(int i=1 ; i<4 ; i++){
        newnode = (struct node*)malloc(sizeof(struct node));

        newnode->data = i+1;
        newnode->pow = i-1;
        newnode->next = NULL;

        if(head == NULL)
            head = ptr = newnode;

        else
            ptr = ptr->next = newnode;
            
    }

    return head;
    
}

void d(struct node *ptr){
    
    if(ptr == NULL){
        printf("\nlist is empty");
        return;
    }
    
    while(ptr != NULL){
        printf("+%dx^%d  ",ptr->data , ptr->pow);
        ptr = ptr->next;
    }
}


int main(){
    struct node *head1 = NULL;
    head1 = cr();
    d(head1);
    return 0;
}