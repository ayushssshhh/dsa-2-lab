#include<stdio.h>
struct time
{
    int hours;
    int minutes;
    int seconds;
};
int main()
{
    struct time t[2];
    int i,h=0,m=0,s=0;
    printf("enter the time in 24 hour format:\n");
    for(i=0;i<2;i++)
    {
        printf("enter the hour:\n");
        scanf("%d",&t[i].hours);
        printf("enter the minutes:\n");
        scanf("%d",&t[i].minutes);
        printf("enter the seconds\n");
        scanf("%d",&t[i].seconds);
    }
    if(t[0].hours>t[1].hours)
    {
        h=t[0].hours-t[1].hours;
    }
    else{
        h=t[1].hours-t[0].hours;
    }
    if(t[0].minutes>t[1].minutes)
    {
        m=t[0].minutes-t[1].minutes;
    }
    else{
        m=t[1].minutes-t[0].minutes;
    }
    if(t[0].seconds>t[1].seconds){
        s=t[0].seconds-t[1].seconds;
    }
    else{
        s=t[1].seconds>t[0].seconds;
    }
    printf("the difference in the two times are:\n");
    printf("%d hours : %d minutes : %d seconds",h,m,s);
    return 0;
}