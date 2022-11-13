#include <stdio.h>

void binary_search(int *a , int n , int x){
    
    if(n/2 == 0){
        printf("\n%d is not found",x);
    }

    else if(x > *(a+n/2)){
        binary_search((a+n/2) , n/2 ,x);
    }

    else if(x < *(a+n/2)){
        binary_search(a , n/2 , x );
    }

    else if(x == *(a+n/2)){
        printf("\n%d is found",x);
    }
}

int main(){

    int a[] = {31, 52 , 23 , 24 ,135 , 90 , 83 , 712};
    
    int x , n = sizeof(a)/4;

    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(a[i]>a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\narray is : ");
    for(int i=0 ; i<n ; i++)
    printf(" %d",a[i]);

    printf("\nenter no. to search : ");
    scanf("%d",&x);
    binary_search(&a , n , x);

    return 0;
}