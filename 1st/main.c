//Standard C lib headers
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//User defined Headers
#include "stack.h"

//Return 0 to the calling OS for success execution
int main()
{
    struct stack *stackHead = initStack(1);
    pushToStack(stackHead, 100);
    printf("Data from stack is: %d\n", popFromStack(stackHead));
    printStack(stackHead, STACK_PRINT_ALL);
    destroyStack(stackHead);
    //Ask user to end program
    printf("Press enter key to exit...!!!\n");
    
    //Wait till user inputs a character
    getchar();
    
    //Return 0 for Success Execution
    return 0;
}