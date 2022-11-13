#include <stdio.h>
#include <stdlib.h>

//function prototyping
void create();
void traverse();

void deletion();
void delete_begin();
void delete_end();
void delete_mid();

struct node{
    int data;
    struct node* next;
};

struct node* head;

int main(){

    int n;
    char ch;
    do{
        printf("\n\n----------LINKED LIST OPERATION------------\n\npress 1 to create an linked list\npress 2 display linked list\npress 3 for deleting any element from linked list\n\n enter your choice : ");
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
            deletion();
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

void deletion(){
    int c;
    char ch;   
    do{
        printf("\n\n---------select between following deletion opperation---------\npress 1 to delete an element from begining\npress 2 to delete an element from the end\npress 3 to delete an element from the middle\nenter your choice : ");
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

            default:
            printf("\n------------error 404!(please choce an valid option)-----------");
            break;
        }

        printf("\n\ndo you want to continue ???\n\npress y or Y to to continue or any other key to exit : ");
        scanf(" %c",&ch);
    }while((ch == 'y') || (ch == 'Y'));

}

void delete_begin(){
    struct node* ptr;
    
    if(head==NULL)
    printf("List is empty");

    else{
        ptr = head;
        head = ptr->next;
        free(ptr);
    }
}

void delete_end(){
    struct node* ptr = head;
    struct node* temp;

    if(head == NULL)
    printf("List is empty");

    else if(head->next == NULL){
        head = NULL;
        free(ptr);
    }

    else{
        while(ptr->next != NULL){
            temp = ptr;
            ptr = ptr->next;
        }

        temp->next = NULL;
        free(ptr);
    }
}

void delete_mid(){

}