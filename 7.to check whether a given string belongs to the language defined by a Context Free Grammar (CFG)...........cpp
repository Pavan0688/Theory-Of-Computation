#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool belongsToCFG(char *input) {
    int len = strlen(input);
    if (len < 5)
        return false;
    if (input[0] == 'A' && input[len - 1] == 'A') {
        char newString[len - 2];
        strncpy(newString, input + 1, len - 3);
        newString[len - 3] = '\0';
        return belongsToCFG(newString);
    } else {
        return false;
    }
}

bool checkA(char *input) {
    if (strlen(input) == 0) 
        return true;
    else if (input[0] == '0' || input[0] == '1') {
        return checkA(input + 1);
    } else {
        return belongsToCFG(input);
    }
}

int main() {
    char input[100];
    printf("Enter the string to check whether it belongs to the CFG language: ");
    scanf("%s", input);

    if (belongsToCFG(input) && checkA(input))
        printf("The string '%s' belongs to the CFG language.\n", input);
    else
        printf("The string '%s' does not belong to the CFG language.\n", input);

    return 0;
}

