#include<stdio.h>

int main(){

    int n,ne=0,no=0,j=0,k=0;                            //local variable
    printf("enter the no. of element : ");
    scanf("%d",&n);                                     //inputing no of element

    int a[n];                                           //defining array of size n

    printf("enter the values in array : ");             //inputing value of array
    for(int i=0 ; i<n ; i++)
    scanf("%d",&a[i]);

    for(int i=0 ; i<n ; i++){                           //counting no. of even and odd element vlaue
        if(a[i]%2==0)
        ne++;
        else
        no++;
    }
    
    int ev[ne],od[no];                                 //defing arrays for even and odd element 

    for(int i=0 ; i<n ; i++){                          //stroing the even and odd elements value in main array to a seperate even and odd array respectively 
        if(a[i]%2==0)
        ev[j++]=a[i];
        else
        od[k++]=a[i];
    }

    /*for(int i=0 ; i<ne ; i++)                        //updating(sorting) main array using 2loop
    a[i]=ev[i];
   
    for(int i=0 ; i<no ; i++)
    a[i+ne]=od[i];*/

    for(int i=0 ; i<n ; i++){                          //updating(sorting) main array using 1 loop only
        if(i<ne)
        a[i]=ev[i];
        else
        a[i]=od[i-ne];
    }

    for(int i=0 ; i<n ; i++)                          //printing the sorted main array
    printf("%3d",a[i]);
    
    return 0;
}