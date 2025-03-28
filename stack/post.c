// p=6523+8*+3+*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int stack[MAX];
    int top;
} Stack;

// Function prototypes
void push(Stack *s, int value);
int pop(Stack *s);
int isOperator(char symbol);
int evaluatePostfix(char postfix[]);

int main() {
    char postfix[MAX];

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of the postfix evaluation: %d\n", result);

    return 0;
}

void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->stack[++(s->top)] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->stack[(s->top)--];
}

int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int evaluatePostfix(char postfix[]) {
    Stack s;
    s.top = -1;
    int i = 0;
    char symbol;

    while ((symbol = postfix[i++]) != '\0') {
        if (isdigit(symbol)) {  // If operand, push it to stack
            push(&s, symbol - '0'); // Convert character to integer
        } else if (isOperator(symbol)) {  // If operator, pop two operands
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            int result;

            switch (symbol) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator!\n");
                    exit(EXIT_FAILURE);
            }
            push(&s, result);  // Push the result back onto the stack
        }
    }

    return pop(&s);  // Final result
}