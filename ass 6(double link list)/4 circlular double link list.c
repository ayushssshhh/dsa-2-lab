#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;
int n;

void create_list(){
    int i;
    struct node* newnode;

    printf("enter no of node to create : ");
    scanf("%d",&n);

    for(int i=1 ; i<=n ; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter DATA : ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }

        else{
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }
    }

    //forward cir
    tail->next = head;

    //rev cir
    head->prev = tail;
}

void traverse_f(){
    struct node* ptr = head;
    int i = 1;

    while(i <= n+n){
        printf(" %d",ptr->data);
        ptr = ptr->next;
        i++;
    }
}

void traverse_r(){
    struct node* ptr = tail;
    int i = 1;

    while(i <= n+n){
        printf(" %d",ptr->data);
        ptr = ptr->prev;
        i++;
    }
}

int main(){
    
    int c;
    char ch;

    

    do{
        printf("\n--select linked list opperatroin--\n\npress 1 to create an linked list\npress 2 to print loop of circular linked list\npress 3 to print loop of rev circular linked list in reverse\n\nenter your choice : ");
        scanf("%d",&c);
        
        switch(c){
            
            case 1:
            create_list();
            break;

            case 2:
            traverse_f();
            break;

            case 3:
            traverse_r();
            break;

            default:
            printf("\n---error 404 ------\nenter valid listed opperation\n");
        }
        printf("\ndo you want to continue??\n(press y to continue) enter your choice : ");
        scanf(" %c",&ch);
    }while((ch == 'y'));

    return 0;   

}

//1 5 98 9 23 75 82 y