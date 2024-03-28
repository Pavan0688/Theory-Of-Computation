#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool belongsToCFG(char *input) {
    if (input[0] != '0') 
        return false;

    int len = strlen(input);
    if (input[len - 1] != '1') 
        return false;
    return checkA(input + 1, len - 2);
}

bool checkA(char *input, int len) {
    if (len == 0) {
        return true;
    } else if (input[0] == '0' || input[0] == '1') {
        return checkA(input + 1, len - 1);
    } else if (input[0] == '0') {
        return checkA(input + 1, len - 1);
    } else if (input[0] == '1') {
        return checkA(input + 1, len - 1);
    } else {
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

