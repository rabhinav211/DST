#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void check(char str[],char substr[]){
    int l1=strlen(str);
    int l2=strlen(substr);
    int flag=0;

    for(int i=0;i<l1;i++){
        if(str[i]==substr[0]){
            for(int j=1;j<l2;j++){
                if(str[i+j]!=substr[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                printf("substr found at postion %d",i);
                exit(0);
            }
            flag=0;
        }
    }

}

void main(){ 
    char str[]="Ahbhinav";
    char substr[]="hin";

    check(str,substr);

}