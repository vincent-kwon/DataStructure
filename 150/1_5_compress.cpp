/*
 * =====================================================================================
 *
 *       Filename:  1_5_compress.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/02/2015 10:21:43 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int countCompression(string str);

string comparessBetter(string str) {
  int new_len = countCompression(str);
  string new_str = "";
  char last = str.at(0);
  int  count = 1;
  
  if (new_len >= str.size())
    return str;
  else {
    for (int i = 1 ; i < str.size(); i++) {
      if (str.at(i) == last) {
        count++;
      }
      else {
        new_str.append(1, last);
        last = str.at(i);
        stringstream ss;
        ss<<count;
        new_str.append(ss.str());     
        count = 1;  
      }  
    }
    new_str.append(1, last);
    stringstream ss;
    ss<<count;
    new_str.append(ss.str());     
    return new_str;
  }
}

int countCompression(string str) {
  char last = str.at(0);
  int  count = 1;
  int  totalLen = 0;

  for (int i = 1 ; i < str.size(); i++) {
    if (str.at(i) == last) {
      count++;
    }
    else {
      last = str.at(i);
      stringstream ss;
      ss<<count;
      totalLen += 1 + ss.str().size();     
      count = 1;  
    }  
  }
  // since last one is not yet added
  totalLen += 1 + to_string(count).size(); //c+11 to_string
  return totalLen;
}

int main() {
  string str = comparessBetter("abbcccddddaaaa");
  cout<<str<<endl;
  return 0;
}
