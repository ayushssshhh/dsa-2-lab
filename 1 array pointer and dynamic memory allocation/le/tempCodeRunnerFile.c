#include<stdio.h>

int main(){

    int n;
    printf("enter the no. of elements in the array : ");
    scanf("%d",&n);

    int a[n] , c , b , count_a=0 , count_b=0 , pos_a , pos_b ;

    for(int i=0 ; i<n ; i++)
    scanf("%d",&a[i]);

    printf("enter the no. to be searhed in the array :");
    scanf("%d%d",&c,&b);

    for(int i=0 ; i<n ; i++){

        if((a[i]==c)&&(count_a==0));{
            count_a++;
            pos_a=i;
        }

        if((a[i]==b)&&(count_b==0)){
            count_b++;
            pos_b=i;
        }
    }

    int d = pos_a - pos_b;

    if(d<0)
    d=d*(-1);

    if((count_a==1)&&(count_b==1))
    printf("the dis between %d and %d value in the array is : %d",c,b,d+2);

    else
    printf("the dis between %d and %d value in the array is : a0",c,b);

    printf("\n%d",count_a);

    return 0;
}

