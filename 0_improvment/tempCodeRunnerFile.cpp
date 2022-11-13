#include <stdio.h>
#include <stdlib.h>

void push(char c);
void pop();
void dis_stack();

struct node{
    char para;
    struct node *next;
};

struct node* top = NULL;
int n_node = 0;

void push(char c){
    printf("\nb: %d",c);
    struct node* newnode;
    
    n_node++;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->para = c;
    newnode->next = NULL;

    if(top == NULL)
        top = newnode;

    else{
        newnode->next = top;
        top = newnode;
    }
    //dis_stack();

}

void dis_stack(){
    struct node *ptr = top;

    while(ptr != NULL){
        printf(" %d",ptr->para);
        ptr = ptr->next;
    }
    printf("\n");
}

void pop(){
    struct node *ptr = top;

    top = top->next;
    free(ptr);
}

int main(){
    char a = '(';
    char b = ')'; 
    push(a);
    push(a);
    push(a);
    push(a);
    push(b);
    push(a);
    push(a);
    dis_stack();
    pop();
    pop();
    dis_stack();
}