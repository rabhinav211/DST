#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;


    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    printf("Values Before swapping: a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("Values After swapping: a = %d, b = %d\n", a, b);

    return 0;
}
