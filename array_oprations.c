#include <stdio.h>

#define MAX_SIZE 100  

int arr[MAX_SIZE];
int size = 0;

void display() {
   int i;
   printf("Elements are: ");
   for (i = 0; i < size; i++) {
      printf("%d, ", arr[i]);
   }
   printf("\n");
}

void insert(int element, int position) {
   int i;
   if (position > size || position < 0) {
      printf("Invalid Position\n");
   } else {
      for (i = size; i > position; i--) {
         arr[i] = arr[i-1];
      }
      arr[position] = element;
      size++;
      printf("Element inserted successfully\n");
   }
}

void delete(int position) {
   int i;
   if (position >= size || position < 0) {
      printf("Invalid Position\n");
   } else {
      for (i = position; i < size-1; i++) {
         arr[i] = arr[i+1];
      }
      size--;
      printf("Element deleted successfully\n");
   }
}

int main() {
   int choice, element, position;

   while (1) {
      printf("1. Insert\n");
      printf("2. Delete\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &element);
            printf("Enter the position: ");
            scanf("%d", &position);
            insert(element, position);
            break;
         case 2:
            printf("Enter the position of element to be deleted: ");
            scanf("%d", &position);
            delete(position);
            break;
         case 3:
            display();
            break;
         case 4:
            return 0;
         default:
            printf("Invalid choice\n");
      }
   }
   return 0;
}
