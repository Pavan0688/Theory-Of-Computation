#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STATES 3

int transitionTable[STATES][2] = {
    {1, -1},
    {1, 2}, 
    {-1, -1} 
};
bool simulateNFA(char *input) {
    int currentState = 0; 
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        char symbol = input[i];

        int inputIndex;
        if (symbol == '0')
            inputIndex = 0;
        else if (symbol == '1')
            inputIndex = 1;
        else
            inputIndex = -1; 
        currentState = transitionTable[currentState][inputIndex];

        if (currentState == -1)
            break;
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

