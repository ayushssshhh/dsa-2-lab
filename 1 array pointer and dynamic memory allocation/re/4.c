#include <stdio.h>

int main(){
    int m , n ;
    printf("\nenter no. of rows and columns respectively : ");
    scanf("%d%d",&m,&n); 
    
    int a[m][n] , r[m] , temp , k , l=1;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%dx%d : ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    
    printf("\n\n-----------------------------------the matrix is : --------------------------------------------------\n");
    for(int i=0;i<m;i++){
        printf("\n");
        for(int j=0;j<n;j++)
        printf(" %2d",a[i][j]);
    }


    for(int i=0 ; i<n/2 ; i++){

        for(int j=0 ; j<m ; j++){ 

            temp=a[j][i];
            a[j][i]=a[j][n-l];
            a[j][n-l]=temp;

        }
        l++;
    }

    printf("\n\n--------------------------the matrix after rearranging coloums is : ---------------------------------\n");
    for(int i=0;i<m;i++){
        printf("\n");
        for(int j=0;j<n;j++)
        printf(" %2d",a[i][j]);
    }

    return 0;
}