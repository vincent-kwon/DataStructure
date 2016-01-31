#include <iostream>
#include <limits.h>

using namespace std;

char v[200][200][200] = {0, };

int getRowCount(char* v, int m) {
  int count = 0;
  int countChar = 0;
  int lastChar = '?';
    
  for (int j = 0; j < m; j++) {
    if (v[j] == lastChar) {
      countChar++;
      continue;
    } 
    else {
      if (lastChar != '?') {
        count += (countChar * (countChar + 1) / 2);
      } 
      lastChar = v[j];
      countChar = 1;
    }
  }  
  
  if (lastChar != '?') {
    count += (countChar * (countChar + 1) / 2);
  }
  return count;
}


int main() {

  int testNum; 
  cin >> testNum;

  while (testNum--) {
    int n, m;
    int count = 0;

    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char  charInput;
        cin >> charInput;
        v[0][i][j] = charInput;
      }

      //after receiving one line perform counting 
      count += getRowCount(v[0][i], m);

      for (int k = 1 ; k <= i ; k++) {
        for (int j = 0 ; j < m ; j++) {
          if (v[k-1][i-1][j] == v[0][i][j]) {
            v[k][i][j] = v[0][i][j];
          } 
          else {
            v[k][i][j] = '?';
          }
        }
        count += getRowCount(v[k][i], m);
      }
    }
    cout << "Test[" << testNum << "] = " << count << endl;
  }
  return 0;
}
