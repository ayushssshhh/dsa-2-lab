#include <stdio.h>
#include<stdlib.h>

struct book{
    char title[25];
    char book_no[10];
    int price;
};

void dispaly(struct book *b , int n);

int main(){

    int n;
    printf("enter the no. of books you want to register : ");
    scanf("%d",&n);
    struct book *p=(struct book*)calloc(n,sizeof(struct book));

    printf("enter the details of %d books : ",n);
    for(int i=0 ; i<n ; i++){
        printf("\nenter the title of the book : ");
        scanf("\n%[^\n]s",&(p+i)->title);
        printf("enter the book no. : ");
        scanf("\n%[^\n]s",&(p+i)->book_no);
        printf("enter the price of the book : ");
        scanf("%d",&(p+i)->price);
    }
    dispaly(p , n);

    return 0;
}

void dispaly(struct book *b , int n){

    int c=0;
    for(int i=0 ; i<n ; i++ ){
        if((((b+i)->price)<(b+i+1)->price)&&((i+1)<n))
        c=i+1;
    }
    printf("the details for the book with th highest price is : ");
    printf("\n title : %s" , (b+c)->title);
    printf("\n book no. : %s" , (b+c)->book_no);
    printf("\n price : $%d" , (b+c)->price);

}

