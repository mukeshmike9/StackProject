//Standard C lib headers
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//User defined Headers
#include "stack.h"

/**
 * @brief This will reverse the Stack in a recursive manner
 * 
 * @param stackHead : Pointer to Stack Head
 */
void reverseStack(struct stack* stackHead);


//Return 0 to the calling OS for success execution
int main()
{
    //Using the size as 10
    struct stack *stackHead = initStack(10);
    fillDummyValues(stackHead);
    printStack(stackHead, STACK_PRINT_ALL);

    reverseStack(stackHead);

    printStack(stackHead, STACK_PRINT_ALL);

    //Free the memory allocated to stack
    destroyStack(stackHead);

    //Ask user to end program
    printf("Press enter key to exit...!!!\n");
    
    //Wait till user inputs a character
    getchar();
    
    //Return 0 for Success Execution
    return 0;
}

void reverseStack(struct stack* stackHead)
{
    if(isStackEmpty(stackHead))
    {
        int data = popFromStack(stackHead);
        reverseStack(stackHead);
        pushToBottom(stackHead, data);
    }
}