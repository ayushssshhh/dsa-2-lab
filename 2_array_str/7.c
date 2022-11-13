#include <stdio.h>

int main(){
    char a[100] , b ,c=0;
    printf("enter the word : ");
    scanf("%s",a);
    
    int i=0;
    while (a[i]!='\0')
    i++;

    printf("\n\nenter the letter to search : ");
    scanf("\n%c",&b);

    for(int j=0 ; j<i ; j++){
        if(a[j]==b)
        c++;
    }

    printf("\n\nthe letter %c occoured in word %s for %d times ",b,a,c);

    return 0;
} 