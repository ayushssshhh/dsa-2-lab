#include <stdio.h>
#include<stdlib.h>

struct node{
    int no;
    int freq;
    struct node* next;
};

struct node* head = NULL;

int main(){
    int n;
    printf("\nenter the the size of size : ");
    scanf("%d",&n);

    int a[n] , f[n];

    for(int i=0 ; i<n ; i++){
        scanf("%d",&a[i]);
    }

    f[0] = a[0];
    int c = 1 , b; 

    for(int i=0 ; i<n ; i++){
        b=0;

        for(int j=0 ; j<c ; j++){
           
            if(a[i] == f[j]){
                b++;
                break;
            }
        }

        if(b == 0)
        f[c++] = a[i];
        
    }

    int sort[c];
    for(int j=0 ; j<c ; j++){
        int n_f = 0;
        for(int i=0 ; i<n ; i++){
            if(f[j] == a[i])
            n_f++;
        }
        sort[j] = n_f;
    }

    struct node *newnnode , *ptr , *temp , *prev;

    for(int i=0 ; i<c ; i++){

        newnnode = (struct node*)malloc(sizeof(struct node));

        newnnode->no = f[i];
        newnnode->freq = sort[i];
        newnnode->next = NULL;

        if(head == NULL)
        head = ptr = newnnode;

        else
        ptr = ptr->next = newnnode;   

    }

    for(int i=0 ; i<c ; i++){
        ptr = head;
        for(int j=0 ; j<c-1 ; j++){
            
            if(ptr->freq > ptr->next->freq){
                
                int temp1 = ptr->no ;
                int temp2 = ptr->freq;
                
                ptr->freq = ptr->next->freq;
                ptr->no = ptr->next->no;
                
                ptr->next->freq = temp2;
                ptr->next->no = temp1;
            }
            ptr = ptr->next;
        }
    }

    ptr = head;
    for(int i=0 ; i<c ; i++){
        printf("%d ",ptr->no);
        ptr = ptr->next;
    }
    
    return 0;   
}

//10 2 4 2 8 9 8 8 4 4 8   