#include <stdio.h>

#define STATES 2

int dfaAccepts(char input[]) {
    int currentState = 0;
    
    for (int i = 0; input[i] != '\0'; i++) {
        if (currentState == 0)
            currentState = 1;
        else if (currentState == 1)
            currentState = 0;
    }
    
    return (currentState == 0); // If the final state is reached, return 1 (accept), otherwise return 0 (reject)
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
