#include <stdio.h>

int main(){
    int m1 , m2 , n1 , n2;
    printf("\nenter dim of mat 1 : ");
    scanf("%d%d",&m1 , &n1);

    printf("\nenter dim of mat 2 : ");
    scanf("%d%d",&m2 , &n2);

    int a[m1][n1] , b[m2][n2];

    printf("\nenter value of mat 1 : ");
    for(int i = 0 ; i< m1 ; i++){
        for(int j = 0 ; j< n1 ; j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nenter value of mat 2 : ");
    for(int i = 0 ; i< m2 ; i++){
        for(int j = 0 ; j< n2 ; j++){
            scanf("%d",&b[i][j]);
        }
    }

    if(n1 == m2){
        int c[m1][n2];

        for(int i=0 ; i<m1 ; i++){
            for(int j=0 ; j<n2 ; j++){
                int sum = 0;
                for(int k=0 ; k<)
            }
        }
    }
}