#include <stdio.h>

int binary_search(int arr[], int size, int key) {
   int low = 0, high = size - 1, mid;
   while (low <= high) {
      mid = (low + high) / 2;
      if (arr[mid] == key) {
         return mid;
      } else if (arr[mid] < key) {
         low = mid + 1;
      } else {
         high = mid - 1;
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

   result = binary_search(arr, size, key);
   if (result == -1) {
      printf("%d is not present in the array\n", key);
   } else {
      printf("%d is present at index %d\n", key, result);
   }

   return 0;
}
