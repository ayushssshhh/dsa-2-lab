#include<stdio.h>

int main(){

    int n;
    printf("enter the no. of elements in the array : ");
    scanf("%d",&n);

    int a[n] , temp , m=n-1;

    for(int i=0 ; i<n ; i++)
    scanf("%d",&a[i]);

    for(int i=0 ; i<n/2 ; i++){
        temp=a[i];
        a[i]=a[m];
        a[m--]=temp;
    }

    printf("the reversed array is : ");
    for(int i=0 ; i<n ; i++)
    printf("%3d",a[i]);
    return 0;
}