#include <stdio.h>

int* createPoly();
void displayPoly(int *s);
void sumPoly(int* s);

int main(){
    
    int c ;
    int* p = 0 ;
    char ch;
    do{
        printf("\n\n--------------------------Polynomial operation----------------------\n\npress 1 to enter your polynomail\npress 2 to display your polynomial\npress 3 for sum\n\n\tenter your choice : ");
        scanf("%d",&c);

        switch(c){

            case 1 : 
                p = createPoly();
                break;

            case 2 : 

                if(p==0){
                    printf("--------------------- ERROR 404 ! --------------------------\nPlease 1st create your polynomial expression");
                    break;
                }

                else{
                    displayPoly(p);
                    break;
                }
                
            case 3 : 

                if(p==0){
                    printf("--------------------- ERROR 404 ! --------------------------\nPlease 1st create your polynomial expression");
                    break;
                }

                else{
                    sumPoly(p);
                    break;
                }
        
        }             

        printf("\n\n______________________________________________________________\n\ndo you want to continue?\n\npress Y/y to continue , press any other key to exit : ");
        scanf(" %c",&ch);
    }while((ch=='y')||(ch=='Y'));
   
    
    return 0;
}

int* createPoly(){

    int n , i=0;
    printf("\n\n---------------creating a polynomial-------------\n\nenter the rank of your 1st polynomial : ");
    scanf("%d",&n);
    
    static int p[100];
    p[0]=n;
    printf("enter your coff of polynomial (ax^n + bx^n-1 + ......) : ");
    for(i=1 ; i<=n+1 ; i++)
    scanf("%d",&p[i]);

    printf("\n\nenter the rank of your 2nd polynomial : ");
    scanf("%d",&n);

    p[i++]=n;
    printf("enter your coff of polynomial (ax^n + bx^n-1 + ......) : ");
    for(int j=i; j<=i+n ; j++)
    scanf("%d",&p[j]);

    return (p);
}


void displayPoly(int* s){

    printf("\n\n---------------------displaying polynomial-------------------\nyour 1st polynomial is : ");
    
    int i=1 , k = *s , l=1;
    for(i ; i<k+2 ; i++)
        printf("%dy^%d + ", *(s+i) , k-i+1 );

    k = *(s+i);
    printf("\nyour 2nd polynomial is : ");
    for(int j=i+1 ; j<i+k+2 ; j++)
        printf("%dy^%d + ", *(s+j) , k+1-l++ );

}

void sumPoly(int* s){

    int n1 = *s+1 , n2 = *(s+n1+1)+1;

    if(n1>n2){

        int c[n1];

        for(int i=0 ; i<n1 ; i++)
        c[i] = *(s+i+1);

        for(int i=0 ; i<)

        for(int i=0 ; i<n1 ; i++)
        printf(" %d",c[i]);

    }

}
//1 2 2 5 3 4 8 9 2 3 1 y 2 y 3 
//1 4 8 9 2 3 1 1 6 7 y 2 y 3
//1 4 8 9 2 3 1 2 2 5 3 y 2 y 3
//1 4 8 9 2 3 1 3 7 7 1 7 y 2 y 3 
//1 3 7 7 1 7 4 8 9 2 3 1 y 2 y 3

/*if(n1>n2){
        int c[n1];
        for(int i=1 ; i<=n1+1 ; i++)
            c[j++] = *(s+i);

        j--;
        for(int i=n1+n2+3 ; i>n1+2 ; i--)
            c[j] = c[j--] + *(s+i);

        for(int i=0 ; i<=n1 ; i++)
            printf("%d " , c[i]);
            
    }

    if(n1<n2){
        int c[n2];
        for(int i=1 ; i<=n2+1 ; i++){
            c[j] = *(s+n1+1+i);
            j++;
        }
        for(int i=0 ; i<=n2 ; i++)
            printf("%d " , c[i]);
            
    }*/