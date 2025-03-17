// p=6523+8*+3+*
#include <stdio.h>
#include <stdlib.h>


#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

int pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

int evaluatePostfix(const char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        
        if (isdigit(ch)) {
            push(ch - '0'); 
        } else {
            int operand2 = pop();
            int operand1 = pop();
            
            switch (ch) {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': 
                    if (operand2 != 0)
                        push(operand1 / operand2);
                    else {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
        }
    }
    return pop();
}

int main() {
    const char* postfixExpression = "6523+8*+3+*";
    int result = evaluatePostfix(postfixExpression);
    printf("The result of the postfix expression is: %d\n", result);
    return 0;
}
