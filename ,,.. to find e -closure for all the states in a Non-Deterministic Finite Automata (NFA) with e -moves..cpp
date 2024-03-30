#include<stdio.h>
#include<stdlib.h>
#define MAX_STATES 100
#define MAX_ALPHABETS 100
int states, alphabets, finalStates[MAX_STATES], transitionTable[MAX_STATES][MAX_ALPHABETS][MAX_STATES], epsilonClosure[MAX_STATES][MAX_STATES];
void epsilonClosureDFS(int state, int currentState) {
    int i;
    for (i = 0; i < states; i++) {
        if (transitionTable[currentState][alphabets][i] == 1 && epsilonClosure[state][i] == 0) {
            epsilonClosure[state][i] = 1;
            epsilonClosureDFS(state, i);
        }
    }
}
void computeEpsilonClosure() {
    int i, j;
    for (i = 0; i < states; i++) {
        for (j = 0; j < states; j++) {
            epsilonClosure[i][j] = 0;
        }
    }
    for (i = 0; i < states; i++) {
        epsilonClosureDFS(i, i);
    }
}
int main() {
    int i, j, k;
    printf("Enter the number of states: ");
    scanf("%d", &states);
    printf("Enter the number of alphabets (excluding epsilon): ");
    scanf("%d", &alphabets);
    for (i = 0; i < states; i++) {
        for (j = 0; j <= alphabets; j++) {
            for (k = 0; k < states; k++) {
                transitionTable[i][j][k] = 0;
            }
        }
    }
    printf("Enter the transition table (use -1 to denote absence of transition):\n");
    for (i = 0; i < states; i++) {
        for (j = 0; j <= alphabets; j++) {
            printf("From state %d on alphabet %c: ", i, (j == alphabets) ? 'e' : 'a' + j);
            scanf("%d", &transitionTable[i][j][0]);
            if (transitionTable[i][j][0] == -1) {
                transitionTable[i][j][0] = 0;
            }
        }
    }
    printf("Enter the final states (Enter -1 to end):\n");
    i = 0;
    while (1) {
        scanf("%d", &finalStates[i]);
        if (finalStates[i] == -1) break;
        i++;
    }
    computeEpsilonClosure();
    printf("\nEpsilon Closure:\n");
    for (i = 0; i < states; i++) {
        printf("e-Closure(%d): ", i);
        for (j = 0; j < states; j++) {
            if (epsilonClosure[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return 0;
}
