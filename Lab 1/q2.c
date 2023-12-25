#include <stdio.h>
#include<string.h>

#define MAX_STRINGS 5
#define MAX_STRING_LENGTH 50

void magicSort(char words[MAX_STRINGS][MAX_STRING_LENGTH]);

int main() {
    char words[MAX_STRINGS][MAX_STRING_LENGTH];

    printf("Enter %d words:\n", MAX_STRINGS);
    for (int i = 0; i < MAX_STRINGS; i++) {
        printf("Word %d: ", i + 1);
        scanf("%s", words[i]);
    }

    magicSort(words);

    printf("\nSorted Words:\n");
    for (int i = 0; i < MAX_STRINGS; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}

void magicSort(char words[MAX_STRINGS][MAX_STRING_LENGTH]) {
    int i, j;
    char temp[MAX_STRING_LENGTH];

    for (i = 0; i < MAX_STRINGS - 1; i++) {
        for (j = 0; j < MAX_STRINGS - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
}
