//Standard C lib headers
#include <stdlib.h> //For malloc
#include <string.h> //For memset

//User defined Headers
#include "stack.h"

struct stack* initStack(int stackSize)
{
    struct stackNode *iterator, *temp;
    struct stack *freshStack = (struct stack*)malloc(sizeof(struct stack));
    iterator = (struct stackNode*)malloc(sizeof(struct stackNode));
    iterator->data = -1;
    iterator->next = NULL;
    iterator->prev = NULL;
    freshStack->basePointer = iterator;
    freshStack->stackPointer = iterator;

    //Allocate memory to stack, stackSize, 1st Node is a dumy node, can't pe popped
    for(int i = 0; i < stackSize; i++)
    {
        pushToStack(freshStack, i);
    }
    return freshStack;
}

void fillDummyValues(struct stack *stackHead)
{
    struct stackNode *iterator = stackHead->basePointer->next;
    int i = 1;

    //Iterate through all nodes and populate data and increment the data variable
    while(iterator != NULL)
    {
        iterator->data = i++;
        iterator = iterator->next;
    }
}

int pushToStack(struct stack* stackHead, int value)
{
    //Create new Node
    struct stackNode *newNode = (struct stackNode*)malloc(sizeof(struct stackNode));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = stackHead->stackPointer;

    //Attach node to the list
    stackHead->stackPointer->next = newNode;

    //Update Stack Pointer
    stackHead->stackPointer = newNode;
    return 0;
}

int pushToBottom(struct stack *stackHead, int value)
{
    //Create new Node
    struct stackNode *newNode = (struct stackNode*)malloc(sizeof(struct stackNode));
    newNode->data = value;
    
    //Insert Node next of the dummy node to the new node next
    newNode->next = stackHead->basePointer->next;
    
    //If Stack is not empty then no need to update as old node doesn't exist 
    if(isStackEmpty(stackHead))
    {
        //Update prev node of the old node
        newNode->next->prev = newNode;
    }

    //Set prev node to Dummy node
    newNode->prev = stackHead->basePointer;

    //Set the 1st node as newNode
    stackHead->basePointer->next = newNode;
    
}

int popFromStack(struct stack *stackHead)
{
    if(stackHead->stackPointer->prev == NULL)
    {
        printf("Stack Empty\n");
        return -1;
    }
    struct stackNode *nodeToBePopped = stackHead->stackPointer;
    int data = nodeToBePopped->data;
    stackHead->stackPointer = nodeToBePopped->prev;
    nodeToBePopped->prev->next = NULL;
    free(nodeToBePopped);
    return data;
}

void destroyStack(struct stack *stackHead)
{
    while(popFromStack(stackHead) != -1);
    free(stackHead->basePointer);
    free(stackHead);
}

int isStackEmpty(struct stack *stackHead)
{
    if(stackHead->stackPointer->prev == NULL)
    {
        return 0;
    }
    return -1;
}

/***************************************************************
          Only to be used for debugging purposes
***************************************************************/

void printNode(struct stackNode* node, int address)
{
    if(node != NULL)
    {
        printf("%08X: %d\n", address, node->data);
    }
}

void printStack(struct stack* stackHead, char printArg)
{
    int printSize;
    struct stackNode *iterator = stackHead->basePointer;
    //Print metadata of the stack
    if(printArg & STACK_PRINT_METADATA == STACK_PRINT_METADATA)
    {
        printf("Stack Meta Data is: \n");
        printf("Base Pointer: ");
        printNode(stackHead->basePointer, 0);
        printf("Stack Pointer: ");
        printNode(stackHead->stackPointer, 0xFFFFFFFF);
    }

    //Print All data
    if((printArg & STACK_PRINT_DATA_ALL) == STACK_PRINT_DATA_ALL)
    {
        int i = 0;
        while (iterator != NULL)
        {
            printNode(iterator, i++);
            iterator = iterator->next;
        }
        
    }
}