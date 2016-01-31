/*
 * =====================================================================================
 *
 *       Filename:  gray_code.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/15/2015 08:32:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> get_gray (int n) {

  if (n == 1) {
    vector<string> r;
    r.push_back("0");
    r.push_back("1");
    return r;
  }
  vector<string> prev_gray = get_gray(n-1); 
  vector<string> result;
  vector<string>::iterator itor = prev_gray.begin();

  for (itor; itor != prev_gray.end(); itor++) {
    stringstream ss;
    ss << 0 << *itor;
    result.push_back(ss.str());
  }

  vector<string>::reverse_iterator ritor = prev_gray.rbegin();

  for (ritor; ritor != prev_gray.rend(); ritor++) {
    stringstream ss;
    ss << 1 << *ritor;
    result.push_back(ss.str());
  }

  return result;  
}

void printNode(string & str) {
  cout << str << endl;
}

int main() {
  int  n;

  cin >> n ; 

  vector<string> r = get_gray (n); 

  for_each(r.begin(), r.end(), printNode);
}
