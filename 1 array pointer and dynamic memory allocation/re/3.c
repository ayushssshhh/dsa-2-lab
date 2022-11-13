#include <stdio.h>

int main(){

    int n;
    printf ("enter no. of element in the array : ");
    scanf("%d",&n);

    int a[n],b[n] , j=0 , k=0;

    for(int i=0 ; i<n ; i++)
    scanf("%d",&a[i]);

    for(int i=0 ; i<n ; i++){

        if(a[i]%2==0)
        b[j++]=a[i];

        else
        b[n-1-(k++)]=a[i];
        
    }

    printf("\nthe sorted array is : ");
    for(int i=0 ; i<n ; i++)
    printf(" %3d", b[i]);
}