#include <stdio.h>
#include <string.h>

#define MAX_LENGTH_OF_ELEMENT 100
#define NUMBER_OF_ELEMENTS 5

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void printArray(char array[NUMBER_OF_ELEMENTS][MAX_LENGTH_OF_ELEMENT]) {
    for(int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
        printf("%s ", array[i]);
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

int main (int argc, char **argv) {

    char string[MAX_LENGTH_OF_ELEMENT];
    char strings[NUMBER_OF_ELEMENTS][MAX_LENGTH_OF_ELEMENT];

    for (int i = 0; i < 5; i++) {
        printf("Enter string: ");
        scanf("%s", string);
        strcpy(strings[i], string);
    }
    
    printArray(strings);
}