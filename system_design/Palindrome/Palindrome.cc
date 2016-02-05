/*
 * =====================================================================================
 *
 *       Filename:  Palindrome.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/05/2016 12:23:11 PM
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

bool isPalindrom(string s) {
  //find medium
  int size = s.size();
  int start = 0;
  int end = size-1;
  while (start < end) {
    if (s.at(start) != s.at(end)) return false;
    else {
      start++;
      end--;
    }
  }
  return true;
}

int main () {
  string s;
  cin >> s ;
  cout << isPalindrom(s) << endl;
}
