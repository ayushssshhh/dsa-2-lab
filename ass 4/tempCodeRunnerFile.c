#include <stdio.h>
#include <stdlib.h>

struct node{
    int r;
    int c;
    int v;
    struct node* next;
};

struct node *head = NULL;

int main(){
    
    int m , n , c=0;
    
    printf("enter no. of row and col : ");
    scanf("%d%d",&m,&n);

    printf("\n----enter your matrix------\n");

    int a[m][n];

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            printf("enter %dx%d : " ,i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    printf("\n---------------the matrix is-----------\n\n");
    for(int i=0 ; i<m ; i++){
        printf("\n");
        for(int j=0 ; j<n ; j++){
            printf("%3d ",a[i][j]);
        }
    }

    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    head = ptr;
    head->r = m;
    head->c = n;

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(a[i][j]!=0){
                c++;
                struct node *newnode = (struct node*)malloc(sizeof(struct node));
                newnode->r = i;
                newnode->c = j;
                newnode-> v = a[i][j];
                newnode->next = NULL;
                ptr->next = newnode;
                ptr = newnode;
            }
        }
    }
    head->v = c;

    printf("\n\n---------------linked list of triplet form is-------------------\n\n");
    ptr = head;
    while(ptr != NULL){
        printf("\n%2d %2d %2d",ptr->r , ptr->c , ptr->v);
        ptr = ptr->next; 
    }

    return 0;

}
//4 4 0 0 0 0 0 0 5 0 6 0 0 0 0 0 0 8
