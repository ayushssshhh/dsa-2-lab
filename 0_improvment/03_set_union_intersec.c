#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};



void create_set(struct node *head , int n_node){
    struct node *ptr , *newnode;
    ptr = head;

    for(int i=0 ; i<n_node ; i++){
        newnode = (struct node*)malloc(sizeof(struct node));

        scanf("%d",&newnode->data);
        newnode->next = NULL;

        if(head == NULL)
        head = ptr = newnode;

        else
        ptr = ptr->next = newnode;
    }
}

void dis_set(struct node *head){
    struct node *ptr = head->next;

    while(ptr != NULL){
        printf(" %d",ptr->data);
        ptr = ptr->next;
    }
}

void set_op(struct node *head1 , struct node *head2 , int n1 ,int n2){

    struct node *ptr1 , *ptr2;
    int c , n_i = 0 , n_u = 0;
    int in[n1+n2] , u[n1+n2];


    ptr1 = head1->next;

    for(int i=0 ; i<n1 ; i++ ){
        ptr2 = head2->next;
        c = 0;
        
        u[n_u++] = ptr1->data;

        for(int j=0 ; j<n2 ; j++){
            if(ptr1->data == ptr2->data)
            c++;
            ptr2 = ptr2->next;
        }

        if(c > 0)
        in[n_i++] = ptr1->data;

        ptr1 = ptr1->next;
    }

    ptr2 = head2->next;
    
    while(ptr2 !=NULL){
        c=0;
        
        for(int j=0 ; j<n_u ; j++){
            if(ptr2->data == u[j])
            c++;
        }

        if(c == 0)
        u[n_u++] = ptr2->data;

        ptr2 = ptr2->next;
        
    }

    printf("\nunion of set 1 and set 2 is : ");
    for(int i=0 ; i<n_u ; i++)
    printf(" %d",u[i]);

    printf("\nintersection of set 1 and set 2 is : ");
    for(int i=0 ; i<n_i ; i++)
    printf(" %d",in[i]);



}

int main(){

    struct node *head1 = NULL , *head2 = NULL;
    int n_node1 = 0 , n_node2 = 0;
    
    printf("\nenter no. elements for set 1 and se 2 respectively : ");
    scanf("%d%d",&n_node1 , &n_node2);

    printf("\n---------input sets------------\n");
    printf("\nenter set 1 : ");
    create_set(&head1 , n_node1);

    printf("\nenter set 2 : ");
    create_set(&head2 , n_node2);

    printf("\nset 1 : ");
    dis_set(&head1);
    
    printf("\nset 2 : ");
    dis_set(&head2);

    printf("\n----------set operation------------\n");
    set_op(&head1 , &head2 , n_node1 , n_node2);

    return 0;
}

//5 3 1 2 3 4 5 4 5 6