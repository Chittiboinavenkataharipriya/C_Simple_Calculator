#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY 100

int main() 
{
    double num1, num2, result;
    int operation;

    double num1History[MAX_HISTORY];
    double num2History[MAX_HISTORY];
    char opHistory[MAX_HISTORY];
    double resultHistory[MAX_HISTORY];
    
    int historyCount = 0;

    printf("============================================\n");
    printf("        WELCOME TO SIMPLE CALCULATOR        \n");
    printf("============================================\n");

    while (1) 
    {
        printf("\nSelect operation:\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Modulus (%%)\n");
        printf("6. Clear Screen\n");
        printf("7. View History\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &operation) != 1) 
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (operation) 
        {
            case 1: 
            case 2: 
            case 3:
            case 4: 
            case 5:
            {
                printf("Enter first number: ");
                if (scanf("%lf", &num1) != 1) 
                {
                    printf("Invalid input.\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter second number: ");
                if (scanf("%lf", &num2) != 1) {
                    printf("Invalid input.\n");
                    while (getchar() != '\n');
                    break;
                }

                if ((operation == 4 || operation == 5) && num2 == 0) {
                    printf("Error: Division by zero!\n");
                    break;
                }

                switch (operation) 
                {
                    case 1: 
                    {
                        result = num1 + num2; 
                        break;
                    }
                    case 2:
                    { 
                        result = num1 - num2; 
                        break;
                    }
                    case 3:
                    { 
                        result = num1 * num2; 
                        break;
                    }
                    case 4:
                    { 
                        result = num1 / num2; 
                        break;
                    }
                    case 5:
                    { 
                        result = num1 - num2 * (int)(num1 / num2); 
                        break;
                    } 
                }
                char opChar;
                switch (operation) 
                {
                    case 1:
                    { 
                        opChar = '+'; 
                        break;
                    }
                    case 2: 
                    {
                        opChar = '-'; 
                        break;
                    }
                    case 3:
                    { 
                        opChar = '*'; 
                        break;
                    }
                    case 4:
                    { 
                        opChar = '/'; 
                        break;
                    }
                    case 5:
                    { 
                        opChar = '%'; 
                        break;
                    }
                }
                printf("\n-----------------------------------\n");
                printf("Result: %.2lf %c %.2lf = %.2lf\n", num1, opChar, num2, result);
                printf("-----------------------------------\n");
                
                if (historyCount < MAX_HISTORY)
                {
                    num1History[historyCount] = num1;
                    num2History[historyCount] = num2;
                    opHistory[historyCount] = opChar;
                    resultHistory[historyCount] = result;
                    historyCount++;
                }
                break;
            }
            case 6:
            {
                system("clear || cls");
                break;
            }
            case 7:
            {
                if (historyCount == 0) 
                {
                    printf("No calculations yet.\n");
                }
                else 
                {
                    printf("\n========== Calculation History ==========\n");
                    for (int i = 0; i < historyCount; i++)
                    {
                        printf("\n%d. %.2lf %c %.2lf = %.2lf\n", i + 1, num1History[i], opHistory[i], num2History[i], resultHistory[i]);
                    }
                    printf("\n========================================\n");
                }
                break;
            }
            case 8:
            {
                printf("Thank you for using the calculator!!\n");
                return 0;
            }
            default:
            {
                printf("Invalid choice!! Please choose 1-8.\n");
            }
        }
    }
}
