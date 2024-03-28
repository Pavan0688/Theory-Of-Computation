#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool simulateNFA(char *input) {
    int currentState = 0; 
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        char symbol = input[i];

        if (currentState == 0 && symbol == 'b')
            currentState = 1;
        else if (currentState == 1 && symbol == 'a')
            currentState = 2;
        else
            currentState = -1;
    }
    return currentState == 2;
}

int main() {
    char input[100];
    printf("Enter the string to check if it's accepted by the NFA: ");
    scanf("%s", input);

    if (simulateNFA(input))
        printf("String '%s' is accepted by the NFA.\n", input);
    else
        printf("String '%s' is not accepted by the NFA.\n", input);

    return 0;
}

