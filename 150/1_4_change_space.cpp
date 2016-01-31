/*
 * =====================================================================================
 *
 *       Filename:  1_4_change_space.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/02/2015 10:07:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

void replace_spaces(string str) {
  int len = str.size();
  int count = 0;
  for (int i = 0 ; i < len ; i++) {
    if (str.at(i) == ' ')
      ++count;
  }
  str.append(2*count, ' ');
  int new_len = str.size();
  for (int i = len - 1; i >= 0 ; i--) {
    if (str.at(i) != ' ') {
      str.at(new_len - 1) = str.at(i);
      new_len--; 
    }
    else {
      str.at(new_len - 1) = '0';
      str.at(new_len - 2) = '2';
      str.at(new_len - 3) = '%';
      new_len = new_len - 3;
    }
  }
  cout<<str<<endl;
}

int main() {
  string str = "h e l l o";
  replace_spaces(str);
}
