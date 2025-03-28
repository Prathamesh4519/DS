#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    char stack[MAX];
    int top;
} Stack;

// Function prototypes
void push(Stack *s, char element);
char pop(Stack *s);
char peek(Stack *s);
int precedence(char operator);
int isOperator(char symbol);
void infixToPostfix(char infix[], char postfix[]);

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

void push(Stack *s, char element) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        s->stack[++(s->top)] = element;
    }
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return '\0';
    } else {
        return s->stack[(s->top)--];
    }
}

char peek(Stack *s) {
    if (s->top == -1) {
        return '\0';
    } else {
        return s->stack[s->top];
    }
}

int precedence(char operator) {
    switch (operator) {
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    s.top = -1;
    int i = 0, j = 0;
    char symbol;

    while ((symbol = infix[i++]) != '\0') {
        if (isalnum(symbol)) { // If symbol is operand
            postfix[j++] = symbol;
        } else if (symbol == '(') {
            push(&s, symbol);
        } else if (symbol == ')') {
            while (peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '('
        } else if (isOperator(symbol)) { // If symbol is operator
            while (s.top != -1 && precedence(peek(&s)) >= precedence(symbol)) {
                postfix[j++] = pop(&s);
            }
            push(&s, symbol);
        }
    }

    // Pop all remaining operators from stack
    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}