#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = 0;
int rear = -1;

void enqueue(int value) {
   if (rear == MAX_SIZE - 1) {
      printf("Error: Queue overflow\n");
      return;
   }
   rear++;
   queue[rear] = value;
}

int dequeue() {
   if (front > rear) {
      printf("Error: Queue underflow\n");
      return -1;
   }
   int value = queue[front];
   front++;
   return value;
}

void display() {
   if (front > rear) {
      printf("Error: Queue is empty\n");
      return;
   }
   printf("Queue elements are: ");
   for (int i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
   }
   printf("\n");
}

int main() {
   int choice, value;
   while (1) {
      printf("\n1. Enqueue\n");
      printf("2. Dequeue\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            printf("Enter a value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
         case 2:
            printf("Dequeued element: %d\n", dequeue());
            break;
         case 3:
            display();
            break;
         case 4:
            return 0;
         default:
            printf("Error: Invalid choice\n");
      }
   }
   return 0;
}
