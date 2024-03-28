#include <iostream>
#include <cstring> // Include the correct header for strlen
using namespace std;

#define STATES 2
#define ALPHABET_SIZE 2
int transitionTable[STATES][ALPHABET_SIZE] = {
    {1, 0},   
    {1, 1}    
};

bool isAccepted(char *input) {
    int currentState = 0; 
    int len = strlen(input); // Use strlen from <cstring> header

    for (int i = 0; i < len; i++) {
        char symbol = input[i];
        int inputIndex;

        if (symbol == 'a')
            inputIndex = 0;
        else if (symbol == 'b')
            inputIndex = 1;
        else {
            cout << "Invalid input character '" << symbol << "'\n";
            return false;
        }

        currentState = transitionTable[currentState][inputIndex];
    }

    return currentState == 1; 
}

int main() {
    char input[100];
    cout << "Enter the string to check if it's accepted by the DFA: ";
    cin >> input;

    if (isAccepted(input))
        cout << "String '" << input << "' is accepted by the DFA.\n";
    else
        cout << "String '" << input << "' is not accepted by the DFA.\n";

    return 0;
}

