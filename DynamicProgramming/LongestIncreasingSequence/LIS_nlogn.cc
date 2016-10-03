#include <iostream>

using namespace std;

#define NUM 11

int a[NUM] = { 3, 4 , -1, 5, 8, 2, 3, 12, 7, 9, 10 }; // -1 2 3 7 9 10
int c[NUM] = { 0, };
int f[NUM] = { 0, };
int currentMax;

int gMax = 1;

int getPos(int num) {

  for (int i = currentMax; i >= 0; i--) {
    if (a[num] > a[c[i]]) {
      return i; 
    }
  }
  return -1;
}

int main() {

  for (int i = 0; i < NUM; i++) c[i] = -1;

  c[0] = 0;  // a[0]'s num
  f[0] = -1; // a[0's came from

  currentMax = 0;

  for (int i = 1 ; i < NUM ; i++ ) {
    // search from
    int pos = getPos(i); 
    pos++;

    if (c[pos] == -1 || a[c[pos]] > a[i]) {
      c[pos] = i;
      f[pos] = c[pos-1];

      if (currentMax < pos) currentMax = pos;
    }
  }

  int r = 0;

  for (int i = NUM-1; i >= 0; i--) 
    if (c[i] != -1) {
      r = i;
      break;
    }


  cout << "r: " << r+1 << endl; 
  
  int nextNumIndex = c[r];

  while (r >= 0) {
    cout << a[c[r]] << endl;
    r--;
  }
  
  return 0;
}
