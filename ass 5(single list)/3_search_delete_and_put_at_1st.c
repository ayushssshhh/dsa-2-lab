#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* head = NULL;
int n_nodes;

void create_list(){
    struct node *newnode;
    struct node *ptr;

    int i;
    printf("enter no. of nodes to create : ");
    scanf("%d",&n_nodes);

    for(i=1 ; i<=n_nodes ; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter data for node %d : ",i);
        scanf("%d",&newnode->data);
        
        newnode->next = NULL;

        if(head == NULL){
        head = newnode;
        ptr = newnode;
        }

        else{
        ptr->next = newnode;
        ptr = newnode;
        }
    }

}

void traverse(){
    struct node* ptr = head;

    if(ptr == NULL)
    printf("\nList is empty");
    
    while(ptr != NULL){
        printf(" %d",ptr->data);
        ptr = ptr->next;
    }
}

void search(){
    int key , n_key = 0;
    printf("enter the vlaue of an element to be searched  : ");
    scanf("%d",&key);

    struct node* ptr = head->next;
    struct node* prev;

    if(head == NULL)
    printf("list is empty");

    else{
        while(ptr != NULL){
            if(key == ptr->data){
                
                n_key++;

                if(ptr->next == NULL){
                    prev->next = NULL;
                }

                else{
                    prev->next = ptr->next;
                }
            }
            prev = ptr;
            ptr = ptr->next;
        }

        for(int i=0 ; i<n_key ; i++){
            struct node* newnode = (struct node*)malloc(sizeof(struct node));

            newnode->data = key;
            newnode->next = head;
            head = newnode;
        }
    }

    if(n_key == 0)
    printf("\n\n--------------error 404!----------------");

    else{
        printf("edited list is : ");
        traverse();
    }
}

int main(){

    create_list();
    printf("\nthe list is : ");

    traverse();
    
    printf("\n");
    search();
        
    return 0;
}

// 8 12 2 12 4 12 6 7 12 12

