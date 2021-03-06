//Standard C lib headers
#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //for malloc
#define STACK_SIZE 11

//Global Variables
struct tripleStack {
    int basePointer1;
    int stackPointer1;
    int basePointer2;
    int stackPointer2;
    int basePointer3;
    int stackPointer3;
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
 * @brief Push data to stack 2
 * 
 * @param value : Value to be pushed
 * @return int -1 if error, else 0
 */
int push2(int value);

/**
 * @brief Push data to stack 3
 * 
 * @param value : Value to be pushed
 * @return int -1 if error, else 0
 */
int push3(int value);

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

/**
 * @brief This pops a vlue from Stack 3
 * 
 * @return int popped value from stack
 */
int pop3();

//Return 0 to the calling OS for success execution
int main()
{
    initStack();
    int loop = 1;
    int choice = 0;
    int value;
    while(loop)
    {
        printf("Enter Your Choice:\n1> Pop 1\n2> Pop 2\n3> Pop 3\n4> Push 1\n5> Push 2\n6> Push 3\n0> Exit\n");
        scanf("%d", &choice);

        //Stack operations to be done based on choice
        switch(choice)
        {
            case 1:
                value = pop1();
                printf("Popped Value: %d\n", value);
            break;
            case 2:
                value = pop2();
                printf("Popped Value: %d\n", value);
            break;
            case 3:
                value = pop3();
                printf("Popped Value: %d\n", value);
            break;
            case 4:
                printf("Enter Number\n");
                scanf("%d", &value);
                push1(value);
            break;
            case 5:
                printf("Enter Number\n");
                scanf("%d", &value);
                push2(value);
            break;
            case 6:
                printf("Enter Number\n");
                scanf("%d", &value);
                push3(value);
            break;
            case 0:
                loop = 0;
                break;
            default:
                printf("%d is an Invalid choice, Try Again...!!!\n", choice);
        }
        //printDualStackData();
    }
    
    //Destroy Stack
    free(stackHead.array);

    //Return 0 for Success Execution
    return 0;
}

int push1(int value)
{
    //Check for data overlap
    if(stackHead.stackPointer1 >= (stackHead.basePointer2 - 1))
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
    if(stackHead.stackPointer2 >= (stackHead.basePointer3 - 1))
    {
        printf("Stack Overflow...!!!\n");
        return -1;
    }
    stackHead.array[++stackHead.stackPointer2] = value;
    return 0;
}

int push3(int value)
{
    //Check for out of Memory Bounds
    if(stackHead.stackPointer3 >= (STACK_SIZE - 1))
    {
        printf("Stack Overflow...!!!\n");
        return -1;
    }
    stackHead.array[++stackHead.stackPointer3] = value;
    return 0;
}

int pop1()
{
    if(stackHead.stackPointer1 < stackHead.basePointer1)
    {
        printf("Stack Empty...!!!\n");
        return -1;
    }

    return stackHead.array[stackHead.stackPointer1--];
}

int pop2()
{
    if(stackHead.stackPointer2 < stackHead.basePointer2)
    {
        printf("Stack Empty...!!!\n");
        return -1;
    }

    return stackHead.array[stackHead.stackPointer2--];
}

int pop3()
{
    if(stackHead.stackPointer3 < stackHead.basePointer3)
    {
        printf("Stack Empty...!!!\n");
        return -1;
    }

    return stackHead.array[stackHead.stackPointer3--];
}

void initStack()
{
    //Equal Partitioning Method is used here, Other algos can be applied too depending on the use case
    stackHead.basePointer1 = 0;
    stackHead.basePointer2 = STACK_SIZE/3;
    stackHead.basePointer3 = (STACK_SIZE/3)*2;
    stackHead.stackPointer1 = stackHead.basePointer1 - 1;
    stackHead.stackPointer2 = stackHead.basePointer2 - 1;
    stackHead.stackPointer3 = stackHead.basePointer3 - 1;
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
    printf("Base Pointer 1: %d\nStack Pointer 1: %d\nBase Pointer 2: %d\nStack Pointer 2: %d\nBase Pointer 3: %d\nStack Pointer 3: %d\n",
           stackHead.basePointer1,
           stackHead.stackPointer1,
           stackHead.basePointer2,
           stackHead.stackPointer2,
           stackHead.basePointer3,
           stackHead.stackPointer3);

    for (int i = 0; i < STACK_SIZE; i++)
    {
        printf("%08X: %d\n", i, stackHead.array[i]);
    }
}