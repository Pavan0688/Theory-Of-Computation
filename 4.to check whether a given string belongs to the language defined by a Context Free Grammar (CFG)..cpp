#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool belongsToCFG(char *input) {
    if (strlen(input) == 0) 
        return true;
    else if (strlen(input) == 1) { 
        if (input[0] == '0' || input[0] == '1') 
            return true;
        else
            return false; 
    }
    else if (strlen(input) == 2) { 
        if ((input[0] == '0' && input[1] == '0') || (input[0] == '1' && input[1] == '1')) 
            return true;
        else
            return false; 
    }
    else {
        if (input[0] == input[strlen(input) - 1]) {
            char newString[strlen(input) - 2];
            strncpy(newString, input + 1, strlen(input) - 2);
            newString[strlen(input) - 2] = '\0'; 
            return belongsToCFG(newString);
        }
        else
            return false;
    }
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

