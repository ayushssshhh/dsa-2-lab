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

void specific(){
    int m;
    printf("enter the value of m : ");
    scanf("%d",&m);
    if(n_nodes >= m){
        int pos = n_nodes - m;
        int i = 0;
        struct node* ptr = head;
        
        while(i<pos){
            ptr = ptr->next;
            i++;
        }

        printf("\nthe mth last element in the list is : %d",ptr->data);
    }

    else if(head == NULL)
    printf("\nthe list is empty");

    else
    printf("the list is too small and doesnt have 3rd last element");
}

int main(){

    create_list();
    printf("\nthe list is : ");

    traverse();

    specific();
        
    return 0;
}

//5 12 98 90 57 32
//67 y 89 y 62 y 0 y 9 y 21 y 300 n 