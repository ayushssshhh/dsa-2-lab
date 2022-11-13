#include <stdio.h>

int main()
{
    int n;
    printf("enter the value of n : ");
    scanf("%d",&n);
    
    int a[n][n],i,j,c=0,ls=0,lsd=0;
    
    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n ; j++){
           printf("enter %dx%d : ",i+1,j+1);
           scanf("%d",&a[i][j]);
        }
    }
    
    printf("\n\nthe matrix is :\n");
    
    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n ; j++){
            printf("%3d",a[i][j]);
            if(a[i][j]!=0)
            c++;
        }
        printf("\n");
    }
    
    printf("\n\ntotal no. of nonzero element : %d\n\n",c);
    
    for(i=0 ; i<n ; i++){
        for(j=i+1 ; j<n ; j++){
            ls=ls+a[i][j];
        }
    }
    printf("the sum of element above leading diagonal : %d\n\n",ls);
    
    for(i=0 ; i<n ; i++){
        for(j=0 ; j<i ; j++){
            lsd=lsd+a[i][j];
        }
    }
    printf("the sum of element below leading diagonal : %d",lsd);
 
    return 0;
}
