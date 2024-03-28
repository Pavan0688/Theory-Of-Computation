#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool belongsToCFG(char *input) {
    if (strlen(input) == 0) 
        return true;
    else if (input[0] == '0' && input[strlen(input) - 1] == '0') {
        char newString[strlen(input) - 2];
        strncpy(newString, input + 1, strlen(input) - 2);
        newString[strlen(input) - 2] = '\0'; 
        return belongsToCFG(newString);
    }
    else if (input[0] == '1') {
        char newString[strlen(input) - 1];
        strncpy(newString, input + 1, strlen(input) - 1);
        newString[strlen(input) - 1] = '\0'; 
        return belongsToCFG(newString);
    }
    else
        return false; 
}

int main() {
    char input[100];
    printf("Enter the string to check whether it belongs to the CFG language: ");
    scanf("%s", input);

    if (belongsToCFG(input))
        printf("The string '%s' belongs to the CFG language.\n", input);
    else
        printf("The string '%s' does not belong to the CFG language.\n", input);

    return 0;
}

