/*TURING MACHINE FOR palindrome*/

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
    q4,
    q5,
    q6
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
    while (true)
    {
        char currentSymbol = tm->tape[tm->head];
        if (curstate == q0)
        {
            if (currentSymbol == 'a')
            {

                tm->tape[tm->head] = 'B';

                tm->head++;
                curstate = q1;
            }
            else if (currentSymbol == 'b')
            {

                tm->tape[tm->head] = 'B';
                tm->head++;
                curstate = q4;
            }

            else if (currentSymbol == '\0' || currentSymbol == 'B')
            {
                curstate = q6;
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

                tm->head++;
            }
            else if (currentSymbol == 'B' || currentSymbol == '\0')
            {

                curstate = q2;
                tm->head--;
            }
        }
        else if (curstate == q2)
        {
            if (currentSymbol == 'a')
            {
                tm->tape[tm->head] = 'B';
                tm->head--;
                curstate = q3;
            }
            else if (currentSymbol == '\0' || currentSymbol == 'B')
            {
                curstate = q6;
                return true;
                tm->head++;
            }

            else
            {
                return false;
            }
        }
        else if (curstate == q3)
        {
            if (currentSymbol == 'a')
            {

                tm->head--;
            }
            else if (currentSymbol == 'b')
            {
                tm->head--;
            }
            else if (currentSymbol == 'B' || currentSymbol == '\0')
            {

                tm->head++;
                curstate = q0;
            }
        }
        else if (curstate == q4)
        {
            if (currentSymbol == 'a')
            {

                tm->head++;
            }
            else if (currentSymbol == 'b')
            {

                tm->head++;
            }

            else if (currentSymbol == 'B' || currentSymbol == '\0')
            {

                tm->head--;
                curstate = q5;
            }
        }
        else if (curstate == q5)
        {

            if (currentSymbol == 'b')
            {

                tm->tape[tm->head] = 'B';
                tm->head--;
                curstate = q3;
            }

            else if (currentSymbol == '\0' || currentSymbol == 'B')
            {
                curstate = q6;
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
    printf("Enter a string over a and b: ");
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