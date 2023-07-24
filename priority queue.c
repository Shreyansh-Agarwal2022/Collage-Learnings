#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX 5

// Define a structure to store the data and priority
typedef struct {
    int data;
    int priority;
} Element;

// Define a structure to store the queue
typedef struct {
    Element elements[MAX];
    int size;
} PriorityQueue;

// Initialize an empty queue
void init(PriorityQueue *q) {
    q->size = 0;
}

// Check if the queue is empty
int isEmpty(PriorityQueue *q) {
    return q->size == 0;
}

// Check if the queue is full
int isFull(PriorityQueue *q) {
    return q->size == MAX;
}

// Compare the priorities of two elements
// Return 1 if e1 has higher priority than e2, 0 otherwise
int compare(Element e1, Element e2) {
    return e1.priority > e2.priority;
}

// Enqueue an element to the queue
// If the queue is full, print an error message
void enqueue(PriorityQueue *q, Element e) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    // Find the position to insert the element
    int i = q->size - 1;
    while (i >= 0 && compare(e, q->elements[i])) {
        // Shift the elements to the right
        q->elements[i + 1] = q->elements[i];
        i--;
    }
    // Insert the element at the found position
    q->elements[i + 1] = e;
    // Increment the size of the queue
    q->size++;
}

// Dequeue an element from the queue
// If the queue is empty, print an error message and return a dummy element
Element dequeue(PriorityQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        Element dummy = {-1, -1};
        return dummy;
    }
    // Get the first element of the queue
    Element e = q->elements[0];
    // Shift the elements to the left
    for (int i = 0; i < q->size - 1; i++) {
        q->elements[i] = q->elements[i + 1];
    }
    // Decrement the size of the queue
    q->size--;
    // Return the dequeued element
    return e;
}

// Print the elements of the queue
void print(PriorityQueue *q) {
    for (int i = 0; i < q->size; i++) {
        printf("(%d, %d) ", q->elements[i].data, q->elements[i].priority);
    }
    printf("\n");
}

// Test the priority queue implementation
int main() {
    PriorityQueue q;
    init(&q);
    
    Element e1 = {10, 3};
    Element e2 = {5, 4};
    Element e3 = {7, 2};
    
    enqueue(&q, e1);
    enqueue(&q, e2);
    enqueue(&q, e3);
    
    print(&q);
    
    Element e4 = dequeue(&q);
    
    print(&q);
    
    printf("Dequeued element: (%d, %d)\n", e4.data, e4.priority);
    
}