#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char value) {
   if (top == MAX_SIZE - 1) {
      printf("Error: Stack overflow\n");
      return;
   }
   top++;
   stack[top] = value;
}

char pop() {
   if (top == -1) {
      printf("Error: Stack is empty\n");
      return '\0';
   }
   char value = stack[top];
   top--;
   return value;
}

int priority(char symbol) {
   switch (symbol) {
      case '(':
         return 0;
      case '+':
      case '-':
         return 1;
      case '*':
      case '/':
         return 2;
      case '^':
         return 3;
      default:
         return 0;
   }
}

void infixToPostfix(char infix[], char postfix[]) {
   int i, j = 0;
   char item;
   for (i = 0; i < strlen(infix); i++) {
      item = infix[i];
      if (isalnum(item)) {
         postfix[j++] = item;
      } else if (item == '(') {
         push(item);
      } else if (item == ')') {
         while (stack[top] != '(') {
            postfix[j++] = pop();
         }
         pop();
      } else {
         while (priority(stack[top]) >= priority(item)) {
            postfix[j++] = pop();
         }
         push(item);
      }
   }
   while (top != -1) {
      postfix[j++] = pop();
   }
   postfix[j] = '\0';
}

int main() {
   char infix[MAX_SIZE], postfix[MAX_SIZE];
   printf("Enter an infix expression: ");
   scanf("%s", infix);
   infixToPostfix(infix, postfix);
   printf("Postfix expression: %s\n", postfix);
   return 0;
}
