#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH_OF_ELEMENT 256
#define NUMBER_OF_ELEMENTS 5

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void printArray(char **array, int *pItemsRemoved) {
    for(int i = 0; i < NUMBER_OF_ELEMENTS - (*pItemsRemoved); i++) {
        printf("%s\n", array[i]);
    }
    printf("\n");
}

int getLength (char string[]) {
    int counter = 0;
    while (string[counter] != '\0') {
        counter++;
    }

    return counter;
}

char ** shortenArray(char **array, int *pItemsRemoved) {
    int shortestLength = getLength(array[0]);
    int shortestIndex = 0;

    for(int i = 0; i < NUMBER_OF_ELEMENTS - (*pItemsRemoved); i++) {
        int newLength = getLength(array[i]);
        if(shortestLength > newLength) {
            shortestLength = newLength;
            shortestIndex = i;
        }
    }
    printf("Shortest string removed: %s\n", array[shortestIndex]);


    free(array[shortestIndex]);
    for (int i = shortestIndex; i < NUMBER_OF_ELEMENTS - (*pItemsRemoved); i++) {
        array[i] = array[i + 1];
    }

    (*pItemsRemoved)++;
    array = realloc(array, (NUMBER_OF_ELEMENTS - *pItemsRemoved) * sizeof(char *));
    return array;
}

int main (int argc, char **argv) {
    
    int itemsRemoved = 0;

    char string[MAX_LENGTH_OF_ELEMENT];
    char **strings = (char **) malloc(NUMBER_OF_ELEMENTS * sizeof(char *));

    for (int i = 0; i < NUMBER_OF_ELEMENTS; ++i) {
        strings[i] = (char *)malloc(MAX_LENGTH_OF_ELEMENT + sizeof(char));
        // printf("Enter string: ");
        scanf("%s", string);
        strcpy(strings[i], string);
    }

    strings = shortenArray(strings, &itemsRemoved);
    printf("Array after removal:\n");
    printArray(strings, &itemsRemoved);

    free(strings);
}