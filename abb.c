#include <stdio.h>

#define STATES 4

int dfaAccepts(char input[]) {
    int currentState = 0;
    
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == 'a') {
            if (currentState == 0)
                currentState = 1;
            else if (currentState == 1)
                currentState = 1;
            else if (currentState == 2)
                currentState = 1;
            else if (currentState == 3)
                currentState = 3;
        } else if (input[i] == 'b') {
            if (currentState == 0)
                currentState = 0;
            else if (currentState == 1)
                currentState = 2;
            else if (currentState == 2)
                currentState = 3;
            else if (currentState == 3)
                currentState = 3;
        } else {
            currentState = 0; // If an unrecognized symbol is encountered, transition to the initial state
        }
    }
    
    return (currentState == 3); // If the final state is reached, return 1 (accept), otherwise return 0 (reject)
}

int main() {
    char input[100];
    
    printf("Enter the input string: ");
    scanf("%s", input);
    
    if (dfaAccepts(input)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }
    
    return 0;
}