#include <stdio.h>

int main(){
    char str[] = "hello world";

    int n_str=0 ;

    while( str[n_str] != '\0' )
    n_str++;

    printf("\n\nthe string is : %s\n\nthe reverse string is : ",str);

    for(int i=n_str-1 ; i>=0 ; i--)
    printf("%c",str[i]);

    return 0 ;
}