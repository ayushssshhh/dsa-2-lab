#include <stdio.h>
#include <stdlib.h>

struct dis{
    int km;
    int m;
};

void add_dis(struct dis *d,int n);

int main(){

    int n;
    printf("\n\nenter total no. of enteries : ");
    scanf("%d",&n);

    struct dis *d=(struct dis*)malloc((n+1)*sizeof(struct dis));

    printf("\n\n--------------------------------enter the %d distances-----------------------------------\n\n",n);
    for(int i=0 ; i<n ; i++){
        printf("enter the dis %d (km mm): ",i+1);
        scanf("%d%d",&(d+i)->km , &(d+i)->m);
    }
    
    add_dis( d , n );

    return 0;
}

void add_dis(struct dis *d,int n){

    (d+n)->km=0 ,(d+n)->m=0;
    for(int i=0 ; i<n ; i++){
        (d+n)->km = (d+i)->km + (d+n)->km ;
        (d+n)->m = (d+i)->m + (d+n)->m ;
    }

    if((d+n)->m > 1000 ){
        (d+n)->km = (d+n)->km + (d+n)->m/1000 ;
        (d+n)->m = (d+n)->m%1000;
    }

    printf("sum of %d dictances = %dkm and %dm", n , (d+n)->km , (d+n)->m);
    
}
