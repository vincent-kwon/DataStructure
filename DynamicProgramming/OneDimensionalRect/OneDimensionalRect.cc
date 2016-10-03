#include <iostream>
#include <stack>

using namespace std;

#define N 4
int maxSize = -987654321;
int m[N] = {4, 3, 2, 1};

int getNextSize(int i, int last, bool isFinal) {
  int height = m[last]; // i = 2, last = 1
  int width;
  if (isFinal) 
    width = i;
  else
    width = i - last;
  int size = height * width;
  if (size > maxSize) maxSize = size;
  return 0;
}

int process(stack<int>& s, int i) 
{
  while (!s.empty()) {
    int last = s.top();
    bool isFinal = false;
    if (m[i] < m[last]) {
      s.pop();
      if (s.empty()) isFinal = true;
      getNextSize(i, last, isFinal);
    } 
    else {
      break;
    } 
  }
  s.push(i);
  return 0;
}

int main() 
{
  stack<int> s;
  int i = 0;

  s.push(i);

  int n = 4;
  for (i = 1; i < n ; i++) {
    if (m[i] >= m[s.top()]) {
      s.push(i);
    }
    else {
      process(s, i);
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
    getNextSize(i, last, isFinal);
  }

  cout << maxSize << endl;
  return 0;
}
