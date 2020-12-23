//Standard C lib headers
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//User defined Headers
#include "stack.h"

//Return 0 to the calling OS for success execution
int main()
{
    struct stack *stack;
    stack = initStack(0);
    int loop = 1;
    int choice = 0;
    int value;
    while(loop)
    {
        printf("Enter Your Choice:\n1> Pop\n2> Push\n3>Find Middle\n4>Delete Middle\n0> Exit\n");
        scanf("%d", &choice);

        //Stack operations to be done based on choice
        switch(choice)
        {
            case 1:
                value = popFromStack(stack);
                printf("Popped Value: %d\n", value);
            break;
            case 2:
                printf("Enter Number\n");
                scanf("%d", &value);
                pushToStack(stack, value);
            break;
            case 3:
                value = findMiddleFromStack(stack);
                if(value != -1)
                {
                    printf("Middle Value: %d\n", value);
                }
            break;
            case 4:
                deleteMiddleFromStack(stack);
            break;
            case 0:
                loop = 0;
                break;
            default:
                printf("%d is an Invalid choice, Try Again...!!!\n", choice);
        }
        //printStack(stack, STACK_PRINT_ALL);
    }

    //Free Memory
    destroyStack(stack);
    
    //Return 0 for Success Execution
    return 0;
}
