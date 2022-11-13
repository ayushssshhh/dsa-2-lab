#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int v){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = v;
    newnode->next = NULL;

    if(top == NULL)
        top = newnode;

    else{
        newnode->next = top;
        top = newnode;
    }

}

void pop(){
    printf("\n \npoping out top : %d from the stack\n\n",top->data);

    struct node *ptr = top;
    top = top->next;
    free(ptr);
}

void dis(){
    struct node *ptr = top;

    while(ptr != NULL){
        printf("%d ",ptr->data);

        ptr = ptr->next;
    }
    printf("\n\n");
}

void is_empty(){
    if(top == NULL)
    printf("\n \nthe stack is empty\n");

    else
    printf("\n\nthe stack is not empty\n\n");
}

int main(){
    char ch;
    int v ,c;

    do{
        printf("\npress 1 for push\npress 2 for pop\npress 3 to check list empty or not\npress 4 to display element of stack\nenter your choice : ");
        scanf("%d",&c);

        switch (c)
        {
            
            case 1 : 
                printf("enter the value to push : ");
                scanf("%d",&v);
                push(v);
                break;

            case 2:
                pop();
                break;

            case 3 :
                is_empty();
                break;

            case 4 :
                printf("\n\nthe element in the stack are : ");
                dis();
                break;

            default : 
                printf("\nenter a valid option : ");
                break;
        }

        printf("do you want to continue?");
        scanf(" %c",&ch);

    }while((ch=='y')||(ch=='Y'));

    return 0;
}

// 1 1 y 1 2 y 1 3 y 1 4 y 1 5 y 1 89 y 1 99 y 2 y 3 y 2 y 4 n

