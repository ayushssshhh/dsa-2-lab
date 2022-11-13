#include <stdio.h>

int main (){

    int m1 , n1 , m2 , n2;
    printf("enter row and col of matrix 1 :");
    scanf("%d%d",&m1,&n1);

    printf("enter row and col of matrix 2 :");
    scanf("%d%d",&m2,&n2);

    int a[m1][n1] , b[m2][n2];

    printf("enter 1st matrix : ");
    for(int i=0 ; i<m1 ; i++){
        for(int j=0 ; j<n1 ; j++)
        scanf("%d",&a[i][j]);
    }

    printf("enter 2nd matrix : \n");
    for(int i=0 ; i<m2 ; i++){
        for(int j=0 ; j<n2 ; j++)
        scanf("%d",&b[i][j]);
    }

    printf("\nmatrix 1 is:\n");
    for(int i=0 ; i<m1 ; i++){
        printf("\n");
        for(int j=0 ; j<n1 ; j++)
        printf("%3d ",a[i][j]);
    }

    printf("\nmatrix 2 is:\n");
    for(int i=0 ; i<m2 ; i++){
        printf("\n");
        for(int j=0 ; j<n2 ; j++)
        printf("%3d ",b[i][j]);
    }

    if(n1==m2){
        int p[m1][n2];

        for(int i=0 ; i<m1 ; i++){
            for(int j=0 ; j<n2 ; j++){
                
                int s=0;
                for(int k=0 ; k<n1 ; k++)
                s += a[i][k] * b[k][j];

                p[i][j] = s;
            }
        }

        printf("\nproduct matrix is :");
        for(int i=0 ; i<m1 ; i++){
            printf("\n");
            for(int j=0 ; j<n2 ; j++)
            printf("%3d ",p[i][j] );
        }     
    }

    else
    printf("cant perform mutliplicatio operation of above printed matrix, since n1!=m2");

    return 0;

}