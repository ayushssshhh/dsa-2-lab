#include <stdio.h>
#include <stdlib.h>

struct node{
    int coff;
    int pow;
    struct node* next;
};

struct node* head_mul = NULL;
int n_node_mul = 0;

void create_list(struct node *head , int n_node){
    struct node *ptr , *newnode;
    ptr = head;
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
}

void dis(struct node* head){
    
    struct node* ptr = head->next;
 
    while(ptr != NULL){
        printf("+%dx^%d ",ptr->coff , ptr->pow);
        ptr = ptr->next; 
    }
}

void mul(struct node* head1 , struct node* head2){

    struct node *newnode ,*ptr , *ptr1 = head1->next , *prev , *ptr2;

    while (ptr1 !=NULL){

        ptr2 = head2->next;
        
        while (ptr2 != NULL){
            
            newnode = (struct node*)malloc(sizeof(struct node));
 
            newnode->coff = ptr1->coff * ptr2->coff;
            newnode->pow = ptr1->pow + ptr2->pow;
            newnode->next = NULL;

            if(head_mul == NULL){
                head_mul = ptr = newnode;
               
            }

            else{
                
                ptr = ptr->next = newnode;
            }
            n_node_mul++;

            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;

    }
    
    ptr1 = head_mul;

    while(ptr1 != NULL){
        
        prev = ptr1;
        ptr2 = ptr1->next;

        while(ptr2 != NULL){
                
            if(ptr1->pow == ptr2->pow){
                ptr1->coff += ptr2->coff;
                prev->next = ptr2->next;
                n_node_mul--;
            }
            prev = ptr2;
            ptr2 = ptr2->next;
        }

        ptr1 = ptr1->next;
        
    }
    
}

int main(){
   struct node *head1 = NULL;
   struct node *head2 = NULL;
   struct node* sum_head = NULL;

    int n_node1 , n_node2;

    printf("enter order of both polynomial respectively : ");
    scanf("%d%d",&n_node1 , &n_node2);

    n_node1++;
    n_node2++;

    printf("\n\n-------creation of polynomial-----------\n\n1st polynomial :\n");
    create_list(&head1 , n_node1);
    printf("\n2nd polynomial :\n");
    create_list(&head2 , n_node2);

    printf("\n\n--------displaying polynomial------------\n\npolynomial 1 : ");
    dis(&head1);
    printf("\npolynomial 2 : ");
    dis(&head2);

    mul(&head1 , &head2);
    printf("\n\n--------multiplicatioon of polynomial------------\n\n polynomial : ");
    dis(head_mul);
    
    return 0;
}
//3 2 89 3 45 2 1 1 8 0 33 2 80 1 67 0