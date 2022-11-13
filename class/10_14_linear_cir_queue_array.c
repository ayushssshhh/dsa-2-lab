#include <stdio.h>

#define max 5
int q[max];

int l = -1;
int r = -1;

void enqueue(int v){
    if(l == -1){
        l = r = 0;
        q[r] = v;
        return;
    }

    else if(l == ((r+1)%max)){
        printf("\n\noverflow");
        return;
    }

    else{
        r = (r+1)%max;
        q[r] = v;
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
        return;
    }

    else{
        l = (l+1)%max;
    }   

}

void isEmp(){

}

void dis(){

}

void peak(){

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