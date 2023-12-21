#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int *arr2 = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        arr2[i] = n + i+1;
    }

    printf("arr: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("arr2: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    int newLength = 2 * n;
    arr = (int *)realloc(arr, newLength * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[n + i] = arr2[i];
    }

    printf("Merged array: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    free(arr2);

    return 0;
}
