#include <stdio.h>
#include <stdlib.h>

struct emp{
    int id;
    char name[25];
    char des[10];
    int sal;
};

int main(){

    int n , a[n], k , c;
    printf("enter no. of employee's data you want to enter : ");
    scanf("%d",&n);

    struct emp *e = (struct emp*)calloc(n,sizeof(struct emp));
    
    printf("\n\n------------------------enter details of the employes-----------------------------------");
    for(int i=0 ; i<n ; i++ ){
        printf("\n\nEmpolye no. %d:\nenter name :",i+1);
        scanf("\n%[^\n]s",(e+i)->name);f
        printf("enter id : ");
        scanf("%d",&(e+i)->id);
        printf("enter designation :");
        scanf("\n%[^\n]s",(e+i)->des);
        printf("enter salary : $");
        scanf("%d",&(e+i)->sal);
        a[i]=(e+i)->sal;        
    }    

    printf("\nenter the salary postion you want display : ");
    scanf("%d",&k);

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(a[i]<a[i+1]){
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }

    for(int i=0 ; i<n ; i++){
        if((e+i)->sal==a[k])
        c=i;
    }

    printf("\n\n-----employee detail with salary postion %d-----------\n\n",k);
    printf("Name : %s\nId : %d\nDesignation : %s\nSalary : $%d",(e+c)->name,(e+c)->id,(e+c)->des,(e+c)->sal);

    return 0;
}