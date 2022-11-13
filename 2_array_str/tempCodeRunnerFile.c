#include <stdio.h>

struct time{
    int h;
    int m;
    int s;
};

int main(){

    int t1 ;

    struct time t[3];
    for(int i=0 ; i<2 ; i++){
        printf("enter time (hh:mm:ss:) - ");
        scanf("%d %d %d",&t[i].h,&t[i].m,&t[i].s);
    }
    
    t1=t[0].h*3600+t[0].m*60+t[0].s-(t[1].h*3600+t[1].m*60+t[1].s);

    printf("\n%d\n",t1);

    t[2].h=t1/3600;
    t[2].m=t1%3600/60;
    t[2].s=t1%60;

    printf("%d : %d : %d ", t[2].h , t[2].m , t[2].s );


    printf("time 1 is - %d : %d : %d\n",t[0].h,t[0].m,t[0].s);
    printf("time 2 is - %d : %d : %d\n",t[1].h,t[1].m,t[1].s);
    printf("time diff is - %d : %d : %d\n",t[3].h,t[3].m,t[3].s);

    return 0;
}//1 0 30 1 2 30