#include <stdio.h>

int* createPoly();
void displayPoly(int *s);

int main(){
    
    int c ;
    int* p = 0 ;
    char ch;
    do{
        printf("--------------------------Polynomial operation----------------------\n\npress 1 to enter your polynomail\npress 2 to display your polynomial\n\n\tenter your choice : ");
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
        }

        printf("\n\n______________________________________________________________\n\ndo you want to continue?\n\npress Y/y to continue , press any other key to exit : ");
        scanf(" %c",&ch);
    }while((ch=='y')||(ch=='Y'));
   
    
    return 0;
}

int* createPoly(){

    int n;
    printf("\n\n---------------creating a polynomial-------------\n\nenter the rank of your polynomial : ");
    scanf("%d",&n);
    
    static int p[100];
    p[0]=n;
    printf("enter your coff of polynomial (ax^n + bx^n-1 + ......) : ");
    for(int i=1 ; i<=n+1 ; i++)
    scanf("%d",&p[i]);

    return (p);
}


void displayPoly(int* s){

    int k=*s;
    printf("\n\n---------------------displaying polynomial-------------------\nyour polynomial is : ");
    
    for(int i=1 ; i<k+2; i++)
        printf("%d*y^%d + ",*(s+i),k-i+1);
}

//2 3 4 5 6 7