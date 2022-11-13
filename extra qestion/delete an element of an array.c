#include <stdio.h>

int main(){

    int a[10] ,  n , temp1 , temp2 ;
    for (int i=0 ; i<5 ; i++)
    scanf("%d",&a[i]);

    printf("enter the pos at which you want to add an element : ");
    scanf("%d",&n);

    for(int i=n-1 ; i<5 ; i++)
    a[i]=a[i+1];

    for (int i=0 ; i<4 ; i++)
    printf("%3d",a[i]);

    return 0;
}