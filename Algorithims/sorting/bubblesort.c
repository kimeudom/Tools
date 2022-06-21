// Bubble sort implementation to sort a float array

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

float randomFloat(void) { return rand() % 100 + rand() % 100 * .01; }

// Swap the float value a with b
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

int main(int argc, char **argv) {
  // Seeding the time base for random number generation
  srand(time(0));

  // Validating the input
  if (argc < 3 || argc > 3) {
    printf("Incorrect usage\n"
           "USAGE :: ./bubblesort.c [Flags] <<number of array elements>>\n"
           "Flags\n-------------\n"
           "-i     iteration\n"
           "-r     recursion\n");

    return -1;
  }

  int sizeOfArray = (int)atol(argv[2]);
  char flag = argv[1][1];
  float array[sizeOfArray];

  // Filling the array
  for (int i = 0; i < sizeOfArray; i++) {
    array[i] = randomFloat();
  }

  // Sorting the arrays accordingly
  if (strcmp(argv[1], "-r") == 0) {
    bubbleSortRecursive(array, sizeOfArray);
  } else {
    bubbleSortIterative(array, sizeOfArray);
  }
  return 0;
}