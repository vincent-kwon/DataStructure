/*
 * =====================================================================================
 *
 *       Filename:  1_3_anagram.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/02/2015 10:00:29 AM
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

bool anagramCheck(string str1, string str2) {
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());

  if (str1 == str2)
    return true;
  else 
    return false;
}

int main() {
  if (anagramCheck("hello", "llejo"))
    cout<<"anagram"<<endl;
  else
    cout<<"no anagram"<<endl;
}
