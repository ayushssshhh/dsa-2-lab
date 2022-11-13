#include <stdio.h>
int i=0;

void search(int *a , int x , int n){
    if(*a == x){
        printf("\n%d is found",x);
    }

    else if(i == n){
        printf("\n%d is not found",x);
    }

    else{
        search((a+1) , x , n);
        i++;
    }
}

int main(){
    
    int a[] = {31, 52 , 23 , 24 ,135 , 90 , 83 , 712};
    
    int x , n = sizeof(a)/4;

    printf("\narray is : ");
    for(int i=0 ; i<n ; i++)
    printf(" %d",a[i]);

    printf("\nenter no. to search : ");
    scanf("%d",&x);
    search(&a , x , n);

    return 0;
}