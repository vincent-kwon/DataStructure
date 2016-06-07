#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_DISC = 12;

int get(int state, int index) {
  return (state >> (index * 2)) & 3;
}

int set(int state, int index, int value) {
//  cout << "set:" << index << "," << value ;
//  cout << " value : " << (value << (index*2)) << endl;
  return (state & ~(3<<(index*2))) | (value << (index * 2));
}

int c[1<<(MAX_DISC*2)]; //

int sgn(int x) {
  if (!x) return 0; return x > 0 ? 1 : -1; 
}

int incr(int x) { 
  if (x < 0) return x-1; return x+1; 
}

int bidir(int disc, int begin, int end) {
  // check same
  if (begin == end) return 0;

  queue<int> q;
  
  memset(c, 0, sizeof(c)); // array c has 

  q.push(begin); c[begin] = 1; // normal direction
  q.push(end); c[end] = -1; // reverse direction

  while (!q.empty()) {
    int here = q.front();
    q.pop();
    int top[4] = { -1, -1, -1, -1 };
    cout << "here: " << here << ", c[here] " << c[here] << endl;
    for (int i = disc-1; i >= 0; i--) {
      top[get(here, i)] = i;
    }
    for (int i = 0; i < 4; i++) {
      if (top[i] != -1) {
        for (int j = 0; j < 4; j++) {
          if (i != j && (top[j] == -1 || top[j] > top[i])) {
            int there = set(here, top[i], j);
            if (c[there] == 0) {
              c[there] = incr(c[here]);
              q.push(there);
            }
            else if (sgn(c[there]) != sgn(c[here]))
              return abs(c[there]) + abs(c[here]) - 1;
          }
        }
      }
    }
  }
  return -1;
}

int bfs(int disc, int begin, int end) {
  if (begin == end) return 0;
  queue<int> q;
  memset(c, -1, sizeof(c));
  q.push(begin);
  c[begin] = 0;
  while (!q.empty()) {
    int here = q.front();
    q.pop();
    int top[4] = { -1, -1, -1, -1 };
    for (int i = disc-1; i >= 0; --i) {
      top[get(here, i)] = i; // current top of this pole
      for (int i = 0; i < 4; i++) {
        if (top[i] != -1) { 
          for (int j = 0; j < 4; j++) {
            if (i != j && (top[j] == -1 || top[j] > top[i])) {
              int there = set(here, top[i], j);
              if (c[there] != -1) continue;
              c[there] = c[here] + 1;
              if (there == end) return c[there];
              q.push(there);
            }
          }
        }
      }
    }
  }
  return -1; 
}

int main() {
  int test;
  cin >> test;
  while (test-- > 0) {
    int inputSize[4];
    int inputArray[4][12];
    int outputSize[4];
    int outputArray[4][12];
 
    int num;
    cin >> num;
    int beginVal = 0, endVal = 0;

    for (int pole = 0 ; pole < 4 ; pole++) 
    {
      cin >> inputSize[pole]; 

      for (int j = 0; j < inputSize[pole]; j++) 
      {
        cin >> inputArray[pole][j];
        cout << "index: " << inputArray[pole][j] << "," << pole << endl;
        beginVal = set(beginVal, inputArray[pole][j]-1, pole);
      }

    }
    cout << "input " << beginVal << endl;

    // with this info, what can you do more?

    for (int i = 0 ; i < 4 ; i++) 
    {
      cin >> outputSize[i];

      for (int j = 0; j < outputSize[i]; j++) 
      {
        cin >> outputArray[i][j];
        endVal = set(endVal, outputArray[i][j]-1, i);
      }
    }
    cout << "output " << endVal << endl;
    int ret = bidir(num, beginVal, endVal);
    cout << "ret: " << ret << endl;
  }  
  return 0;
}
