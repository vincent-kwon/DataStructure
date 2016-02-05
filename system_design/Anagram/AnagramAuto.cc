/*
 * =====================================================================================
 *
 *       Filename:  Anagram.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/05/2016 01:10:14 PM
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
#include <map>

using namespace std;

bool isAnagram(string s1, string s2) {
  stringstream ss; 
  map<char, int> hm;

  for (int i = 0; i < s1.size(); i++) {
    char c = s1.at(i);
    auto itor = hm.find(c);
    if (itor == hm.end()) hm[c] = 1;
    else hm[c]++;
  }

  for (int i = 0; i < s2.size(); i++) {
    char c = s2.at(i);
    auto itor = hm.find(c);
    if (itor == hm.end()) return false;
    else {  
      hm[c]--;
      if (hm[c] == 0) hm.erase(c);
    }
  }

  if (hm.empty()) return true;
  else return false;
}

int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;
  cout << isAnagram(s1, s2) << endl;
  return 1;
}
