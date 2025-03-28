#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char stack[MAX];
    int top;
} Stack;

// Function prototypes
void push(Stack *s, char element);
char pop(Stack *s);
int precedence(char operator);
int isOperator(char symbol);
void reverse(char str[]);
void infixToPostfix(char infix[], char postfix[]);
void infixToPrefix(char infix[], char prefix[]);

int main() {
    char infix[MAX], prefix[MAX];
    
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    
    infixToPrefix(infix, prefix);
    
    printf("Prefix expression: %s\n", prefix);
    
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

void reverse(char str[]) {
    int i, j;
    char temp;
    i = 0;
    j = strlen(str) - 1;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    s.top = -1;
    int i = 0, j = 0;
    char symbol;

    while ((symbol = infix[i++]) != '\0') {
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } else if (symbol == '(') {
            push(&s, symbol);
        } else if (symbol == ')') {
            while (s.stack[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '('
        } else if (isOperator(symbol)) {
            while (s.top != -1 && precedence(s.stack[s.top]) >= precedence(symbol)) {
                postfix[j++] = pop(&s);
            }
            push(&s, symbol);
        }
    }
    
    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }
    
    postfix[j] = '\0';
}

void infixToPrefix(char infix[], char prefix[]) {
    char postfix[MAX];
    
    reverse(infix);
    
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    
    infixToPostfix(infix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}
