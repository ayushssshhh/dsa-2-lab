#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int priority;
    struct node *next;
};

struct node *head = NULL;

void enqueue(int p , int v){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    
    newnode->data = v;
    newnode->priority = p;
    newnode->next = NULL;

    if(head==NULL){
        head = newnode;        
    }

    else if(head->priority > p){
        struct node *temp = head;
        head = newnode;
        head->next = temp;
    }

    else{
        struct node *temp , *prev;
        temp = head;
        prev = NULL;

        while((temp->next != NULL) && (temp->priority < p)){
            prev = temp;
            temp = temp->next;
        }

        if(temp->next == NULL){
            temp->next = newnode;
        }

        else{
            prev->next = newnode;
            newnode->next = temp->next;
        }

    }

}

void dequeue(){
    printf("%d ",head->data);
    
    struct node* ptr = head;
    head = head->next;

    free(ptr);
}

int main(){

    int v,p;
    char ch;

    do{
        int c;
        printf("\npress 1 to enqueue an element\npress 2 to dqueue\nenterr your choice : ");
        scanf("%d",&c);

        switch (c)
        {
            
            case 1:
                printf("enter the value and prirority of element : ");
                scanf("%d%d",&v,&p);
                enqueue(p , v);
                break;

            case 2 : 
                dequeue();
                break;
        
            default : 
                printf("\n please enter an valid option");
                break;
        }

        printf("do you want to continue? : ");
        scanf(" %c",&ch);
    }while((ch == 'y')||(ch == 'Y'));

    return 0;
}
