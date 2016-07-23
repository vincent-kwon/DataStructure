#include <iostream>
#include <stack>

using namespace std;

#define N 100
int maxSize = -987654321;
int M[N][N];
int A[N][N];
bool squareOnly = false;

int getNextSize(int i, int last, bool isFinal,int rowIndex) {
  int height = A[rowIndex][last]; // i = 2, last = 1
  int width;
  if (isFinal) 
    width = i;
  else
    width = i - last;
  int size = height * width;
  if (squareOnly && (height != width)) return 0; 
  if (size > maxSize) maxSize = size;
  return 0;
}

int process(stack<int>& s, int i, int rowIndex) 
{
  while (!s.empty()) {
    int last = s.top();
    bool isFinal = false;
    if (A[rowIndex][i] < A[rowIndex][last]) {
      s.pop();
      if (s.empty()) isFinal = true;
      getNextSize(i, last, isFinal, rowIndex);
    } 
    else {
      break;
    } 
  }
  s.push(i);
  return 0;
}

int getMaxForSingleColumn(int rowIndex, int colSize)  
{
  stack<int> s;
  int i = 0;
  int n = colSize;

  s.push(i);

  for (i = 1; i < n ; i++) {
    if (A[rowIndex][i] >= A[rowIndex][s.top()]) {
      s.push(i);
    }
    else {
      process(s, i, rowIndex);
    }
  }

/*
 * {1,2,1}
 *      _
 * 2  _|_|_
 * 1 |_|_|_| 
 *   0 1 2 3 4
 *
 * i  0 1 2 3
 *
 * i = 2, top = 1, 
 *
 */

  while (!s.empty()) {
    int last = s.top();
    bool isFinal = false;
    s.pop();
    if (s.empty()) isFinal = true;
    getNextSize(i, last, isFinal, rowIndex);
  }

  cout << maxSize << endl;
  return maxSize;
}

int main() {
  int size;
  squareOnly = true;
  cin >> size;
  int r = -987654321;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cin >> M[i][j];
      if (M[i][j] != 0) { 
        if (i > 0) A[i][j] = A[i-1][j] + M[i][j];
        else A[i][j] = M[i][j];
      }
      else A[i][j] = 0;
    }
    r = max(getMaxForSingleColumn(i,size),r);
  }
  
  cout << "Max:" << r << endl;
  return 0;
}
