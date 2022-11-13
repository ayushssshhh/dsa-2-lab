#include <stdio.h>

int main (){
    int m , n ,nz=0; 
    int a[m][n];
    
    printf("enter no. of row and col : ");
    scanf("%d%d",&m,&n);

    for(int i=0 ; i<m ; i++ ){
        for(int j=0 ; j<n ; j++){
            printf("enter %dx%d : ",i+1,j+1);
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0)
            nz++;
        }
    }

    printf("\n\n-----the matrix is :----------------\n");
    for(int i=0 ; i<m ; i++ ){
        printf("\n");
        for(int j=0 ; j<n ; j++)
        printf("%d ",a[i][j]);
    }

    int s[nz+1][3];

    s[0][0]=m;
    s[0][1]=n;
    s[0][2]=nz;

    int k=1;
    for(int i=0 ; i<m ; i++ ){
        for(int j=0 ; j<n ; j++){
            if(a[i][j]!=0){
                s[k][0]=i;
                s[k][1]=j;
                s[k++][2]=a[i][j];
            }
        }
    }

    printf("\n\nthe spares matrix is : ");
    for(int i=0 ; i<nz+1 ; i++){
        printf("\n");
        for(int j=0 ; j<3 ;j++)
        printf("%d ",s[i][j]);
    }

    return 0;
}