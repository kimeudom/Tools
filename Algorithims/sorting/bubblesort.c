#include <stdio.h>

void swap(float *a, float *b) {
  float temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSortRecursive(float array[], int size) {
  if (size == 1) {
    return;
  }

  for (int i = 0; i < size; i++) {
    if (array[i] > array[i + 1]) {
      swap((array + i), (array + i + 1));
    }

    bubbleSortRecursive(array, size - 1);
  }
}

void bubbleSortIterative(float array[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (array[i] > array[j]) {
        swap((array + i), (array + j));
      }
    }
  }
}