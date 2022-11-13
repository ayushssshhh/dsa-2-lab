#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node *prev;
};

struct node *head = NULL;
struct node* tail = NULL;
int n_node = 0;

void create_list(int n){

    struct node *newnode;

    while(n > 0){
        newnode = (struct node*)malloc(sizeof(struct node));

        newnode->data = n%10;
        newnode->next = newnode->prev = NULL;

        if(head == NULL)
        tail = head = newnode;

        else{
            newnode->prev = tail;
            tail = tail->next = newnode;
        }

        n_node++;
        n /= 10;
    }
    


}

void dis_list(){
    struct node *ptr = tail;

    while(ptr != NULL){
        printf(" %d",ptr->data);
        ptr = ptr->prev;
    }
}

void check_palin(){
    struct node *ptr1 = head , *ptr2 = tail;
    int c = 0;

    for(int i=0 ; i < n_node/2 ; i++){
        if(ptr1->data != ptr2->data){
            c++;
            break;
        }
    }

    if(c == 0 ){
        printf("\nthe no. is palindrome");
    }

    else
    printf("\nthe no. is not palindrome");
}

int main(){

    int n;
    printf("enter the no. : ");
    scanf("%d",&n);

    create_list(n);

    printf("the no. is : ");
    dis_list();

    check_palin();

    return 0;
}