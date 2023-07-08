/*IMPLEMENTATION OF STORAGE IN STATE TURING MACHINE THAT ACCEPTS STRING ab* + ba*  */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_TAPE_SIZE 100

enum states
{
    q0,
    q1,
    qf
};

// Structure to represent the Turing Machine
typedef struct TuringMachine
{
    char tape[MAX_TAPE_SIZE];
    int head;
} TuringMachine;

// Function to initialize the Turing Machine
void initializeTuringMachine(TuringMachine *tm, char *input)
{
    strcpy(tm->tape, input);
    tm->head = 0;
}
// Function to perform the Turing Machine computation
bool performComputation(TuringMachine *tm)
{

    enum states curstate = q0;
    char stateStorage = 'B';
    while (true)
    {
        char currentSymbol = tm->tape[tm->head];
        if (curstate == q0)
        {

            if (currentSymbol == 'a' && stateStorage == 'B')
            {
                tm->head++;
                curstate = q1;
                stateStorage = currentSymbol;
            }
            else if (currentSymbol == 'b' && stateStorage == 'B')
            {

                tm->head++;
                curstate = q1;
                stateStorage = currentSymbol;
            }

            else
            {
                return false;
            }
        }
        else if (curstate == q1)
        {

            if (currentSymbol == 'b' && stateStorage == 'a')
            {
                tm->head++;
                curstate = q1;
            }
            else if (currentSymbol == 'a' && stateStorage == 'b')
            {
                tm->head++;
                curstate = q1;
            }
            else if (currentSymbol == 'B' || currentSymbol == '\0')
            {
                tm->head--;
                curstate = qf;
                stateStorage = currentSymbol;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
int main()
{
    TuringMachine tm;
    char input[MAX_TAPE_SIZE];
    printf("Enter a string: ");
    scanf("%s", input);
    initializeTuringMachine(&tm, input);
    if (performComputation(&tm))
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Not Accepted\n");
    }
    return 0;
}