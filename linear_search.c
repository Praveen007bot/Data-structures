#include <stdio.h>

int linear_search(int arr[], int size, int key) {
   int i;
   for (i = 0; i < size; i++) {
      if (arr[i] == key) {
         return i;
      }
   }
   return -1;
}

int main() {
   int arr[] = {1, 2, 3, 4, 5};
   int size = sizeof(arr)/sizeof(arr[0]);
   int key, result;

   printf("Array: ");
   for (int i = 0; i < size; i++) {
      printf("%d, ", arr[i]);
   }
   printf("\n");

   printf("Enter the number to be searched: ");
   scanf("%d", &key);

   result = linear_search(arr, size, key);
   if (result == -1) {
      printf("%d is not present in the array\n", key);
   } else {
      printf("%d is present at index %d\n", key, result);
   }

   return 0;
}
