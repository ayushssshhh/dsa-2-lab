#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head;
int n_node;
int n_key=0;
int key;

void create_list(){
    printf("enter number nodes you want to create : ");
    scanf("%d",&n_node);

    for(int i=0 ; i<n_node ; i++){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        struct node* temp;
        printf("enter data %d : ",i);
        scanf("%d",&newnode->data);
        newnode->next = NULL;

        if(head == NULL){
            head = newnode;
            temp = newnode;
        }

        else{
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void traverse(){
    struct node* ptr = head;

    if(head == NULL)
    printf("the link list is empty \n");

    else{
        printf("\nthe link list is :");
        while(ptr != NULL){
            printf(" %d",ptr->data);
            ptr = ptr->next;
        }
    }
}

int* occ(){
    struct node* ptr = head;
    
    static int pos[100];
    
    int c = 0;
    printf("\nenter the value of key to be searched : ");
    scanf("%d",&key);

    while(ptr != NULL){
        
        c++;
        
        if(ptr->data == key)
        pos[n_key++] = c;
        
        ptr = ptr->next;        
    }

    static int* p = pos;

    return(p);
}


int main(){

    create_list();
    traverse();
    
    int *p = occ();

    if(n_key == 0)
    printf("\n%d not found in the list",key);

    else{
        printf("\n%d is found in the list at pos :",key);
        
        for(int i=0 ; i<n_key ; i++){
            printf(" %d",*(p+i));
        }
    }
    return 0;
}