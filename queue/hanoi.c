#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Function prototypes
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int isEmpty(Queue *q);
void solveTowerOfHanoi(int n, Queue *source, Queue *auxiliary, Queue *destination);

int main() {
    int n;
    Queue source, auxiliary, destination;

    // Initialize the queues
    source.front = source.rear = -1;
    auxiliary.front = auxiliary.rear = -1;
    destination.front = destination.rear = -1;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Initialize the source queue with disks
    for (int i = n; i >= 1; i--) {
        enqueue(&source, i);
    }

    printf("Steps to solve Tower of Hanoi:\n");
    solveTowerOfHanoi(n, &source, &auxiliary, &destination);

    return 0;
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
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1; // Reset queue
    }
    return value;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void solveTowerOfHanoi(int n, Queue *source, Queue *auxiliary, Queue *destination) {
    if (n == 1) {
        // Move a single disk from source to destination
        int disk = dequeue(source);
        enqueue(destination, disk);
        printf("Move disk %d from Source to Destination\n", disk);
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary using destination
    solveTowerOfHanoi(n - 1, source, destination, auxiliary);

    // Step 2: Move the nth disk from source to destination
    int disk = dequeue(source);
    enqueue(destination, disk);
    printf("Move disk %d from Source to Destination\n", disk);

    // Step 3: Move the n-1 disks from auxiliary to destination using source
    solveTowerOfHanoi(n - 1, auxiliary, source, destination);
}