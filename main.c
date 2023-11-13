#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numStrings;
    printf("Enter the number of strings please: ");
    scanf("%d", &numStrings);

    char **strings = (char **)malloc(numStrings * sizeof(char *)); // Array of pointers for strings

    if (strings == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    for (int i = 0; i < numStrings; i++) {
        char buffer[100]; // Buffer for reading each string
        printf("Enter string %d: ", i + 1);
        scanf(" %99[^\n]", buffer);

        strings[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char)); // Allocating memory for the string
        if (strings[i] == NULL) {
            printf("Memory allocation failed.");
            return 1;
        }
       
    // Encrypt the string
        for (int j = 0; buffer[j] != '\0'; j++) {
            strings[i][j] = buffer[j] + 3;
        }

        strings[i][strlen(buffer)] = '\0'; // Null-terminate the encrypted string

        // Alternatively, you can use strcpy to copy the encrypted string
        // strcpy(strings[i], buffer); // Assuming buffer is already encrypted

        // If you want to print the encrypted string
        printf("Encrypted String %d: %s\n", i + 1, strings[i]);
    
    
               
    }
    
    // Accessing and printing each string
    for (int i = 0; i < numStrings; i++) {
        printf("String %d: %s\n", i + 1, strings[i]);
    }

    // Freeing allocated memory for each string
    for (int i = 0; i < numStrings; i++) {
        free(strings[i]);
    }

    // Freeing memory for the array of pointers
    free(strings);

    return 0;
}
