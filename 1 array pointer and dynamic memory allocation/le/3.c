#include<stdio.h>

int main(){

    int n;
    printf("enter the no. of elements in the array : ");
    scanf("%d",&n);

    int a[n] , temp , c=0;

    for(int i=0 ; i<n ; i++)
    scanf("%d",&a[i]);

    printf("enter the element which is to be searched in the array : ");
    scanf("%d",&temp);

    for(int i=0 ; i<n ; i++){
        if(a[i]==temp){
            i=n;
            c++;
            printf("%d is found in the array",temp);
        }
    }

    if(c==0)
    printf("%d is not found in the array",temp);

    return 0;
}