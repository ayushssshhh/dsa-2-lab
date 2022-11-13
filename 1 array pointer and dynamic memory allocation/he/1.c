#include<stdio.h>

int main(){
    
    int a[10],max,min,max2,min2;

    printf("Enter the elements of an array : ");
    for(int i=0 ; i<10 ; i++)
    scanf("%d",&a[i]);

    max=min=a[0];

    for(int i=0 ; i<10 ; i++){
        if(max<a[i])
        max=a[i];
        if(min>a[i])
        min=a[i];
    }

    printf("max : %d min : %d\n\n",min,max);
    min2=max,max2=min;
    for(int i=0 ; i<10 ; i++){
        
        if((max2<a[i])&&(a[i]!=max))
        max2=a[i];

        if((min!=a[i])&&(min2>a[i]))
        min2=a[i];
    }
        
    printf("\n\nthe 2nd greatest and smallest no. in the array is : %d and %d respectively",max2,min2);

    return 0;
}