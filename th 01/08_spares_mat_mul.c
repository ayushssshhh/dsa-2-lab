//-----------algo--------------------------
//agr triplet 1 ka col aur triplet 2 ka row same hoga toh element [i][2] location mul hoke store hojayega 
//1 ka row 3 ka row hoga aur 2 ka col  3 ka col hoga
//last mai 3 p same row aur col wale element ko add krdege
//3 ko sort krdege

#include <stdio.h>

int main (){

    int m1 , n1 , m2 , n2 , nz1 , nz2 , k=1;
    printf("\n\nenter order and no. of non-zero element of matrix 1 : ");
    scanf("%d%d%d",&m1,&n1,&nz1);
    printf("\n\nenter order of matrix 2 : ");
    scanf("%d%d%d",&m2,&n2,&nz2);

    int a[nz1+1][3] , b[nz2+1][3];

    a[0][0] = m1 , a[0][1] = n1 , a[0][2] = nz1 , b[0][0] = m2 , b[0][1] = n2 , b[0][2] = nz2;

    printf("\n\n-------------------enter the triplet form---------------------");

    printf("\n\nmatrix 1 : \n");
    for(int i=1 ; i<=nz1 ; i++){
        printf("enter the detail for %d non-zero elemet : ",i);
        for(int j=0 ; j<3 ; j++)
        scanf("%d",&a[i][j]);
    }

    printf("\n\nmatrix 2 : \n");
    for(int i=1 ; i<=nz2 ; i++){
        printf("enter the detail for %d non-zero elemet : ",i);
        for(int j=0 ; j<3 ; j++)
        scanf("%d",&b[i][j]);
    }

    printf("\n\n-------------------the triplet form---------------------");

    printf("\n\nmatrix 1 : \n");
    for(int i=0 ; i<=nz1 ; i++){
        printf("\n");
        for(int j=0 ; j<3 ; j++)
        printf("%3d ",a[i][j]);
    }

    printf("\n\nmatrix 2 : \n");
    for(int i=0 ; i<=nz2 ; i++){
        printf("\n");
        for(int j=0 ; j<3 ; j++)
        printf("%3d ",b[i][j]);
    }
    
    int c[m1+m2+1][3];                                              
    c[0][0] = a[0][0];
    c[0][1] = b[0][1];

    for(int i=1 ; i<=nz1 ; i++){
        for(int j=1; j<=nz2 ; j++){
            if(a[i][1] == b[j][0] ){            //for working with transpose b[0][1]
                c[k][0] = a[i][0];
                c[k][1] = b[j][1];              //for working with transpose b[0][0]
                c[k++][2] = a[i][2]*b[j][2];                 
            }
        }
    }

    //sorting product array
    for(int j=1 ; j<k ; j++){  
        for(int i=1 ; i<k-1 ; i++){

            if((c[i][1] > c[i+1][1]) && (c[i][0] == c[i+1][0])){

                for(int j=0 ; j<3 ; j++){
                    int temp = c[i][j];
                    c[i][j] = c[i+1][j];
                    c[i+1][j] = temp;
                }
            }
        }
    }
    // adding multiple entry of same elemement
    int i=1;
    while(i<k){
        int j = i+1;
        while(j<k){
            if((c[i][0] == c[j][0]) && (c[i][1] == c[j][1])){
                c[i][2] += c[j][2];
                for(int l=j ; l<k ; l++){
                    c[l][0] = c[l+1][0];
                    c[l][1] = c[l+1][1];
                    c[l][2] = c[l+1][2];
                }
                k--;
            }
            j++;            
        }
        i++;
    }

    c[0][2] = k-1;
    printf("\n\ntriplet form product matrix :\n");
    for(int i=0 ; i<k ; i++){
        printf("\n");
        for(int j=0 ; j<3 ; j++)
        printf("%3d ",c[i][j]);
    }
     

    return 0;
}

//4 4 6 4 4 6 1 2 10 1 3 4 1 4 2 3 3 3 4 1 4 4 2 2 1 3 8 2 4 3 3 2 2 3 3 9 4 1 2 4 2 7 