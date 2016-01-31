/*
 * =====================================================================================
 *
 *       Filename:  1_6_rotate_matrix.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/02/2015 11:02:59 AM
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

void rotate(vector< vector<int> >&v) {
  
  int n = v[0].size();
  int start = 0;
  int end = n - 1;

  while(start < end) {
    int tmp;
    for (int i = 0; i < end - start ; i++) {
      tmp = v[start][start + i];   
      v[start][start + i] = v[end - i][start];//v[up][start]
      v[end - i][start] = v[end][end - i]; //v[up][start] = v[end][left]
      v[end][end - i] = v[start + i][end]; //v[end][left] = v[down][end]
      v[start + i][end] = tmp;
    }
    ++start;
    --end; 	
  }
  

  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j < n; j++) {
      cout<<v[i][j]<<" " ;
    }
    cout<<""<<endl;
  }
}

int main()  {
  int n;
  cin>>n;
  vector< vector<int> > v(n, vector<int>(n, 0)); 

  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j < n; j++) {
      v[i][j] = i*j;
      cout<<v[i][j]<<" " ;
    }
    cout<<""<<endl;
  }
  rotate(v);
  return 0;
}
