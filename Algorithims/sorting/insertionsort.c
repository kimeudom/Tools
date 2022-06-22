#include <stdio.h>

// The insertion sort algorithim
void insertionSort(float array[], int size) {
  for (int i = 0; i < size; i++) {
    float currentValue = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > array[j + 1]) {
      array[j + 1] = array[j];
      j -= 1;
    }
    array[j + 1] = currentValue;
  }
}