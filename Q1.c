#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

typedef struct {
    int stack[MAX];
    int top;
} Stack;

void push(Stack *s, int element) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        s->stack[++(s->top)] = element;
    }
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return s->stack[(s->top)--];
    }
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q) {
    if (q->front == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return value;
}

void reverk(int k, Queue *q, Stack *s) {
    for (int i = 0; i < k; i++) {
        int x = dequeue(q);
        push(s, x);
    }
    for (int i = 0; i < k; i++) {
        int y = pop(s);
        enqueue(q, y);
    }
    int size = q->rear - q->front + 1;
    for (int i = 0; i < size - k; i++) {
        int temp = dequeue(q);
        enqueue(q, temp);
    }
    while (q->front <= q->rear) {
        int z = dequeue(q);
        printf("%d\n", z);
    }
}

int main() {
    int n;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    Queue source;
    source.front = source.rear = -1;
    printf("Enter the numbers\n");
    for (int i = 0; i < n; i++) {
        int b;
        scanf("%d", &b);
        enqueue(&source, b);
    }
    int k;
    printf("Enter the number of elements to be reversed\n");
    scanf("%d", &k);
    Stack s;
    s.top = -1;
    reverk(k, &source, &s);
    return 0;
}
