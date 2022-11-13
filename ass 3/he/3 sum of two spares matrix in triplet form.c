#include <stdio.h>

int main(){
    int nz1 , nz2 , i , j , k ;
    printf("enter no. of non-zero element in matrix 1 and 2 respectively : ");
    scanf("%d%d",&nz1,&nz2);
    
    int a[nz1+1][3] , b[nz2+1][3] , c[nz1+nz2+1][3];

    printf("enter row and col of matrixes respectively : ");
    scanf("%d%d",&a[0][0],&a[0][1]);
    a[0][2] = nz1;
    b[0][0] = c[0][0] = a[0][0];
    b[0][1] = c[0][1] = a[0][1];
    b[0][2] = nz2;

    printf("\n\n-------------------enter the triplet form of matrix 1----------------\n\n");
    for(i=1 ; i<nz1+1 ; i++){
        for(j=0 ; j<3 ; j++){
            printf("enter the detail of non zero element %d : ",i);
            scanf("%d",&a[i][j]);
        }
    }

    printf("\n\n-------------------enter the triplet form of matrix 2----------------\n\n");
    for(i=1 ; i<nz2+1 ; i++){
        for(j=0 ; j<3 ; j++){
            printf("enter the detail of non zero element %d : ",i);
            scanf("%d",&b[i][j]);
        }
    }

    printf("\n\n--------------triplet form--------------\n\n");
    
    printf("\n\nmatrrix 1 : \n");
    for(i=0 ; i<nz1+1 ; i++){
        printf("\n");
        for(j=0 ; j<3 ; j++)
        printf("%3d ", a[i][j]);
    }

    printf("\n\nmatrrix 2 : \n");
    for(i=0 ; i<nz2+1 ; i++){
        printf("\n");
        for(j=0 ; j<3 ; j++)
        printf("%3d ", b[i][j]);
    }

    i=1 , k=1 , j=1;
    
    while ((i <= nz1) && (j <=nz2)) {

        if(a[i][0] == b[j][0]){

            if(a[i][1] == b[j][1]){
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k++][2] = a[i++][2] + b[j++][2];
            }

            else if(a[i][1] < b[j][1]){
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k++][2] = a[i++][2];
            }

            else{
                c[k][0] = b[j][0];
                c[k][1] = b[j][1];
                c[k++][2] = b[j++][2];
            }
        }

        else if (a[i][0] < b[j][0]){
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k++][2] = a[i++][2];
        }

        else{
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k++][2] = b[j++][2];
        }
    }

    while(i <= nz1){
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k++][2] = a[i++][2];
    }

    while(j <= nz2){
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k++][2] = b[j++][2];
    }

    c[0][2] = k-1;

    printf("\n\nsum matrrix : \n");
    for(i=0 ; i<k ; i++){
        printf("\n");
        for(j=0 ; j<3 ; j++)
        printf("%3d ", c[i][j]);
    }
    return 0;
}
