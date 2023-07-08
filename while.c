#include <stdio.h>
#include <string.h>

#define STATES 7

int dfaAccepts(char input[]) {
    int currentState = 0;
    
    for (int i = 0; input[i] != '\0'; i++) {
        if (currentState == 0 && input[i] == 'w')
            currentState = 1;
        else if ((currentState == 1 && input[i] == 'h') || (currentState == 3 && input[i] == 'i'))
            currentState++;
        else if (currentState == 2 && input[i] == 'i')
            currentState++;
        else if (currentState == 3 && input[i] == 'l')
            currentState++;
        else if (currentState == 4 && input[i] == 'e')
            currentState++;
        else if (currentState == 0 && input[i] == 'f')
            currentState = 6;
        else if ((currentState == 6 && input[i] == 'o') || (currentState == 7 && input[i] == 'r'))
            currentState++;
        else
            currentState = 0; // If an unrecognized symbol is encountered, transition to the initial state
    }
    
    return (currentState == 5 || currentState == 7); // If the final states are reached, return 1 (accept), otherwise return 0 (reject)
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
