#include <stdio.h>

int main(){

    char a[25] , b[25];

    printf("enter two words : ");
    scanf("%s%s",a,b);

    int n_a=0 , n_b=0  , j=0 , k=0 ; 
     
    while(a[n_a]!='\0')
    n_a++;

    while(b[n_b]!='\0')
    n_b++;

    char c[n_a + n_b]; 
    
    for(int i=0 ; i < n_a + n_b ; i++ ){

        if(i%2!=0)
        c[i] = b[j++];

        else
        c[i] = a[k++];

    }

    printf("the combined string is : ");
    for(int i=0 ; i < n_a + n_b ; i++ )
    printf("%c  ",c[i]);

    return 0;
}