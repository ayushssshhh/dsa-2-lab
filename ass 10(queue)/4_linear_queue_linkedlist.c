#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    struct node*t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;

    if(front==NULL){
        front=rear=t;
    }
    
    else{
        rear->next=t;
        rear=t;
    }
    
}

void check(){
    if(front == NULL)
        printf("\n\nthe queue is empty\n");

    else
        printf("\n\n the queue is not empty\n");
}

void dequeue(){
    struct node*t;
    if(front==NULL){
        printf("queue is empty");
    }
    else{
        t=front;
        front=front->next;
        free(t);
    }
}

void display(){
    struct node *p=front;
    while(p){
        printf("%d  ",p->data);
        p=p->next;
    }
}


int main(){

    char ch;
    int x , c;

    do
    {
        printf("\n\n1 enqueue\n2 deuqeue\n3 display\n4 check\n\nenter choice : ");
        scanf("%d",&c);

        switch (c){
            case 1 :
                printf("enter value to enqueue : ");
                scanf("%d",&x);
                enqueue(x);
                break;

            case 2 :
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4 :
                check();
                break;

            default :
                printf("\nenter a valid option");
                break;
        }

        printf("DO YOU WANT TO CONTINUE?!");
        scanf(" %c",&ch);
    } while ((ch=='y')||(ch=='Y'));
    

    return 0;
}