#include<stdio.h>
#include<stdlib.h>

int main(){
    
    int n , k , min , max , min2 , max2;
    printf("enter the no. of elemnt : ");
    scanf("%d",&n);

    int *a=(int *)calloc(n,sizeof(int));

    printf("enter %d values which is to be stored in arra : ",n);
    for(int i=0 ; i<n ; i++)
    scanf("%d",&a[i]);


    for(int i=0 ; i<n ; i++){
        if(max<a[i])
        max=a[i];
        if(min>a[i])
        min=a[i];
    } 

    printf("\n\nenter value of kth : ");
    scanf("%d",&k);

    int a_min[k-1] , a_max[k-1] , n_min=0 , n_max=0;
    max=min=a[0] , min2 , max2;
    
    if(k==1){
        printf("\n\n the 1st greatest and the 1st smallest no. in array is : %d %d respectively",max,min);
    }

    else{
        for(int j=0 ; j<k-1 ; j++){
            
            min2=max , max2=min , a_max[n_max++]=max , a_min[n_min++]=min ;
            for(int i=0 ; i<n ; i++){
        
                if((max2<a[i])&&(a[i]!=max)){
                    for(int l=0 ; l<n_max ; l++){
                        if(a[i]!=a_max[l])
                        max2=a[i];
                    }
                }

                if((min!=a[i])&&(min2>a[i]))
                min2=a[i];
            }
            max=max2,min=min2;
        }
        printf("the %dth greatest and %dth smallest no. is : %d and %d repesctively",k,k,max2,min2);
    }

    return 0;
}
//10 12 34 87 09 12 65 56 83 41 10
