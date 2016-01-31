/*
 * =====================================================================================
 *
 *       Filename:  1_1_uniq_char_string.cpp
 *
 *    Description:  Assume input fits in 1 byte; thus,  256
 *
 *        Version:  1.0
 *        Created:  04/02/2015 06:32:55 AM
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

using namespace std;
// bool hash
bool isUniqueChar2B(string str) {
  //assume ascii, 48 0-9 65 a, 97 A
  if (str.size() > 256) 
    return false;
  
  bool hash[256]; 
  
  for (int i = 0; i <= 255; i++) {
    hash[i] = false; 
  }

  for (int i = 0; i < str.size(); i++) {
    if (hash[str.at(i)]) {
      return false;
    }
    else {
      hash[str.at(i)] = true;
    }
  }
  return true;
}

// sort string chars
bool isUniqueChar2A(string s) {
  if (s.size() > 256) 
    return false;
  char last = s.at(0);
  sort(s.begin(), s.end());
  for (int i = 1 ; i < s.size(); i++) {
    if (s.at(i) == last) 
      return false;
    else 
      last = s.at(i);
  }  
  return true;
}

int main() {
  string s = "abcdefghijklmnpqrstu";
  if (isUniqueChar2B(s))
    cout<<"Unique"<<endl;
  else
    cout<<"Not unique"<<endl;
  return EXIT_SUCCESS;
}
