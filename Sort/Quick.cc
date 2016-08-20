#include <iostream>

using namespace std;

#define NUM 5

int a[] = { 100, 300, 200, 500, 0 };

void swap(int i , int j) {
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

void quickSort(int start, int end) {
  int p = a[end];
  int smallerEnd = start - 1;  

  if (start > end) return;

  for (int i = start; i < end; i++) {
    if (a[i] < p) {
      smallerEnd++;
      swap(smallerEnd, i);
    }
  }

  swap(smallerEnd+1, end);
  
  quickSort(start, smallerEnd); // if no smaller start > smallerEnd
  quickSort(smallerEnd+2, end); // if no bigger start > smallerEnd
}

int main() {
  quickSort(0,NUM-1);
  for (int i = 0 ; i < NUM ; i++) {
    cout << a[i] << endl;
  }
  return 0;
}
