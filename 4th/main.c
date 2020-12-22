//Standard C lib headers
#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //for malloc
#define STACK_SIZE 5

//Global Variables
struct dualStack {
    int basePointer1;
    int stackPointer1;
    int basePointer2;
    int stackPointer2;
    int *array;
} stackHead; //Initializing a single instance of stack 

/**
 * @brief This will print the metadata of stack
 * 
 */
void printDualStackData(void);

/**
 * @brief Initialize the stack
 * 
 */
void initStack(void);

/**
 * @brief Push data to stack 1
 * 
 * @param value : Value to be pushed
 * @return int -1 if error, else 0
 */
int push1(int value);

/**
 * @brief Push data to stack 1
 * 
 * @param value : Value to be pushed
 * @return int -1 if error, else 0
 */
int push2(int value);

/**
 * @brief This pops a vlue from Stack 1
 * 
 * @return int popped value from stack
 */
int pop1();

/**
 * @brief This pops a vlue from Stack 2
 * 
 * @return int popped value from stack
 */
int pop2();

//Return 0 to the calling OS for success execution
int main()
{
    initStack();
    int loop = 1;
    int choice = 0;
    int value;
    while(loop)
    {
        printf("Enter Your Choice:\n1> Pop 1\n2> Pop 2\n3> Push 1\n4> Push 2\n0> Exit\n");
        scanf("%d", &choice);

        //Stack operations to be done based on choice
        switch(choice)
        {
            case 1:
                value = pop1();
                printf("Popped Value: %d\n", value);
            break;
            case 2:
            break;
            case 3:
                printf("Enter Number\n");
                scanf("%d", &value);
                push1(value);
            break;
            case 4:
                printf("Enter Number\n");
                scanf("%d", &value);
                push2(value);
            break;
            case 0:
                loop = 0;
                break;
            default:
                printf("%d is an Invalid choice, Try Again...!!!\n", choice);
        }
        printDualStackData();
    }
    
    //Return 0 for Success Execution
    return 0;
}

int push1(int value)
{
    //Check for data overlap
    if(stackHead.stackPointer1 >= (stackHead.stackPointer2 - 1))
    {
        printf("Stack Overflow...!!!\n");
        return -1;
    }
    stackHead.array[++stackHead.stackPointer1] = value;
    return 0;
}

int push2(int value)
{
    //Check for data overlap
    if(stackHead.stackPointer2 <= (stackHead.stackPointer1 + 1))
    {
        printf("Stack Overflow...!!!\n");
        return -1;
    }
    stackHead.array[--stackHead.stackPointer2] = value;
    return 0;
}

int pop1()
{
    if(stackHead.stackPointer1 < 0)
    {
        printf("Stack Empty...!!!\n");
        return -1;
    }

    return stackHead.array[stackHead.stackPointer1--];
}

int pop2()
{
    //As stack size is already +1 than array index we need to check for equal value too
    if(stackHead.stackPointer2 >= STACK_SIZE)
    {
        printf("Stack Empty...!!!\n");
        return -1;
    }

    return stackHead.array[stackHead.stackPointer2++];
}


void initStack()
{
    stackHead.basePointer1 = 0;
    stackHead.basePointer2 = STACK_SIZE - 1; //1 less because offset starts from 0
    stackHead.stackPointer1 = stackHead.basePointer1 - 1;
    stackHead.stackPointer2 = stackHead.basePointer2 + 1;
    stackHead.array = (int*) malloc(STACK_SIZE); 

    for (int i = 0; i < STACK_SIZE; i++)
    {
        //Init with -1
        stackHead.array[i] = -1;
    }
}

void printDualStackData()
{
    printf("Dual Stack Data:\n");
    printf("Base Pointer 1: %d\nStack Pointer 1: %d\nBase Pointer 2: %d\nStack Pointer 2: %d\n",
           stackHead.basePointer1,
           stackHead.stackPointer1,
           stackHead.basePointer2,
           stackHead.stackPointer2);

    for (int i = 0; i < STACK_SIZE; i++)
    {
        printf("%08X: %d\n", i, stackHead.array[i]);
    }
}