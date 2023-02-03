#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node *next;
};

struct Node* head = NULL;

void insert_at_beginning(int data) {
   struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = data;
   new_node->next = head;
   head = new_node;
}

void insert_at_end(int data) {
   struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = data;
   new_node->next = NULL;

   if (head == NULL) {
      head = new_node;
      return;
   }

   struct Node *last = head;
   while (last->next != NULL) {
      last = last->next;
   }
   last->next = new_node;
}

void delete_at_position(int position) {
   if (head == NULL) {
      return;
   }

   struct Node *temp = head;
   if (position == 0) {
      head = temp->next;
      free(temp);
      return;
   }

   int i;
   for (i = 0; temp != NULL && i < position - 1; i++) {
      temp = temp->next;
   }
   if (temp == NULL || temp->next == NULL) {
      return;
   }

   struct Node *next = temp->next->next;
   free(temp->next);
   temp->next = next;
}

void display() {
   struct Node *temp = head;
   while (temp != NULL) {
      printf("%d, ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

int main() {
   int choice, value, position;
   while (1) {
      printf("1. Insert at beginning\n");
      printf("2. Insert at end\n");
      printf("3. Delete at position\n");
      printf("4. Display\n");
      printf("5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            printf("Enter the value to insert at beginning: ");
            scanf("%d", &value);
            insert_at_beginning(value);
            break;
         case 2:
            printf("Enter the value to insert at end: ");
            scanf("%d", &value);
            insert_at_end(value);
            break;
         case 3:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            delete_at_position(position);
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
