#include <stdio.h>
#include <stdlib.h>

void bin_search(int a[], int n,int key)
{   
    
    int high, mid, low;
    high = n - 1;
    low = 0;

    while (high >= low)
    {
        mid = (high + low) / 2;
        if (a[mid] == key)
        {
            printf("Key found at position %d", mid);
            exit(0);
        }

        else if (a[mid] > key)
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }
    printf("Unsuccessful search");
}

int main()
{
    int a[10];
    int n;
    int res=0;
    int key;

    printf("Enter number of elements:");
    scanf("%d", &n);
    printf("Enter array elements:");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the key to be found:");
    scanf("%d", &key);

    return 0;
}