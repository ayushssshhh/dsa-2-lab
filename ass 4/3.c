#include <stdio.h>
#include <stdlib.h>


//function prototyping
void create();
void traverse();

void insertion();
void insert_begin();
void insert_end();
void insert_mid();

void deletion();
void delete_begin();
void delete_end();
void delete_mid();
void delete_key();

void count_node();

void search();


//linked list structured node
struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

//main function
int main(){

    int n;
    char ch;
    do{
        printf("\n\n----------LINKED LIST OPERATION------------\n\npress 1 to create an linked list\npress 2 display linked list\npress 3 for insert an element in linked list\npress 4 for deleting any element from linked list\npress 5 to count no. of nodes\npress 6 to search an element\n\n enter your choice : ");
        scanf("%d",&n);
        switch (n)
        {
        case 1 : 
            create();
            break;
        
        case 2 :
            traverse();
            break;
        
        case 3 :
            insertion();
            break;

        case 4 :
            deletion();
            break;

        case 5 :
            count_node();
            break;

        case 6 :
            search();
            break;
            
        default:
            printf("selecet a valid linked list opperation");
            break;
        }
        printf("\n\ndo you want to continue???\npress Y to continue or any other key to exit\nenter your choice : ");
        scanf(" %c",&ch);
    }while((ch == 'y') || (ch == 'Y'));

    return 0;
}

//function for linked list operation

void create(){

    struct node *temp;
    char ch;
    int i=1;

    printf("\n\n-----enter data in your linked list------\n\n");
    do{
        struct node *newnode = (struct node*)malloc(sizeof(struct node));

        printf("enter data %d : ",i++);
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

        printf("\n\ndo you want to continue ???\n\npress y or Y to to continue or any other key to exit : ");
        scanf(" %c",&ch);
    }while((ch == 'y') || (ch == 'Y'));
}


void traverse(){
    printf("\n\nthe linked list is : ");
    struct node *ptr;
    ptr = head;
    while (ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

void insertion(){

    int c;
    char ch;   
    do{
        printf("\n\n---------select between following insertion opperation---------\npress 1 to insert in the begining\npress 2 to insert at the end\npress 3 to insert in middle\nenter your choice : ");
        scanf("%d",&c);

        switch (c){

            case 1 : 
            insert_begin();
            traverse();
            break;

            case 2 :
            insert_end();
            traverse();
            break;

            case 3 :
            insert_mid();
            traverse();
            break;

            default:
            printf("\n------------error 404!(please choce an valid option)-----------");
            break;
        }

        printf("\n\ndo you want to continue ???\n\npress y or Y to to continue or any other key to exit : ");
        scanf(" %c",&ch);
    }while((ch == 'y') || (ch == 'Y'));
    
}

void deletion(){
    int c;
    char ch;   
    do{
        printf("\n\n---------select between following deletion opperation---------\npress 1 to delete an element from begining\npress 2 to delete an element from the end\npress 3 to delete an element from the middle\npress 4 to delete any specific key\nenter your choice : ");
        scanf("%d",&c);

        switch (c){

            case 1 : 
            delete_begin();
            traverse();
            break;

            case 2 :
            delete_end();
            traverse();
            break;

            case 3 :
            delete_mid();
            traverse();
            break;

            case 4 :
            delete_key();
            traverse();
            break;

            default:
            printf("\n------------error 404!(please choce an valid option)-----------");
            break;
        }

        printf("\n\ndo you want to continue ???\n\npress y or Y to to continue or any other key to exit : ");
        scanf(" %c",&ch);
    }while((ch == 'y') || (ch == 'Y'));
    
}

void count_node(){
    struct node* ptr = head;
    int i=0;
    while(ptr != NULL){
        ptr = ptr->next;
        i++;
    }

    printf("\n total no. of nodes = %d",i);
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
    printf("%d is in the linked list",key);

    else
    printf("%d is not present in linked list",key);

}

//insertion operation
void insert_begin(){

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nenter data : ");
    scanf("%d",&newnode->data);
    newnode->next = head;
    head = newnode;
}

void insert_end(){

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nenter data : ");
    scanf("%d",&newnode->data);

    struct node *ptr;
    struct node *temp;
    ptr = head;
    
    while (ptr != NULL){
        temp = ptr;
        ptr = ptr->next;
    }

    temp->next = newnode ; 
    newnode->next = NULL;
    
}

void insert_mid(){

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    int pos , i=1;

    printf("\nenter data : ");
    scanf("%d",&newnode->data);
    printf("enter the pos where you want new data : ");
    scanf("%d",&pos);

    struct node *ptr ;
    struct node *temp;
    ptr = temp = head;

    while((ptr != NULL) && (i<pos)){
        temp = ptr;
        ptr = ptr->next;
        i++;
    }

    if(i == 1){
        newnode->next = head;
        head = newnode;
    }

    else{
        newnode->next = temp->next;
        temp->next = newnode;
    }        
}

//deletion operation
void delete_begin(){
    head = head->next;
}

void delete_end(){
    struct node* ptr = head;
    struct node* temp;

    while (ptr!=NULL)
    {
        temp = ptr;
        ptr = ptr->next;
    }

    temp->next = ptr;
}

void delete_mid(){
     struct node* ptr = head;
    struct node* temp = head;

    int pos , i=0;
    printf("enter the pos of an element that you want to delete : ");
    scanf("%d",&pos);

    if(pos == 1)
    head = ptr->next;
    
    while((ptr!=NULL) && (i<pos)){
        temp = ptr;
        ptr = ptr->next;
        i++;
    }

    temp->next = ptr->next;
}

void delete_key(){

    struct node* ptr = head;
    struct node* temp = head;

    int key;
    printf("enter the value of key to be deleted : \n");
    scanf("%d",&key);

    while((ptr->data != key)){
        temp = ptr;
        ptr = ptr->next;
    }

    if(ptr->data == key){
        temp->next = ptr->next;
        free(ptr);
    }

    else
    printf("\n %d key value is not found",key);
}

//1 21 y  34 y  78 y 39 n y 2 y
//1 21 y  34 y  78 y 39 n y 2 y 4 4 78