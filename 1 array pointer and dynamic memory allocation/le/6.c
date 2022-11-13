#include <stdio.h>

int main()
{
    int a[5],max=0, c=0;
    printf("enter the elements of the array : ");
    for(int i=0 ; i<5 ; i++){
        scanf("%d",&a[i]);
    }
    
    printf("elements | Nge\n");
    for(int i=0 ;  i<5 ; i++){
        c=0;
        int j=i;
        while(j<5){
            if(a[i]<a[j]){
                c++;
                max=a[j];
                j=6;
            }
            else
            j++;
        }
        if(c>0){
            printf("%7d | %d\n",a[i],max);
        }
        else{
            printf("%7d | -1\n",a[i]);
        }
    }
    

    return 0;
}

