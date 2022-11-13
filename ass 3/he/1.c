#include <stdio.h>

int main(){
    int m , c=0 , l=0;
    printf("enter the order of matrix : ");
    scanf("%d",&m);

    int a[m][m];

    printf("\n\nenter %d value for the matrix : ",m*m);
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<m ; j++)
        scanf("%d",&a[i][j]);
    }

    printf("\n\nthe matrix is : \n");
    for(int i=0 ; i<m ; i++){
        printf("\n");
        for(int j=0 ; j<m ; j++)
        printf("%3d",a[i][j]);
     }

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<i ; j++){
            if(a[i][j]!=0){
                c++;
                goto out1;
            }
        }
    }

    out1 : 

    for(int i=0 ; i<m ; i++){
        for(int j=i+1 ; j<m ; j++){
            if(a[i][j]!=0){
                l++;
                goto out2;
            }
            
        }
    }
    
    out2 : 

    if(l==0)
    printf("\nmatrix is an lower triangle matrix");

    else if(c==0)
    printf("\nmatrix is a uper triangular matrix");

    return 0;
}