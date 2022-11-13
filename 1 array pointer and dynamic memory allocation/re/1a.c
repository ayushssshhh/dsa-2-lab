#include <stdio.h>

int main(){

    int n , k ;
    printf("enter no. of element in the array : ");
    scanf("%d",&n);

    int a[n] , i;
    printf("enter the %d values which is to be stored in the array : ",n);
    for(i=0 ; i<n ; i++)
    scanf("%d",&a[i]);

    for(int j=0 ; j<n ; j++){
        for(i=0 ; i<n ; i++){
            if((a[i]>a[i+1])&&((i+1)<n)){
                int temp = a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }   
        }
    }

    printf("enter the vlue of k : ");
    scanf("%d",&k);

    printf("the %dth greatest no. is : %d\nthe %dth smallest no. is : %d\n\n",k,a[n-(k)],k,a[k-1]);

    return 0;
}

// 10 12 34 87 09 12 65 56 83 41 10 1