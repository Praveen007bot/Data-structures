#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
   if (top == MAX_SIZE - 1) {
      printf("Error: Stack overflow\n");
      return;
   }
   top++;
   stack[top] = data;
}

int pop() {
   if (top == -1) {
      printf("Error: Stack is empty\n");
      return -1;
   }
   int data = stack[top];
   top--;
   return data;
}

int peek() {
   if (top == -1) {
      printf("Error: Stack is empty\n");
      return -1;
   }
   return stack[top];
}

void display() {
   int i;
   printf("Stack: ");
   for (i = 0; i <= top; i++) {
      printf("%d, ", stack[i]);
   }
   printf("\n");
}

int main() {
   int choice, value;
   while (1) {
      printf("1. PUSH\n");
      printf("2. POP\n");
      printf("3. PEEK\n");
      printf("4. Display\n");
      printf("5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            printf("Enter the value to PUSH: ");
            scanf("%d", &value);
            push(value);
            break;
         case 2:
            value = pop();
            if (value != -1) {
               printf("Popped value: %d\n", value);
            }
            break;
         case 3:
            value = peek();
            if (value != -1) {
               printf("Peek value: %d\n", value);
            }
            break;
         case 4:
            display();
            break;
         case 5:
            exit(0);
            break;
         default:
            printf("Invalid choice.\n");
      }
   }
   return 0;
}
