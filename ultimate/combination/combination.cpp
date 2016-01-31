#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
/*
 * From given start point (r,c), and end point to a matrix filled with values,
 * find maximum sum of area must start from start point. End can't be bigger than
 * end point.
 *
 * 
 */
int M[300];
int V[300] = {0,};

int C;
int S;

void combination(int C, int S, int curLen, int startIndex, vector<int> v) {
  if (S == curLen) {
    vector<int>::iterator itor = v.begin();
    for (itor; itor != v.end(); itor++) {
      cout << *itor << ", ";
    }
    cout << " " << endl;
    return;
  }

  for (int i = startIndex; i < C; i++) {
    if (V[i] == 0) {
      v.push_back(M[i]);
      V[i] = 1; //disable this value;
      combination(C,S, curLen+1, i, v);
      v.pop_back(); //remove after finished; 
      V[i] = 0;
    }
  }
}

int main() {
  int test;
  int i,j,k;

  scanf("%d", &test);
  while (test-- > 0) {
    scanf("%d %d", &C,&S);      
    for (i = 0; i < C; i++) {
      scanf("%d", &M[i]);
    }
    vector<int> v;
    combination(C,S,0,0, v);
  }
}
