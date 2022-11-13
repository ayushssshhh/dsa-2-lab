#include<stdio.h>

int main(){

    int n;
    printf("enter no. of elements in your array : ");
    scanf("%d",&n);
    
    int a[n],b[n];

    printf("enter the value of the elements of array : ");
    for (int i=0 ; i<n ; i++)
    scanf("%d",&a[i]);

    printf("\n\n\nd");
    b[0]=a[0];
    b[n-1]=a[n-1];

    for(int i=1 ; i<n-1 ; i++)
    b[i]=a[i-1]*a[i+1];

    printf("the updated array is :");
    for(int i=0 ; i<n ; i++)
    printf("%5d",b[i]);
    return 0;
}