#include <stdio.h>

int main(){
    int n , m , nz=0 , k=1;
    printf("enter no. of row row and col : ");
    scanf("%d%d",&m,&n);

    int a[m][n];
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            printf("%dx%d : ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    printf("\n\n---------------------------the matrix is-----------------------------\n");
    for(int i=0 ; i<m ; i++){
        printf("\n");
        for(int j=0 ; j<n ; j++){
            printf("%3d ",a[i][j]);
            if(a[i][j]!=0)
            nz++;
        }
    }

    printf("\n-----------------------------------------------------------------------\ntotal no. of non-zero element are : %d",nz);

    printf("\n\n---------------------------the spares matrix is-----------------------------\n");
    int b[nz+1][3];

    b[0][0] = m , b[0][1] = n , b[0][2] = nz;
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(a[i][j]!=0){
                b[k][0] = i;
                b[k][1] = j;
                b[k++][2] = a[i][j];
            }
        }
    }

    for(int i=0 ; i<nz+1 ; i++){
        printf("\n");
        for(int j=0 ; j<3 ; j++)
        printf("%d ",b[i][j]);
    }

    printf("\n\n---------------------------the transpose of the spares matrix is-----------------------------\n");
    for(int i=0 ; i<3 ; i++){
        printf("\n");
        for(int j=0 ; j<nz+1 ; j++)
        printf("%d ",b[j][i]);
    }


    return 0;
}

//3 4 3 0 0 0 0 8 9 0 0 4 0 1