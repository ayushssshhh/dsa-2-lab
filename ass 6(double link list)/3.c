#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next ;
    struct node *prev;
};

struct node* tail = NULL;
struct node* head = NULL;
int n_node;

void create_dl(){
    printf("enter the no. of node you want to create : ");
    scanf("%d",&n_node);
    struct node* newnode;
    for(int i=0 ; i<n_node ; i++){
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("enter data : ");
        scanf("%d",&newnode->data);

        newnode->next = newnode->prev = NULL;

        if(head == NULL){
            head = tail = newnode;
        }

        else{
            newnode->prev = tail;
           tail = tail->next = newnode;
        }
    }
       
}

void traverse_f(){
    struct node* ptr = head;

    while(ptr != NULL){
        printf(" %d",ptr->data);
        ptr = ptr->next;
    }
}

void traverse_r(){
    struct node* ptr = tail;

    while(ptr != NULL){
        printf(" %d",ptr->data);
        ptr = ptr->prev;
    }
}

void check(){
    if (head == NULL){
        printf("\nthe ist is empty");
    }

    else
    printf("\nthe list is not empty");
}

void insert_at_beg(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    printf("enter the data to insert : ");
    scanf("%d",&newnode->data);
    newnode->next = newnode->prev = NULL;

    newnode->next = head;
    head = newnode;

    newnode->prev = NULL;

    struct node* ptr = tail;

    while(ptr->prev != NULL)
    ptr = ptr->prev;

    ptr->prev = newnode;
    n_node++;

    traverse_f();
    printf("\n");
    traverse_r();

}

void insert_at_end(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    printf("enter the data to insert : ");
    scanf("%d",&newnode->data);
    newnode->next = newnode->prev = NULL;

    newnode->prev = tail;
    tail = newnode;

    newnode->next = NULL;

    struct node* ptr = head;

    while(ptr->next != NULL)
    ptr = ptr->next;

    ptr->next = newnode;
    n_node++;

    traverse_f();
    printf("\n");
    traverse_r();

}

void insert_mid(){

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    int pos;

    printf("enter the pos where you want new data : ");
    scanf("%d",&pos);

    if(pos == 1)
    insert_at_beg();

    else if(pos == n_node)
    insert_at_end();

    else{
        
        printf("\nenter data to insert : ");
        scanf("%d",&newnode->data);
        struct node *ptrf , *ptrr , *tempf , *tempr;
        ptrf = tempf = head;
        ptrr = tempr = tail;

        int i = 1;
        while((ptrf != NULL) && (i<pos)){
            tempf = ptrf;
            ptrf = ptrf->next;
            i++;
        }

        i = 1;
        while((ptrr != NULL) && (i < (n_node-pos+2))){
            tempr = ptrr;
            ptrr = ptrr->prev;
            i++;
        }
        newnode->next = tempf->next;
        tempf->next = newnode;

        newnode->prev =  tempr->prev;
        tempr->prev = newnode;      

        n_node++;
        traverse_f();
        printf("\n");
        traverse_r();
    }
}

void delete_beg(){

    struct node* ptr , *temp;

    ptr = head;
    head = head->next;
    free(ptr);

    ptr = tail;
    while(ptr->prev != NULL){
        temp = ptr;
        ptr = ptr->prev;
    }

    temp->prev = NULL;
    free(ptr);

    n_node--;
    traverse_f();
    printf("\n");
    traverse_r();
}

void delete_end(){

    struct node* ptr , *temp;

    ptr = tail;
    tail = tail->prev;
    free(ptr);

    ptr = head;
    while(ptr->next != NULL){
        temp = ptr;
        ptr = ptr->next;
    }

    temp->next = NULL;
    free(ptr);

    n_node--;
    traverse_f();
    printf("\n");
    traverse_r();
}

void delete_mid(){
    int pos;
    printf("enter the pos at which you want to delete a node : ");
    scanf("%d",&pos);

    if(pos == 1)
    delete_beg();

    else if(pos == n_node)
    delete_end();

    else{
        int i = 2 ; 
        struct node *ptr , *temp;
        ptr = head->next;

        while((ptr->next != NULL)&&(i<pos)){
            temp = ptr;
            ptr = ptr->next;
            i++;
        }

        ptr->next->prev = temp;
        temp->next = ptr->next;

        free(ptr);

        n_node--;
        traverse_f();
        printf("\n");
        traverse_r();
    }
}

void delete_key(){
    int key;
    printf("enter the key to be deleted : ");
    scanf("%d",&key);
    
    if(key == head->data)
    delete_beg();

    else if(key == tail->data)
    delete_end();

    else{
        struct node *ptr , *temp;
        ptr = head->next;

        while (ptr->next != NULL){
            temp = ptr;
            ptr = ptr->next;

            if(temp->data == key)
            break;            
        }

        temp->prev->next = ptr;
        ptr->prev = temp->prev;

        free(temp);

        n_node--;
        traverse_f();
        printf("\n");
        traverse_r();


    }
}

void search(){
    struct node* ptr = head;

    int key , i=0;
    printf("enter the key to be searched : ");
    scanf("%d",&key);

    while(ptr != NULL){
        if(key == ptr->data)
        i++;
        ptr = ptr->next;
    }

    if(i>0)
    printf("%d is in the linked list and it is found for %d times",key,i);

    else
    printf("%d is not present in linked list",key);

}

int main(){
    printf("\n\n----creation of double liked list------\n\n");
    create_dl();

    printf("\n\n---forward traversing------\n\n");
    traverse_f();

    printf("\n\n----reverse traversing-------\n\n");
    traverse_r();

    printf("\n\n----counting no. of nodes-------\n\ntotal no. of node is : %d",n_node);

    printf("\n\n------checking list status-----\n\n");
    check();

    printf("\n\n------insertion at beg-----\n\n");
    insert_at_beg();

    printf("\n\n------insertion at end-----\n\n");
    insert_at_end();

    printf("\n\n------insertion at anypos-----\n\n");
    insert_mid();

    printf("\n\n------deletion at beg-----\n\n");
    delete_beg();

    printf("\n\n------deletion at end-----\n\n");
    delete_end();

    printf("\n\n------deletion at anypos-----\n\n");
    delete_mid();

    printf("\n\n------deletion of key-----\n\n");
    delete_key();

    printf("\n\n------searching-----\n\n");
    search();

    return 0;
}

//4 1 2 3 4 71 12 3 780 4