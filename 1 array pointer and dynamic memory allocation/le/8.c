#include <stdio.h>

int main()
{
    int n,se,ee,nse=0,nee=0;   //local variable 
    printf("enter the no. of element : ");  //inputinig no. of element
    scanf("%d",&n);
   
    int a[n]; //defining array
    printf("\n\nenter the value of elements : ");
    for(int i=0 ; i<n ; i++)
    scanf("%d",&a[i]);   //inputinig elements in an array
   
    printf("\n\nthe array is : ");   //printing array
    for(int i=0 ; i<n ; i++)
    printf("%2d",a[i]);
   
    printf("\n\nenter the elements to be searched respectively : ");
    scanf("%d%d",&se,&ee);  //inputinig elements to be searched
    
    for(int i=0 ; i<n ; i++){  //counting itiration of 1st element which is to be searched
       if(se==a[i]){
           nse++;
        }
    }
    
    for(int i=0 ; i<n ; i++){  //counting itiration of 2nd element which is to be searched
       if(ee==a[i]){
           nee++;
        }
    }
    
    if((nee>0)&&(nse>0)){
        int pos_se[nse] , pos_ee[nee], k=0;  //pos array for both element
    
        for(int i=0 ; i<n ; i++){  //storing pos of every itiration of se in pos_se
            if(se==a[i])
            pos_se[k++]=i;
        }    
            
        k=0;
        for(int i=0 ; i<n ; i++){  //storing pos of every itiration of ee in pos_se
            if(ee==a[i])
            pos_ee[k++]=i;
        }
    
        int q=0 ,temp=0,min_diff=n;
    
        for(int i=0 ; i<nse ; i++){
            for(int j=0 ; j<nee ; j++){
                temp = pos_se[i]-pos_ee[j];
                if(temp<0)
                temp=temp*(-1);
                if(min_diff>temp)
                min_diff=temp;
            }
        }
    
        printf("\n\nthe min diffrence between %d %d%d",se,ee,min_diff); //printing min_diff between two elements
    }
    
    else
    printf("\n\nnos. %d %d are not in array",se,ee);
    
    return 0;
}