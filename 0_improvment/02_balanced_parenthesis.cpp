#include <stdio.h>
#include <stdlib.h>

void push(int c);
void pop();
void dis_stack();

struct node{
    char para;
    struct node *next;
};

struct node* top = NULL;
int n_node = 0;

void push(char c){
   // printf("\nb: %c",c);
    struct node* newnode;
    
    n_node++;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->para = c;
    newnode->next = NULL;

    if(top == NULL)
        top = newnode;

    else{
        newnode->next = top;
        top = newnode;
    }
    //dis_stack();

}

void dis_stack(){
    struct node *ptr = top;

    while(ptr != NULL){
        printf(" %d",ptr->para);
        ptr = ptr->next;
    }
    printf("\n");
}

void pop(){
    struct node *ptr = top;

    top = top->next;
    free(ptr);

    n_node--;
    /*printf("\ns:");
    dis_stack();*/
}

int main(){
    char c[100];
    int last = 0 , p = 0;
    printf("enter your expression : ");
    scanf("%s",&c);

    int i=0 ; 
    while(c[i] != '\0'){
        if((c[i] != ')') && (c[i] != ']') && (c[i] != '}')){
            char ch = c[i];
            push(ch);

            if((c[i] == '(') || (c[i] == '[') || (c[i] == '{'))
            p++;
        }
        
        else{
            
            if(p == 0 ){
                last++;
            }
            
            else{
            
                while((top->para != '(') && (top->para != '[') && (top->para != '{')){
                    pop();
                }

            

                if((c[i] == ')') && (top->para == '(')){
                    pop();
                    p--;
                }
    

                else if((c[i] == '}') && (top->para == '{')){
                    pop();
                    p--;
                }   

                else if((c[i] == ']') && (top->para == '[')){
                    pop();
                    p--;
                }

                else
                last++;
            }
        }   
        
        if(last == 0)
            i++;

        else{
            printf("\nthe expression is not balanced parenthesize");
            break;
        }
    
    }

    if(last == 0)
    printf("the expression is balanced parethesize");
    
    return 0;
}