/*
 * =====================================================================================
 *
 *       Filename:  pascal_triangle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/15/2015 10:33:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;

  cin >> n;

  int numPerLine = 1;
  int cum = 0;
  vector<int> v;

  v.resize(n);

  // 0 
  v[0] = 1;
  cout << v[0] << endl;
  numPerLine++;
  
  // 1, 2, 3, 4, 5 ...
  for (int i = 1; i < n ; i++) {
    cum++;
    
    if (cum == 1) {
      // has only right parent 
      v[i] =  v[i - numPerLine + 1];
      cout << v[i] << " ";  
      continue;
    }

    else if (cum < numPerLine) {
      // has only left parent
      v[i] = v[i - numPerLine] + v[i - numPerLine + 1];  
      cout << v[i] << " ";  
      continue; 
    }

    else {
      v[i] = v[i - numPerLine];
      cout << v[i] << " ";  

      cum = 0;
      numPerLine++;
      cout << " " << endl;
    }        
  }
  return 0;
}
