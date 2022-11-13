#include <stdio.h>

int main(){

    int n;
    printf("enter no. of element : ");
    scanf("%d",&n);

    int a[n] , max , n_max=0 ;

    printf("enter the %d values for the array : ",n);
    for (int i=0 ; i<n ; i++)
    scanf("%d",&a[i]);

    max=a[0];
    for(int i=0 ; i<n ; i++){

        if(a[i]>max){
            n_max=0;
            max=a[i];
        }

        if(a[i]==max)
        n_max++;
    }

    printf("the greatest no. in the array is : %d and it's occurance is %d time",max,n_max);

    return 0 ;

}