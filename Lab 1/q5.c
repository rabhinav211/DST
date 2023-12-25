#include<stdio.h>

void check(int a[], int n,int key){
    for(int i=(n-1);i>=0;i--){
        if(a[i]==key){
            printf("Key found at position %d",i);
            exit(0);
        }
    }
    printf("Unsuccessful search");
}

int main(){

    int a[10]={6,4,2,7,1,3};
    int key=7;
    check(a,6,key);

    return 0;
}