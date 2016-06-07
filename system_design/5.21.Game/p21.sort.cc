#include <iostream>

using namespace std;

int a[] = { 1, 2, 3, 4, 5 };
int b[] = { 1, 100, 2, 200, 400, 50 };

void swap(int &a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int print(int p[], int start_index, int end_index) {
  for (int i = start_index ; i <= end_index; i++) 
    cout << p[i] << " " ; 
  cout << " " << endl;
  return 0;
}

int quickSort(int p[], int start_index, int end_index) {
  int v = p[end_index];
  int size = end_index - start_index + 1;
  int lastOfStart = start_index - 1;

  /* 1 2 3 rule sort (no bigger) or 2 3 1 (no smaller). In both case, start > end */
  if (start_index > end_index) return 0; 

  if (size == 1) return 0;

  if (size == 2) { 
    if (p[start_index] > p[end_index]) swap(p[start_index], p[end_index]);
    return 0;
  }

  for (int i = 0 ; i < size-1; i++)
    if (p[start_index + i] < v) {
      lastOfStart++; // this may the first index of big
      swap(p[lastOfStart], p[start_index+i]);
    } 

  swap(p[++lastOfStart], p[end_index]);
  quickSort(p, start_index, lastOfStart - 1);
  quickSort(p, lastOfStart + 1, end_index);
  return 0;
}

int main() {
  quickSort(a, 0, 4);
  quickSort(b, 0, 5);
  print(a,0,4);
  print(b,0,5);
  return 0;
}
