#include <stdio.h>

int max , l = -1 , r = -1;

void enqueue(int *q , int v){
    if(r >= max){
        printf("\n\noverflow");
        return;
    }

    else if(l == -1){
        l++;
        r++;
        *(q+r) = v;
        return;
    }

    else{
        r++;
        *(q+r) = v;
        return;
    }
}

void dequeue(int *q){
    if((l == -1)){
        printf("\n\nunderflow");
        return;
    }

    else if (l == r){
        printf("\n\n%d is poped out from the queue",*(q+l));
        l = r = -1;
        return;
    }
    

    else{
        printf("\n\n%d is poped out from the queue",*(q+l));
        l++;
        return;
    }
}

void peak(int *q){
    printf("\n\n %d is peak elememt",*(q+l));
}

void check(int *q){
    if(l == -1){
        printf("\n\nthe queue is empty");
    }

    else{
        printf("\n\n the queue is not empty");
    }
}

void dis(int *q){
    if(l == -1){
        printf("\n\nthe queue is empty");
    }

    else{
        printf("\n\nelement in the is : ");
        for(int i=l ; i<=r ; i++){
            printf("%d ",*(q+i));
        }
    }
}

int main(){
    printf("enter total no. of element in the queue : ");
    scanf("%d",&max);

    int queue[max];
    int *q = &queue[0];

    char ch;
    int c , v;

    do
    {
        printf("\n\npress 1 to enqueue\npress 2 to dequeue\npress 3 to check\npress 4 to get the peak elemet\npress 5 to print the element of the queue\nenter your choice : ");
        scanf("%d",&c);

        switch (c)
        {
            case 1 :
                printf("enter the value to push in queue : ");
                scanf("%d",&v);
                enqueue(q,v);
                break;

            case 2 : 
                dequeue(q);
                break;

            case 3 :
                check(q);
                break;

            case 4 : 
                peak(q);
                break;

            case 5 : 
                dis(q);
                break;

            default : 
                printf("\n\nplease enter an valid option");
                break;
        }
        printf("\n\nDo you want to continue??\n(press y or Y to continue)\nenter your choice : ");
        scanf(" %c",&ch);

    }while ((ch == 'y') || (ch == 'Y'));
    
    return 0;
}