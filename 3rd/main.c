//Standard C lib headers
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//User defined Headers
#include "stack.h"

//Global variables
struct stack *stack1, *stack2;

/**
 * @brief This functions add a value to the queue
 * 
 * @param stackHead : Pointer to the stackHead
 * @param value : Value to be enqueued
 */
void enqueue(int value);

/**
 * @brief This function fetches a value from the queue
 * 
 * @param stackHead : Pointer to the stackHead
 * @return int : The dfata from the queue
 */
int dequeue(void);

//Return 0 to the calling OS for success execution
int main()
{
    //For time calculations
    clock_t start, end;

    //Using the size as 5
    stack1 = initStack(0);
    stack2 = initStack(0);

    enqueue(122);
    enqueue(125);
    enqueue(126);
    enqueue(987);
    printf("Dequed Value: %d\n", dequeue());
    printf("Dequed Value: %d\n", dequeue());
    printf("Dequed Value: %d\n", dequeue());
    printf("Dequed Value: %d\n", dequeue());

    printf("Press enter to begin enqueue time calculations\n");
    getchar();

    //Timing Calculations
    int numberOfOperations = 10000;
    for (int i = 0; i < numberOfOperations; i++)
    {
        start = clock();
        enqueue(i);
        end = clock();
        printf("Start = %ld, End = %ld\n", start, end);
        printf("Time for Enqueue number %d: %fms\n", i, (double)(end - start));
    }

    printf("Press enter to begin dequeue time calculations\n");
    getchar();

    for (int i = 0; i < numberOfOperations; i++)
    {
        start = clock();
        dequeue();
        end = clock();
        printf("Start = %ld, End = %ld\n", start, end);
        printf("Time for Dequeue number %d: %fms\n", i, (double)(end - start));
    }

    //Free the memory allocated to stack
    destroyStack(stack1);
    destroyStack(stack2);

    //Ask user to end program
    printf("Press enter key to exit...!!!\n");
    
    //Wait till user inputs a character
    getchar();
    
    //Return 0 for Success Execution
    return 0;
}

//Making enqueue operation expensive
void enqueue(int value)
{
    //push everything from stack 1 to stack 2
    while(isStackEmpty(stack1))
    {
        pushToStack(stack2, popFromStack(stack1));
    }
    
    pushToStack(stack1, value);

    //push everything from stack 2 to stack 1
    while(isStackEmpty(stack2))
    {
        pushToStack(stack1, popFromStack(stack2));
    }
}

int dequeue()
{
    return popFromStack(stack1);
}