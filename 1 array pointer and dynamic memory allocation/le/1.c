#include<stdio.h>

int main(){

    int n,min,max;
    printf("enter no. of element : ");
    scanf("%d",&n);

    int a[n];

    printf("\n\nenter the %d values which is to be stored in the array : ",n);
    for(int i=0 ; i<n ; i++)
    scanf("%d",&a[i]);

    min=max=a[0];

    for(int i=0 ; i<n ; i++){
        
        if(a[i]>max)
        max=a[i];

        if(a[i]<min)
        min=a[i];
    }

    printf("the max no. and min no. stored in the array is : %d %d respectively",max,min);

    return 0 ;
}