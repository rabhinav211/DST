#include<stdio.h>

int main(){
    int a[10]={6,4,8,9,10,4,5};
    int n=7;
    int min=a[0],max=a[0];

    for(int i=0;i<7;i++){
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min=a[i];
    }

    printf("The max element is %d and minimum element is %d",max,min);

    
    return 0;
}