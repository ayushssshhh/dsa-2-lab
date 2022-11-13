#include <stdio.h>

int main(){

    int a[] = {31, 52 , 23 , 24 ,135 , 90 , 83 , 712};
    
    int n = sizeof(a)/4;

    printf("\narray before linear sorting : ");
    for(int i=0 ; i<n ; i++)
    printf(" %d",a[i]);

    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(a[i]>a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\narray after linear sorting : ");
    for(int i=0 ; i<n ; i++)
    printf(" %d",a[i]);

    return 0;
}