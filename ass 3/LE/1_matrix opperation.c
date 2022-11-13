#include <stdio.h>

void dis(int* a ,int* b , int m );
void trans(int* a ,int* b , int m);
void add(int* a ,int* b , int m );
void sub(int* a ,int* b , int m );
void mul(int* a ,int* b , int m  );
int dit(int* a , int m  );

int main(){

    int m ;
    printf("enteer no. of row and col : ");
    scanf("%d",&m);
    int n=m;
    int a[m][n] , b[m][n];

    char ch;

    printf("\n\n\tenter the values for matrix 1: \n");
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            printf("enter %dx%d : ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    printf("\n\n\tenter the values for matrix 2: \n");
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<m ; j++){
            printf("enter %dx%d : ",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }

    do{
        printf("\n\n\tchoose any matrix opperation listed below\n\npress 1 for displaying two matrix\npress 2 for displaying transpose two matrix\npress 3 for addition of two matrix\npress 4 for subraction of two matrix\npress 5 for multiplication of two matrix\npress 6 to find detreminant of both matrix\n\nenter your choice :");
        int c;
        scanf("%d",&c);
        switch(c){
            
            case 1 :
            printf("\n\n\t--------------displaying two matrixes-------------------\n");
            dis(*a , *b , m);
            break;

            case 2 :
            printf("\n\n\t--------------transpose of two matrixes-------------------\n");
            dis(*a , *b , m);
            trans(*a , *b , m);
            break;

            case 3 :
            printf("\n\n\t--------- -----addition of two matrixes-------------------\n");
            dis(*a , *b , m);
            add(*a , *b , m);
            break;

            case 4 :
            printf("\n\n\t--------------subraction of two matrixes-------------------\n");
            dis(*a , *b , m);
            sub(*a , *b , m);
            break;

           case 5 :
            printf("\n\n\t--------------multiplication of two matrixes-------------------\n");
            dis(*a , *b , m );
            mul(*a , *b , m );
            break;

            case 6 :
            printf("\n\n\t--------------determinant of two matrixes-------------------\n");
            dis(*a , *b , m);
            printf("\nditerminant of matrix 1 : %d\n",dit(*a , m));
            printf("\nditerminant of matrix 2 : %d\n",dit(*b , m));
            break;


            default :
            printf("\n\n\t--------------------error 404!------------------\nplease enter any valid opperation listed above");
            break;

            
        }

        printf("\n\n\tdo you want to continue ?(press Y to continue and N to exit)\nenter your choice : ");
        scanf(" %c",&ch);
    }while((ch=='y')||(ch=='Y'));
    return 0;
}

void dis(int* a ,int* b , int m){
    int n=m ;
    printf("\nmarix 1 :\n");
    for(int i=0 ; i<m ; i++){
        printf("\n");
        for(int j=0 ; j<n ; j++)
        printf("%3d ",*((a+i*n) + j));
    }

    printf("\nmarix 2 :\n");
    for(int i=0 ; i<m ; i++){
        printf("\n");
        for(int j=0 ; j<n ; j++)
        printf("%3d ",*((b+i*n) + j));;
    }
}

void trans(int *a ,int *b ,int m){
    int n=m ;
    printf("trasnpose of matrix 1 is :\n");
    for(int i=0 ; i<n ; i++){
        printf("\n");
        for(int j=0 ; j<m ; j++)
        printf("%3d ",*((a+j*n)+i));
    }

    printf("trasnpose of matrix 2 is :\n");
    for(int i=0 ; i<n ; i++){
        printf("\n");
        for(int j=0 ; j<m ; j++)
        printf("%3d ",*((b+j*n)+i));
    }
}

void add(int *a ,int *b ,int m){
    int n=m ;
    printf("\nthe sum of two matrixes are : ");
    int c[m][n];
    for(int i=0 ; i<m ;i++){
        for(int j=0 ; j<n ; j++)
        c[i][j] = *((a+i*n)+j) + *((b+i*n)+j);
    }

    for(int i=0 ; i<m ;i++){
        printf("\n");
        for(int j=0 ; j<n ; j++)
        printf("%3d ",c[i][j]);
    }
}

void sub(int *a ,int *b ,int m){
    int n=m ;
    printf("\nthe subraction of two matrixes are : ");
    int c[m][n];
    for(int i=0 ; i<m ;i++){
        for(int j=0 ; j<n ; j++)
        c[i][j] = *((a+i*n)+j) - *((b+i*n)+j);
    }

    for(int i=0 ; i<m ;i++){
        printf("\n");
        for(int j=0 ; j<n ; j++)
        printf("%3d ",c[i][j]);
    }
}


void mul(int *a ,int *b ,int m){

    int p[m][m] , sum , k; 

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<m ; j++){
            sum=0;
            for(k=0 ; k<m ; k++)
            sum += *((a+i*m)+k) * *((b+k*m)+j);
            p[i][j] = sum;
        }
    }

    printf("the multiplication of two matrix is :\n");
    for(int i=0 ; i<m ; i++){
        printf("\n");
        for(int j=0 ; j<m ; j++)
        printf("%3d ",p[i][j]);
    }
}

int dit(int *a , int m){
    int s=1 , b[m-1][m-1] , n , d , l;

    if(m==1)
    return (*a);

    else{
        d=0;
        for(int c=0 ; c<m ; c++){
            n=0 , l=0;
            for(int i=0 ; i<m ; i++){
                for(int j=0 ; j<m ; j++){

                    if((i!=0)&&(j!=c)){

                        b[n][l] = *((a + i*m) + j);

                        if(l<(m-2))
                        l++;

                        else{
                            l=0;
                            n++;
                        }
                    }
                }
            }
            d += s * (*(a+c) * dit(*b , m-1)); 
            s *= -1;
        }    
    }
    return d;
}
//3 4 1 2 3 4 5 6 7 8 9 10 11 0 13 12 11 10 9 8 7 6 5 4 3 2

//3 7 7 1 7 7 8 9 2 3 9 9 5 5 9 2 2 0 8