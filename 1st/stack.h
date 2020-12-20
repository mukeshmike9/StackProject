//Include only if STACK Macro is defined
//This preventys multiple inclusion of same file during compilation
#ifndef STACK
#define STACK

#define STACK_PRINT_ALL 0xFF
#define STACK_PRINT_METADATA 0x01
#define STACK_PRINT_DATA_ALL 0x02
#define STACK_PRINT_DATA_POPULATED 0x03

//This is included here as printStack will use this
#include <stdio.h>

/**
 * @brief Stack Metadata
 * @param noOfItems : Number of items currently in stack,
 * -1 means stack is empty
 * @param capacity : Size of Stack
 * @param dataArray : Array to hold the data values in a stack
 * We are using integer so as to store 32bits in a single data cell
 * as on a 64 bit CPU Arch 
 */
struct stack {
    int noOfItems;
    int capacity;
    int *dataArray;
};

/**
 * @brief This function initializes a fresh stack
 * 
 * @param stackSize : size of the stack to be allocated
 * @return struct stack : The stack head containg stack metadata
 */
struct stack* initStack(int stackSize);

/**
 * @brief This is used to free all the memory allocated to stack
 * 
 * @param stackHead  Pointer to Stack Head
 */
void destroyStack(struct stack *stackHead);


/**
 * @brief This function prints the stack data, should only be used for 
 *        debugging purposes
 * 
 * @param stackHead : Pointer to The stack head whose data is to be printed
 * @param printData : If 1 print Data values too else not
 *                    boolean can also be used but its not a default data type hence
 *                    using char as it only uses 1 byte
 */
void printStack(struct stack *stackHead, char printArg);

/**
 * @brief This function pushes data to stack
 * 
 * @param stackHead : Pointer to stack Metadata 
 * @param value : value to be pushed
 */
void pushToStack(struct stack *stackHead, int value);

/**
 * @brief This functions Pops a value from the stack
 * This function doesnt clears the data from the memory
 * If accessed directly via address the data can still be accessed
 * 
 * @param stackHead : Pointer to stack Metadata
 * @return int Data from the stack
 */
int popFromStack(struct stack *stackHead);

#endif