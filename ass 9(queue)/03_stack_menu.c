#include <stdio.h>
int n_stack;
int ele = 0;

void push(int *s , int v){
    if(ele == n_stack){
        printf("\n\noverflow\n");
        return;
    }

    else{
        *(s+ele) = v;
        ele++;
    }
}

void pop(int *s){
    if(ele == 0){
        printf("\n\nuderflow");
        return;
    }

    else{
        printf("\n\n%d is poped out from the stack\n",*(s+ele-1));
        ele--;
    }
}

void is_empty(int *s){
    if(ele == 0)
    printf("\n\nthe stack is empty\n");

    else
    printf("\n\nthe stack is not empty\n");
}

void dis(int *s){
    if(ele == 0)
    printf("\n\nthe stack is empty\n");

    else{
        printf("\n\nthe element in stack are : ");
        for(int i=ele-1 ; i>=0 ; i--){
            printf("%d ",*(s+i));
        }
    }

    printf("\n");
}

int main(){
    printf("enter total no. of element in your stack : ");
    scanf("%d",&n_stack);

    int stack[n_stack];
    int *s = &stack[0];

    char ch;
    int c , v;

    do{
        printf("\npress 1 for push\npress 2 for pop\npress 3 to check list empty or not\npress 4 to display element of stack\nenter your choice : ");
        scanf("%d",&c);

        switch (c)
        {
            
            case 1 : 
                printf("enter the value to push : ");
                scanf("%d",&v);
                push(s ,v);
                break;

            case 2:
                pop(s);
                break;

            case 3 :
                is_empty(s);
                break;

            case 4 :
                printf("\n\nthe element in the stack are : ");
                dis(s);
                break;

            default : 
                printf("\nenter a valid option : ");
                break;
        }

        printf("\n\ndo you want to continue?");
        scanf(" %c",&ch);

    }while((ch=='y')||(ch=='Y'));

    return 0;
}