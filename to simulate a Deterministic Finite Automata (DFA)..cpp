#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STATES 2
#define ALPHABET_SIZE 2

// Transition table for the DFA
int transitionTable[STATES][ALPHABET_SIZE] = {
    {1, 0},   // If current state is 0, and input is '0', move to state 1. If input is '1', stay in state 0.
    {1, 1}    // If current state is 1, and input is '0', stay in state 1. If input is '1', stay in state 1.
};

// Function to check if input string is accepted by the DFA
bool isAccepted(char *input) {
    int currentState = 0; 
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        char symbol = input[i];
        int inputIndex;

        if (symbol == '0')
            inputIndex = 0;
        else if (symbol == '1')
            inputIndex = 1;
        else {
            printf("Invalid input character '%c'\n", symbol);
            return false;
        }

        currentState = transitionTable[currentState][inputIndex];
    }

    return currentState == 1; 
}

int main() {
    char input[100];
    printf("Enter the string to check if it's accepted by the DFA: ");
    scanf("%s", input);

    if (isAccepted(input))
        printf("String '%s' is accepted by the DFA.\n", input);
    else
        printf("String '%s' is not accepted by the DFA.\n", input);

    return 0;
}

