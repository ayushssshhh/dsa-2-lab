#include<stdio.h>

int main(){

    int n;                                                          //inputing no. of element in an array
    printf("enter no. of element of an array : ");
    scanf("%d",&n);
    
    int a[n];                                                      //defining an array of size n

    printf("enter the value of the elements of an array : ");       //inputing the values of the element
    for(int i=0 ; i<n ; i++)
    scanf("%d",&a[i]);

    for(int i=0 ; i<n ; i++){                                       //loop for updating array
        int j=i;
        while(j<n){                                                 
            if(a[i]<a[j]){                                          //when next greatest element is found then the its value will be stoed in current pos of i pointer and while loop will exit which wil further led to move the for loop pointer to move to next pointer
                a[i]=a[j];
                j=n;
            }
            j++;
        }
    }
    printf("\n\n the updated array is :");                          //printing the updated array
    for(int i=0 ; i<n ; i++)
    printf("%3d",a[i]);
    
    return 0;
}