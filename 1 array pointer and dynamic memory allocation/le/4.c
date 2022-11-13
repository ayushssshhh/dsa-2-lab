#include<stdio.h>

int main(){

    int n;
    printf("enter the no. of elements in the array : ");
    scanf("%d",&n);

    int a[n] , temp , c=0;

    for(int i=0 ; i<n ; i++)
    scanf("%d",&a[i]);

    for(int j=0 ; j<n ; j++){
        for(int i=0 ; i<n ; i++ ){
            if((a[i]>a[i+1])&&((i+1)<n)){
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }

    printf("the sorted array is : ");
    for(int i=0 ; i<n ; i++)
    printf(" %d",a[i]);

    return 0;
}