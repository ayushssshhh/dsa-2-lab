#include <stdio.h>

int main(){

    int n1 , n2 , m ,  carry=0;
    printf("enter highest power of 1st polynomial : ");
    scanf("%d",&n1);

    int a[n1];
    printf("enter the 1st polynomial : ");
    for(int i=n1-1 ; i>=0 ; i-- )
        scanf("%d",&a[i]);
    
    printf("enter highest power of 2nd polynomial : ");
    scanf("%d",&n2);

    int b[n2];
    printf("enter the 2nd polynomial : ");
    for(int i=n2-1 ; i>=0 ; i-- )
        scanf("%d",&b[i]);

    if(n1>n2){
        m=n1;
        int c[m];
        for(int i=0 ; i<m ; i++)
        c[i]=a[i];
        for(int i=0 ; i<n2 ; i++)
        c[i]=c[i]-b[i];
        printf("the ploynomial is : ");

        for(int i=m-1 ; i>=0 ; i-- )
        printf("%dx^%d ",c[i],i);

    }

    else{
        m=n2;
        int c[m];
        for(int i=0 ; i<m ; i++)
        c[i]=b[i];
        for(int i=0 ; i<n1 ; i++)
        c[i]=c[i]+a[i];

        printf("the ploynomial is : ");
        for(int i=m-1 ; i>=0 ; i-- )
        printf("%dx^%d ",c[i],i);

    }

    return 0;    

}