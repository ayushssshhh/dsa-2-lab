#include <stdio.h>

int main(){

    int n1 , n2 , m=0;
    printf("enter size of 1st polynomial : ");
    scanf("%d",&n1);

    int a[n1];
    printf("enter the 1st polynomial : ");
    for(int i=n1-1 ; i>=0 ; i-- )
        scanf("%d",&a[i]);
    
    printf("enter size of polynomial : ");
    scanf("%d",&n2);

    int b[n2];
    printf("enter the 2nd polynomial : ");
    for(int i=n2-1 ; i>=0 ; i-- )
        scanf("%d",&b[i]);

    int c[(n1+n2-1)];

    for(int i=0 ; i<n1+n1-1 ; i++)
    c[i]=0;

    for(int i=0 ; i<n1 ; i++){
        for(int j=0 ; j<n2 ; j++)
        c[i+j] += a[i]*b[j];
    }

    printf("\n\nthe 1st polynomial is : ");
    for(int i=n1-1 ; i>=0 ; i-- )
        printf("%dx^%d ",a[i],i);

    printf("\n\nthe 2nd polynomial is : ");
    for(int i=n2-1 ; i>=0 ; i-- )
        printf("%dx^%d ",b[i],i);

    printf("\n\nthe polynomial is : ");
    for(int i=n1+n2-2 ; i>=0 ; i-- )
        printf("%dx^%d ",c[i],i);

    return 0;

}

//3 3 5 4 2 2 5