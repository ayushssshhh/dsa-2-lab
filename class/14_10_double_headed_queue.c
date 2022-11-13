#include<stdio.h>
#include<stdlib.h>
struct node{
    int pr;
    int ele;
    struct node *next;
};
struct node *f=NULL;
void insert_PQ(int p,int v)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->pr=p;
    newnode->ele=v;
    newnode->next=NULL;
    if(f==NULL)
    {
        f=newnode;
    }
    else if(f!=NULL && f->pr>p)
    {
        newnode->next=f;
        f=newnode;
    }
    else{
        struct node *prev=NULL;
        struct node *temp=f;
        while(temp->next!=NULL && temp->pr<p)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            temp->next=newnode;
        }
        else{
            prev->next=newnode;
            newnode->next=temp;
        }
    }
}
void delete_PQ()
{
    if(f==NULL)
    {
        printf("underflow condition\n");
    }
    else{
        struct node *ptr=f;
        f=f->next;
        free(ptr);
    }
}
void traverse_PQ()
{
    struct node *ptr=f;
    while(ptr->next!=NULL)
    {
        printf("\nThe data is : %d",ptr->ele);
        printf("\nThe priority is : %d",ptr->pr);
        ptr=ptr->next;
    }
}
int main()
{
    int n;
    printf("enter the number of elements:");
    scanf("%d",&n);
    int k;char ch;
    int i,p1,v1;
    do{
        printf("enter 1 for insertion 2 for deletion and 3 for traversal of the pririty queue\n");
        printf("enter your choice!!\n");
        scanf("%d",&k);
        switch(k)
        {
            case 1:
            for(i=0;i<n;i++)
            {
                printf("\nenter the element :");
                scanf("%d",&v1);
                printf("\nenter the priority of the element :");
                scanf("%d",&p1);
                insert_PQ(p1,v1);
            }
            break;
            case 2:
            delete_PQ();
            break;
            case 3:
            traverse_PQ();
            break;
        }
        printf("\ndo you want to continue? y/n  :");
        scanf(" %c",&ch);
    }
    while(ch=='y');
    return 0;
   
}