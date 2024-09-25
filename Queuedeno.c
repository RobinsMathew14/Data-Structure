#include <stdio.h>

int enqueue(int Queue[], int rear, int n) {
    if (rear == n - 1) {
        printf("\nQueue Overflow");
        return rear;
    } else {
        int item;
        rear++;
        printf("\nEnter the element to be added: ");
        scanf("%d", &item);
        Queue[rear] = item;
        return rear; 
    }
}

int dequeue(int Queue[], int front, int rear) {
    if (front > rear) {
        printf("\nQueue Underflow");
        return front; 
    } else {
        printf("\nThe deleted element is: %d", Queue[front]);
        front++;
        return front; 
}
}
void display(int Queue[], int front, int rear) {
    if (rear < front) {
        printf("\nThe queue is empty");
    } else {
        printf("\nThe elements in the queue are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Queue[i]);
        }
        printf("\n"); 
    }
}

int main() {
    int n, front = 0, rear = -1, choice;
    char c;
    
    printf("\nEnter the queue size: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("\nInvalid queue size.");
        return 1; 
    }

    int Queue[n];

    do {
        printf("\nQueue operations");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                rear = enqueue(Queue, rear, n);
                break;
            case 2:
                front = dequeue(Queue, front, rear);
                break;
            case 3:
                display(Queue, front, rear);
                break;
            default:
                printf("\nInvalid choice");
                break;
        }

        printf("\nDo you want to continue? (Y/N): ");
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');
    
    printf("\nExiting...\n");
    return 0;
}

