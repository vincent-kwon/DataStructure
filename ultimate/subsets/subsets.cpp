#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
/*
 * print subsets
 */
int M[300];
//int H;
//int W;

int C;

void realPrint(vector< vector<int> >& result) {
  vector< vector<int> >::iterator itor = result.begin();
  for (itor; itor != result.end(); itor++) {
    vector<int> v = *itor;

    vector<int>::iterator itor2 = v.begin();
 
    cout << "{ ";
    for (itor2; itor2 != v.end(); itor2++) {
      cout << *itor2 << "," ;
    }
    cout << " } " << endl;
  }
}

void printSubset(int len, int current, vector< vector<int> >& result) {
  if (current == len) {
    // no further
    vector<int> v;
    result.push_back(v);
    return;
  }

  printSubset(len, current + 1, result);
  
  int currentValue = M[current];

  vector< vector<int> >::iterator itor = result.begin();

  int size = result.size();

  cout << " "  << endl;

  for (int i = 0; i < size; i++) {
     vector<int> v = result[i];
     v.push_back(currentValue);
     result.push_back(v);
  }

  realPrint(result);
}

int main() {
  int test;
  int i,j,k;

  scanf("%d", &test);
  while (test-- > 0) {
    scanf("%d" , &C);      
    for (i = 0; i < C; i++) {
        scanf("%d", &M[i]);
        cout << M[i] << endl;
    }
    vector< vector<int> > result;
    printSubset(C, 0, result);
  }
}
