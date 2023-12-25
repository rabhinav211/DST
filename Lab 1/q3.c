#include <stdio.h>
#include <stdlib.h>

void check(int a[][4], int key)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == key)
            {
                printf("Key found at position %d,%d", i, j);
                exit(0);
            }
        }
    }
    printf("Unsuccessful search");
}

void main()
{
    int a[4][4] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int key = 5;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == key)
            {
                printf("Key found at position %d,%d", i, j);
            }
        }
    }
}