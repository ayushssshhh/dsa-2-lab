#include <stdio.h>
#include <stdlib.h>

struct node{
    int coff;
    int pow;
    struct node* next;
};

int* create_list(struct node *head_add , int n_node){
    struct node *ptr , *newnode , *head;

    head = NULL;

    for(int i=0 ; i<n_node ; i++){

        newnode = (struct node*)malloc(sizeof(struct node));

        printf("enter the coff. x : ");
        scanf("%d",&newnode->coff);
        printf("enter power of x : ");
        scanf("%d",&newnode->pow);
        newnode->next = NULL;
        
        if(head == NULL){
            ptr = newnode;
            head = newnode;
        }

        else{
            ptr->next = newnode;
            ptr = newnode;
        }
    }

    return (&head);
}

void dis(struct node* head_add , int n_node){
    struct node* ptr , head;

    head = *head_add;
    ptr = head;

    
    for(int i=0 ; i<n_node ; i++){
        
        printf("+%dx^%d ",ptr->coff , ptr->pow);
            
        ptr = ptr->next; 
    }
}

int main(){
   int *head1 = NULL;
   int *head2 = NULL;

    int n_node1 , n_node2;

    printf("enter order of both polynomial respectively : ");
    scanf("%d%d",&n_node1 , &n_node2);

    n_node1++;
    n_node2++;

    printf("\n\n-------creation of polynomial-----------\n\n1st polynomial :\n");
    *head1 = create_list(&head1 , n_node1);
    
    printf("\n2nd polynomial :\n");
    *head2 = create_list(&head2 , n_node2);

    printf("\n\n--------displaying polynomial------------\n\npolynomial 1 : ");
    dis(&head1 , n_node1);
    printf("\npolynomial 2 : ");
    dis(&head2 , n_node2);

    return 0;
}
//3 2 89 3 45 2 1 1 8 0 33 2 80 1 67 0