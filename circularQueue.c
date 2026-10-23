#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = 0, rear = -1, count = 0;

void enqueue(int reading)
{
    if (count == SIZE) {
        printf("Queue Overflow!\n");
        return;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = reading;
    count++;

    printf("Inserted: %d\n", reading);
}

void dequeue()
{
    if (count == 0) {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Removed: %d\n", queue[front]);
    front = (front + 1) % SIZE;
    count--;
}

void display()
{
    int i;

    if (count == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue (front to rear): ");

    for (i = 0; i < count; i++) {
        printf("%d ",
               queue[(front + i) % SIZE]);
    }

    printf("\nFront index = %d\n", front);
    printf("Rear index = %d\n", rear);
    printf("Count = %d\n", count);
}

int main()
{
    printf("--- Insert five readings ---\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();

    printf("\n--- Remove three readings ---\n");
    dequeue();
    dequeue();
    dequeue();
    display();

    printf("\n--- Insert three new readings ---\n");
    enqueue(60);
    enqueue(70);
    enqueue(80);
    display();

    return 0;
}
