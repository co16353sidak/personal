#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int place[10];
int newplace[10];

// creation of simulated unstable program which changes position of equal elements

int unstable(int arr[10]) {
  int i, j;
  for (i = 0; i <= 9; i++) {
    for (j = 0; j <= 8; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
  }

  // swapping of equal elements take place
  for (i = 0; i < 10; i++) {
    if (arr[i] == arr[i + 1]) {
      int temp = arr[i];
      arr[i + 1] = arr[i];
      arr[i] = temp;
    }
  }
  return 0;
}

int stable_sort(int arr[10]) {
  int i, j;
  for (i = 0; i <= 9; i++) {
    for (j = 0; j <= 8; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      } else if (arr[j] == arr[j + 1]) {
        continue; // maintain order
      }
    }
  }
  return 0;
}

int main() {
  int arr[10];
  int i;
  std::cout << "Enter the elements" << '\n';
  for (i = 0; i < 10; i++) {
    std::cin >> arr[i];
  }

  for (i = 0; i < 10; i++) {
    if (arr[i] == arr[i + 1]) {
      place[i] = arr[i];
      place[i + 1] = arr[i];
    }
  }

  // using unstable algorithm to sort the elements
  unstable(arr);
  std::cout << "Sorting using unstable algorithm is : " << '\n';
  for (i = 0; i < 10; i++) {
    std::cout << arr[i] << '\n';
  }

  for (i = 0; i < 10; i++) {
    if (arr[i] == arr[i + 1]) {
      newplace[i] = arr[i];
      newplace[i + 1] = arr[i];
    }
    std::cout << "Stablizing the algorithm and then sorting" << '\n';
    stable_sort(arr);
    for (i = 0; i < 10; i++) {
      std::cout << arr[i] << '\n';
    }
  }
}
