#include <stdio.h>
#include <stdlib.h>

struct poly{
    int n;
    int l[100];
};

void createPoly(struct poly *p);
void displayPoly(struct poly *p);
void sumPoly(struct poly *p);

int main(){
    
    struct poly *p = (struct poly*)calloc(2,sizeof(struct poly));

    int c , k=0 ;
    char ch;
    do{
        printf("\n\n--------------------------Polynomial operation----------------------\n\npress 1 to enter your polynomail\npress 2 to display your polynomial\npress 3 for sum\n\n\tenter your choice : ");
        scanf("%d",&c);

        switch(c){

            case 1 : 
                printf("\n\n---------------------------inputing polynomial--------------------------\n\n");
                k++;
                createPoly(p);
                break;

            case 2 : 

                if(k==0){
                    printf("--------------------- ERROR 404 ! --------------------------\nPlease 1st create your polynomial expression");
                    break;
                }

                else{
                    printf("\n\n---------------------------displaying polynomial--------------------------\n\n");
                    displayPoly(p);
                    break;
                }
                
            case 3 : 

                if(k==0){
                    printf("--------------------- ERROR 404 ! --------------------------\nPlease first create your polynomial expression");
                    break;
                }

                else{
                    printf("\n\n---------------------------adding polynomial--------------------------\n\n");
                    sumPoly(p);
                    break;
                }
        
        }             

        printf("\n\n______________________________________________________________\n\ndo you want to continue?\n\npress Y/y to continue , press any other key to exit : ");
        scanf(" %c",&ch);
    }while((ch=='y')||(ch=='Y'));
   
    
    return 0;
}

void createPoly(struct poly *p){
    
    for(int i=0 ; i<2 ; i++){
        printf("\n\nenter the rank of your polynomial %d : ",i+1);
        scanf("%d",&(p+i)->n);
        int size = (p+i)->n + 1;
        printf("enter your polynomial %d : ",i+1);
        for(int j=0 ; j<size ; j++)
        scanf("%d",&(p+i)->l[j]);
    }
}

void displayPoly(struct poly *p){

    for(int i=0 ; i<2 ; i++){
        printf("\npolynomial %d is : ", i+1);
        int size = (p+i)->n + 1;
        for(int j=0 ; j<size ; j++)
        printf("+ %dx^%d ", (p+i)->l[j] , size-j-1);
    }
}

void sumPoly(struct poly *p){

    int m1 = p->n+1 , m2 = (p+1)->n + 1;
    printf("\nthe sum of polynomial 1 and polynomial 2 is : ");

    if(m1 > m2){

        int c[m1];

        for(int i=0 ; i<m1 ; i++)
        c[i] = p->l[i];

        for(int i=m1-m2 ; i<m1 ; i++)
        c[i] += (p+1)->l[i-m1+m2];

        for(int i=0 ; i<m1 ; i++)
        printf("+ %dx^%d ", c[i] , m1-i-1);   

    }

    else{
        int c[m2];

        for(int i=0 ; i<m2 ; i++)
        c[i] = (p+1)->l[i];

        for(int i=-m1+m2 ; i<m2 ; i++)
        c[i] += p->l[i+m1-m2];

        for(int i=0 ; i<m2 ; i++)
        printf("+ %dx^%d ", c[i] , m2-i-1);  
    }
}