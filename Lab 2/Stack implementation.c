#include<stdio.h>
#include<string.h>

#define max 10

int stack[max];
int top=-1;

void push(int c){
    if(top==max-1){
        printf("Stack is full");
        return;
    }
    top++;
    stack[top]=c;
}

void pop(){
    if(top==-1){
        printf("Stack is empty");
        return;
    }
    top--;
    printf("The popped elements is:%d",stack[top+1]);
}

void display(){
    if(top==-1){
        printf("Stack is empty");
    }

    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
}

int main(){
    int choice;
    int a;


    while (1)
    {
        printf("\nSelect an option\n1.Push element into stack\n2.Pop element from stack\n3.Display stack\nChoice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter element to be pushed:");
                scanf("%d",&a);
                push(a);
                break;
            case 2:
                pop();
                break;
            default:
                display();
        }
        printf("\n");
    }

    return 0;
}