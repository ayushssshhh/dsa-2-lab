#include<stdio.h>

int main(){

    int m,n,c;
    printf("enter no. of rows and coloumn : ");
    scanf("%d%d",&m,&n);

    int a[m][n],b[m][n];

    printf("\n\n enter the value in matrinx :\n\n");
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            printf("enter the value of %dx%d : ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    printf("\n\nthe matrix is :\n");


    for(int i=0 ; i<m ; i++){
        printf("\n");
        for(int j=0 ; j<n ; j++)
        printf("%5d",a[i][j]);
    }

    for(int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++)
        b[i][j]=a[i][j];
    }

    int col[m],row[n];

    for(int i=0 ; i<n ; i++){

        for(int j=0 ; j<m ; j++)
        col[j]=a[j][i];

        for(int k=0 ; k<m ; k++){
            for(int j=0 ; j<m ; j++){

                if((col[j]<col[j+1])&&((j+1)<m)){
                    int temp=col[j];
                    col[j]=col[j+1];
                    col[j+1]=temp;
                }
            }
        }

        for(int j=0 ; j<m ; j++)
        a[j][i]=col[j];

    } 

    printf("\n\nthe matrix after sorting the coloumn in descending order is :\n");

    printf("\n");
    for(int i=0 ; i<m ; i++){
        printf("\n");
        for(int j=0 ; j<n ; j++)
        printf("%5d",a[i][j]);
    }

    for(int i=0 ; i<m ; i++){
        
        for(int j=0 ; j<n ; j++)
        row[j]=b[i][j];

        for(int k=0 ; k<n ; k++){
            for(int j=0 ; j<n ; j++){
                if((row[j]>row[j+1])&&((j+1)<n)){
                    int temp=row[j];
                    row[j]=row[j+1];
                    row[j+1]=temp;
                }
            }
        }

        for(int j=0 ; j<n ; j++)
        b[i][j]=row[j];
    }

    printf("\n\nthe matrix after sorting the row in ascending order is :\n");

    printf("\n");
    for(int i=0 ; i<m ; i++){
        printf("\n");
        for(int j=0 ; j<n ; j++)
        printf("%5d",b[i][j]);
    }

    return 0;
}

//3 4 1   56   43   90 32   90   56   42 89   32   70   41