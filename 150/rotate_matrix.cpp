/*
 * =====================================================================================
 *
 *       Filename:  rotate_matrix.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/14/2014 06:01:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <time.h>

using namespace std;

int main() {
  srand(time(NULL)); 
  vector< vector<int> > v(4, vector<int>(4));
  for (int i = 0 ; i < 4 ; i++)
  {
    for (int j = 0 ; j < 4 ; j++)
    {
      v[i][j] = rand() % 10;
      cout<<v[i][j]<<","; 
    }
    cout<<"\n";
  }
}
