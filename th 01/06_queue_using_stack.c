#include <stdio.h>
#include <stdlib.h>

struct stack1{
    int data;
    struct stack1 *next;
};

struct stack2{
    int data;
    struct stack2 *next;
};

struct stack1 *f1 = NULL;
struct stack2 *f2 = NULL;

int n = 0;

void push(int x){
    struct stack1 *newnode = (struct stack1*)malloc(sizeof(struct stack1));
    newnode->data = x;
    newnode->next = NULL;

    if(f1 == NULL)
    f1 = newnode;

    else
    {
        newnode->next = f1;
        f1 = newnode;
    }

    n++;
}

void pop(){
    for(int i=0 ; i<n ; i++){
        struct stack1 *ptr = f1;
        struct stack2 *newnode = (struct stack2*)malloc(sizeof(struct stack2));
        
        newnode->data = f1->data;
        newnode->next = NULL;

        if(f2 == NULL)
        f2 = newnode;

        else{
            newnode->next = f2;
            f2 = newnode;
        }

        f1 = f1->next;
        free(ptr);
    }

    printf("\n\npoping out %d from the stack",f2->data);

    struct stack2 *ptr = f2;
    f2 = f2->next;
    free(ptr);
    f1 = NULL;
    n--;

    int k = n;
    n = 0;

    for(int i=0 ; i<k ; i++){
        push(f2->data);

        struct stack2 *ptr = f2;
        f2 = f2->next;
        free(ptr);
    }

    f2 = NULL;
}

void dis(){
    if(f1 == NULL){
        printf("\nthe list is empty");
        return;
    }

    else{
        struct stack1 *ptr = f1;

        printf("\nthe stack is : ");
        while(ptr != NULL){
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
}

int main(){
    char ch;
    int c , x;

    do{
        printf("\n\n1 push\n2 pop\n3 display\nenter choice : ");
        scanf("%d",&c);

        switch(c){
            case 1 : 
                printf("enter value to push : ");
                scanf("%d",&x);
                push(x);
                break;

            case 2 :
                pop();
                break;

            case 3 :
                dis();
                break;

            default :
                printf("\nenter a valid option");
                break;
        }
        printf("\ndo you want to continue?!\nenter choice :");
        scanf(" %c",&ch);

    }while((ch=='y')||(ch=='Y'));
}