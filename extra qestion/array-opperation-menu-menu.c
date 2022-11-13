#include <stdio.h>

int insert(int *a , int n);
int delete(int *a , int n);
int* rev(int *a , int n);
void search(int *a , int n);
void display(int *a , int n);

int main (){

    int arr[1000] , n , choice ;
    char ch; 
    printf("enter no. of element : ");
    scanf("%d",&n);
    
    printf("enter %d values in the array : ",n);
    for(int i=0 ; i<n ; i++)
    scanf("%d",&arr[i]);

    int *a = &arr[0];

    do{

        printf("\n\n------------choose the following array operation---------------\n\n\tpress 1 for  inserting an element\n\tpress 2 for deleting an element\n\tpress 3 for reversing an element\n\tprees 4 for searching an element\n\tpress 5 for displaying an array\n\n\tenter your choice : ");
        scanf("%d",&choice) ;

        switch (choice)
        {
        case 1: 
            n = insert(a , n);
            break;

        case 2 :
            n = delete(a , n);
            break;

        case 3:
            a = rev(a , n);
            break;

        case 4:
            search(a , n);
            break;

        case 5 : 
            display(a , n);
            break;
        
        default:
            printf("------------------------invalid input(try again)----------------------------");
            break;
        }

        printf("\n\n----------------DO YOU WANT TO CONTINUE ?----------------------\npress Y to continue elese press N to exit : ");
        scanf(" %c",&ch);
    }while((ch=='y')||ch=='Y');

    return 0;
}

int insert(int *a , int n){

    int pos , val , temp;
    printf("\n\n------------------------------inserting an element in an arry----------------------\n\nenter the position and value of the  the new element : ");
    scanf("%d%d",&pos,&val);

    for(int i=pos-1 ; i<n+1 ; i++){
       
        temp = a[i];
        a[i]=val;
        val=temp;      

    }

    return (n+1);
}

int delete(int *a , int n){

    int pos ; 
    printf("enter the pos of an element which you want to delete : ");
    scanf("%d",&pos);

    for(int i=pos-1 ; i<n ; i++)
    a[i]=a[i+1];

    return (n-1);
}

int* rev(int *a ,int n){
    static int b[1000];
    for(int i=0 ; i<n ; i++)
    b[i]=a[n-1-i];

    return (&b[0]);
}

void search(int *a , int n){

    int s , c=0 ;
    printf("\tenter the value to be searched");
    scanf("%d",&s);

    for(int i=0 ; i<n ; i++){

        if(a[i]==s)
        c++;

    }

    if(c>0)
    printf("\n\n------------------found-----------------------\n\n%d is found in the array for %d times",s,c);

    else
    printf("\n\n------------------found-----------------------\n\n%d is not found in the array",s);
}

void display(int *a , int n){

    printf("\n\n----------------the array is--------------------\n\n");
    for(int i=0 ; i<n ; i++)
    printf("%d ",a[i]);

} 