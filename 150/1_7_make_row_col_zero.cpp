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

void makeone(vector< vector<int> >&v, vector< std::pair<int,int> > &p) {
  
  vector< std::pair<int, int> >::iterator itor = p.begin();
 
  for (itor ; itor != p.end(); itor++) {
    std::pair<int, int> nextPoint = *itor;

    for (int i = 0; i < v.size(); i++) {
      v[nextPoint.first][i] = 1;
    }
    for (int i = 0; i < v.size(); i++) {
      v[i][nextPoint.second] = 1;
    }
  }

  for (int i = 0 ; i < v.size() ; i++) {
    for (int j = 0 ; j < v.size() ; j++) {
      cout<<v[i][j]<<" " ;
    }
    cout<<""<<endl;
  }
}

int main()  {
  int n;
  cin>>n;
  vector< vector<int> > v(n, vector<int>(n, 0)); 
  vector< std::pair<int, int> > points;

  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j < n; j++) {
      if (i == j && i % 2) {
        v[i][j] = 1;
        points.push_back(make_pair(i,j));
      }
      else 
        v[i][j] = 0;
      cout<<v[i][j]<<" " ;
    }
    cout<<""<<endl;
  }
  makeone(v, points);
  return 0;
}
