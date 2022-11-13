#include <stdio.h>

int main(){

    int a[10] ,  n , temp1 , temp2 , v;
    for (int i=0 ; i<5 ; i++)
    scanf("%d",&a[i]);

    printf("enter the pos at which you want to add an element  and value of the element : ");
    scanf("%d%d",&n,&v);
    temp1=a[n-1];
    for(int i=n-1 ; i<=5 ; i++){
        temp2=a[i+1] ;
        a[i+1]=temp1;
        temp1=temp2;
    }
    a[n-1]=v;
     for(int i=0 ; i<=5 ; i++)
     printf("%3d",a[i]);
    return 0;    
}