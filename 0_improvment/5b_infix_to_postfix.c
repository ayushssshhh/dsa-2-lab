#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
    char data;
    struct node* next;
};

struct node *top = NULL;


void push(char c){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = c;
    newnode->next = NULL;

    if(top == NULL)
    top = newnode;

    else{
        newnode->next = top;
        top = newnode;
    }
}

void pop(){
    struct node *ptr = top;
    top = top->next;
    printf("%s",ptr->data);
    free(ptr);
}

int main (){

    char a[100];
    printf("\nente your infix epxpresion with parenthesis : ");
    scanf("%d",&a);

    int i = 0;
    while(a[i] != '\0'){
        if( isdigit(a[i])  == 1){
            printf("%d",a[i]);
        }

        else{
            if(top == NULL)
            push(a[i]);

            else if(){
                
            }
        }

    }


    return 0;
}