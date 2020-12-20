//Standard C lib headers
#include <stdlib.h> //For malloc
#include <string.h> //For memset

//User defined Headers
#include "stack.h"

struct stack* initStack(int stackSize)
{
    //Allocate memory to stackll
    struct stack* freshStack = (struct stack*)malloc(sizeof(struct stack));

    //Allocate memory to stack
    freshStack->capacity = stackSize;

    //As its empty initialize with -1
    freshStack->noOfItems = -1;

    //Allocate memory for Data
    freshStack->dataArray = (int *) malloc(sizeof(int) * stackSize);

    //Reset all data to 0 so we don't get garbage
    memset(freshStack->dataArray, '\0', sizeof(int) * stackSize);

    return freshStack;
}

void pushToStack(struct stack* stackHead, int value)
{
    if((stackHead->noOfItems + 1) >= stackHead->capacity)
    {
        printf("\n******************************\n");
        printf("Exception: Stackoverflow...!!!\n");
        printf("******************************\n\n");
        return;
    }

    stackHead->dataArray[++stackHead->noOfItems] = value;
}

int popFromStack(struct stack *stackHead)
{
    return stackHead->dataArray[stackHead->noOfItems--];
}

void destroyStack(struct stack *stackHead)
{
    free(stackHead->dataArray);
    free(stackHead);
}

/***************************************************************
          Only to be used for debugging purposes
***************************************************************/

void printStack(struct stack* stackHead, char printArg)
{
    int printSize;

    //Print metadata of the stack
    if(printArg & STACK_PRINT_METADATA == STACK_PRINT_METADATA)
    {
        printf("Stack Meta Data is: \n");
        printf("Number of Items Currently in Stack: %d\n", stackHead->noOfItems + 1);
        printf("Capacity of Stack is: %d\n", stackHead->capacity);
    }

    //Print All data
    if((printArg & STACK_PRINT_DATA_ALL) == STACK_PRINT_DATA_ALL)
    {
        printSize = stackHead->capacity;
    }
    //Print only the populated data
    else
    {
        printSize = stackHead->noOfItems;
    }

    //Store reference into local variable
    int *dataArray = stackHead->dataArray;

    //Print this only if some data has to be printed
    if(printSize > -1)
    {
        printf("Stack Data is: \n");
    }

    //Print Data
    for (int i = 0; i < printSize; i++)
    {
        printf("%08X: %d\n", i, dataArray[i]);
    }
}