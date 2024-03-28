#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 100
#define MAX_TRANSITIONS 100

typedef struct {
    int state;
    int next_state;
    char symbol;
} Transition;

typedef struct {
    int state;
    int is_final;
    Transition transitions[MAX_TRANSITIONS];
    int num_transitions;
} State;

void epsilon_closure(int state, int num_states, State states[], int visited[]) {
    visited[state] = 1;
    printf("%d ", state);

    for (int i = 0; i < states[state].num_transitions; i++) {
        if (states[state].transitions[i].symbol == 'e') {
            int next_state = states[state].transitions[i].next_state;
            if (!visited[next_state])
                epsilon_closure(next_state, num_states, states, visited);
        }
    }
}

int main() {
    State states[MAX_STATES];
    int num_states, num_symbols;

    printf("Enter the number of states: ");
    scanf("%d", &num_states);

    printf("Enter the number of symbols (excluding epsilon): ");
    scanf("%d", &num_symbols);


    for (int i = 0; i < num_states; i++) {
        states[i].state = i;
        states[i].num_transitions = 0;
        states[i].is_final = 0;
    }

    for (int i = 0; i < num_states; i++) {
        int num_transitions;
        printf("Enter the number of transitions for state %d: ", i);
        scanf("%d", &num_transitions);

        for (int j = 0; j < num_transitions; j++) {
            Transition t;
            printf("Enter transition %d for state %d (next state, symbol): ", j+1, i);
            scanf("%d %c", &t.next_state, &t.symbol);
            states[i].transitions[j] = t;
            states[i].num_transitions++;
        }
    }

    int num_final_states;
    printf("Enter the number of final states: ");
    scanf("%d", &num_final_states);

    printf("Enter the final states: ");
    for (int i = 0; i < num_final_states; i++) {
        int final_state;
        scanf("%d", &final_state);
        states[final_state].is_final = 1;
    }

    printf("\nEpsilon Closure for all states:\n");
    for (int i = 0; i < num_states; i++) {
        printf("Epsilon closure for state %d: ", i);
        int visited[MAX_STATES] = {0};
        epsilon_closure(i, num_states, states, visited);
        printf("\n");
    }

    return 0;
}

