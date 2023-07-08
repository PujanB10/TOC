/* Turing Machine for equal number of a's and b's*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_TAPE_SIZE 100

enum states
{
    q0,
    q1,
    q2,
    q3,

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
bool calculate(TuringMachine *tm)
{
    enum states curstate = q0;
    while (true)
    {
        char currentSymbol = tm->tape[tm->head];
        if (curstate == q0)
        {
            if (currentSymbol == 'a')
            {
                tm->tape[tm->head] = 'X';
                tm->head++;
                curstate = q1;
            }
            else if (currentSymbol == 'b')
            {
                tm->tape[tm->head] = 'X';
                tm->head++;
                curstate = q3;
            }
            else if (currentSymbol == 'X')
            {
                tm->head++;
            }
            else if (currentSymbol == 'B' || currentSymbol == '\0')
            {
                curstate = qf;
                return true;
            }
        }
        else if (curstate == q1)
        {
            if (currentSymbol == 'a')
            {
                tm->head++;
            }
            else if (currentSymbol == 'b')
            {
                tm->tape[tm->head] = 'X';
                tm->head--;
                curstate = q2;
            }
            else if (currentSymbol == 'X')
            {
                tm->head++;
            }
            else
            {
                return false;
            }
        }
        else if (curstate == q2)
        {
            if (currentSymbol == 'a' || currentSymbol == 'b' || currentSymbol == 'X')
            {
                tm->head--;
            }

            else if (currentSymbol == 'B' || currentSymbol == '\0')
            {
                tm->head++;
                curstate = q0;
            }
        }
        else if (curstate == q3)
        {
            if (currentSymbol == 'a')
            {
                tm->tape[tm->head] = 'X';
                tm->head--;
                curstate = q2;
            }
            else if (currentSymbol == 'b' || currentSymbol == 'X')
            {
                tm->head++;
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
    if (calculate(&tm))
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }
    return 0;
}