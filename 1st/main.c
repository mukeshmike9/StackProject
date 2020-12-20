//Standard C lib headers
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//User defined Headers
#include "stack.h"

#define ERROR_STRING "Symbols are not balanced\n"
#define SUCCESS_STRING "Symbols are balanced\n"

/**
 * @brief This function checks if the symbol is a valid bvalancing symbol or not
 * 
 * @param symbol : symbol to be checked
 * @return int 0 if true, -1 otherwise
 */
int isValidBeginSymbol(const char symbol);


//Return 0 to the calling OS for success execution
int main()
{
    //Reserving only 100 bytes for input and 1 byte for null character 
    //as chances of it are exceeding is very low
    char inputString[101];
    char currentChar, charFromStack, validateChar;
    char isError = 0;
    
    //Using the size same as string
    struct stack *stackHead = initStack(100);

    printf("Enter the String with symbols\n");

    //Store the input from user in inputString
    gets(inputString);
    puts(inputString);
    for(int i = 0; inputString[i] != '\0'; i++)
    {
        //Reset this so that next tiume if value is not updated it shouldn't be checked
        validateChar = 0;
        currentChar = inputString[i];

        if(!isValidBeginSymbol(currentChar))
        {
            //char will be converted to integer implicitly
            pushToStack(stackHead, currentChar);
        }
        else if (currentChar == ')')
        {
            validateChar = '(';
        }
        else if (currentChar == '}')
        {
            validateChar = '{';
        }
        else if (currentChar == ']')
        {
            validateChar = '[';
        }

        //Only check if validateChar variable is updated
        if (validateChar != 0)
        {
            if (isStackEmpty(stackHead))
            {
                isError = 1;
                break;
            }
            charFromStack = popFromStack(stackHead);
            if (charFromStack != validateChar)
            {
                isError = 1;
                break;
            }
        }
    }

    if(!isStackEmpty(stackHead) || isError == 1)
    {
        printf(ERROR_STRING);
    }
    else
    {
        printf(SUCCESS_STRING);
    }

    //Free the memory allocated to stack
    destroyStack(stackHead);

    //Ask user to end program
    printf("Press enter key to exit...!!!\n");
    
    //Wait till user inputs a character
    getchar();
    
    //Return 0 for Success Execution
    return 0;
}

int isValidBeginSymbol(const char symbol)
{
    //Wil be checked for only below symbols
    if ((symbol == '(') || (symbol == '[') || (symbol == '{'))
    {
        return 0;
    }
    
    return -1;
}