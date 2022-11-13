#include <stdio.h>

#define max 5
int q[max];

int l = -1;
int r = -1;
int n = 0;

void enqueue(int v){
    if(l == -1){
        l = r = 0;
        q[r] = v;
        n++;
        return;
    }

    else if(l == ((r+1)%max)){
        printf("\n\noverflow");
        return;
    }

    else{
        r = (r+1)%max;
        q[r] = v;
        n++;
        return;
    }
}

void dequeue(){
    if(l == -1){
        printf("\n\nunderflow");
        return;
    }

    else if(l == r){
        printf("\n\n%dis poped out from queue",q[l]);
        l = r = -1;
        n--;
        return;
    }

    else{
        printf("\n\n%dis poped out from queue",q[l]);
        l = (l+1)%max;
        n--;
        return;
    }   

}

void isEmp(){
    if(l == -1){
        printf("\n\nthe queue is empty");
        return;
    }

    printf("\n\nthe queue is not empty");
}

void dis(){
    int front = l;

    printf("\n\nelement stored in queue are : ");
    for(int i=0 ; i<n ; i++){
        printf("%d ",q[front]);
        front = (front+1)%max;
    }

}

void peak(){
    printf("\n\npeak element is  : %d" , q[l]);
}

int main(){
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
                enqueue(v);
                break;

            case 2 : 
                dequeue();
                break;

            case 3 :
                isEmp();
                break;

            case 4 : 
                peak();
                break;

            case 5 : 
                dis();
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