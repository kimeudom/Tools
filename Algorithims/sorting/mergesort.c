#include <stdio.h>

void merge(float array[], int start, int median, int end) {
  // Counters
  int i, j, k;

  // Size of the left and right arrays
  int sizeLeft = median - start + 1;
  int sizeRight = end - median;

  // Creating sub arrays
  float leftArr[sizeLeft];
  float rightArr[sizeRight];

  for (i = 0; i < sizeLeft; i++) {
    leftArr[i] = array[start + i];
  }

  for (int j = 0; j < sizeRight; j++) {
    rightArr[j] = array[median + j + 1];
  }

  // Reseting the counters
  i = 0;
  j = 0;
  k = start;

  while (i < sizeLeft && j < sizeRight) {
    if (leftArr[i] <= rightArr[j]) {
      array[k] = leftArr[i];
      i++;
    } else {
      array[k] = rightArr[j];
      j++;
    }
    k++;
  }

  // In the case where either the left or right elements have not been
  // completely added to the main array The remaining elements are added
  while (i < sizeLeft) {
    array[k] = leftArr[i];
    i++;
    k++;
  }

  while (j < sizeRight) {
    array[k] = rightArr[j];
    j++;
    k++;
  }
}

void mergesort(float array[], int start, int end) {
  if (end > start) {
    int median = start + (end - start) / 2;

    // Split the array into two halves
    mergesort(array, start, median);
    mergesort(array, median + 1, end);

    merge(array, start, median, end); // Merge sort this current half
  }
}