#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

// Push function
void push(int value)
{
    top++;
    stack[top] = value;
}

// Pop function
int pop()
{
    int value = stack[top];
    top--;
    return value;
}

int main()
{
    char postfix[100];
    int i, a, b, result;

    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    for(i = 0; postfix[i] != '\0'; i++)
    {
        // If character is a digit
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');   // Convert character to integer
        }
        else
        {
            a = pop();
            b = pop();

            switch(postfix[i])
            {
                case '+':
                    result = b + a;
                    break;
                case '-':
                    result = b - a;
                    break;
                case '*':
                    result = b * a;
                    break;
                case '/':
                    result = b / a;
                    break;
            }

            push(result);
        }
    }

    printf("Result = %d", pop());

    return 0;
}
