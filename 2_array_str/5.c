#include <stdio.h>
#include <stdlib.h>

struct word{
    char str1[25] ;
};

int main(){

    int n_str=0 , n_word=1 , k=0 , j ; 

    char str[1000];
    printf("\n\nenter your sentence : ");
    for(int i=0 ; i<1000 ; i++)
    scanf("%[^\n]s",&str[i]);

    while(str[n_str]!='\0')
    n_str++;


    for(int i=0 ; i<n_str ; i++){
        
        if(str[i]==32)
        n_word++;        

    }
    
    struct word *w = (struct word*)calloc(n_word , sizeof(struct word));
  
    for(int i=0 ; i<n_word ; i++){
       
        j=0 ;
        while(str[k]!=32)
        (w+i)->str1[j++] = str[k++];
        k++;

    }

    for(int i=0 ; i<n_word ; i=i+2)
    printf("%s ",(w+i)->str1);

    printf("\n");
    for(int i=1 ; i<n_word ; i=i+2)
    printf("%s ",(w+i)->str1);

    return 0;
} 