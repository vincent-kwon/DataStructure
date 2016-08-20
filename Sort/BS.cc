#include <iostream>

using namespace std;

#define NUM 5

int a[] = { 100, 300, 200, 500, 0 };

void swap(int i , int j) {
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

int binarySearch(int num, int start, int end) {
  if (start > end) return -1; // think about 0, 1 case.
                              // bs(0,0), bs(2,1) mid is 1 
  if (start == end) {
    if (a[num] != a[start]) return -1;
    else return start;
  }

  int half = (end - start + 1) / 2; // if 0,3 mid is second half's first

  int mid = start + half; // if even number start + half - 1 represents last of first half

  if (a[mid] == num) { 
    return mid;
  }
  
  if (num < a[mid]) return binarySearch(num, start, mid-1);
  else return binarySearch(num, mid+1, end);
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

  int r = binarySearch(1000, 0, NUM-1);
  cout << r << endl;

  return 0;
}
