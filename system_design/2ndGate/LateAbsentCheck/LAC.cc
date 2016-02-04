/*
 * =====================================================================================
 *
 *       Filename:  LAC.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/30/2016 06:59:47 PM
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
#include <algorithm>

using namespace std;

vector<string> v;

int getCount(int day) 
{
  int val = 0;

  if (day == 1) 
  {
    v.push_back("L");
    v.push_back("A");
    v.push_back("N");
    return 3; // L and C
  } 
  else if (day == 2) 
  {
    int prev = getCount(day-1);
    vector<string>::iterator itor = v.begin();
    for (int i = 0; i < size; i++) 
    {
      string s = v.at(0);
      v.erase(v.begin());
      v.push_back("L" + s);
      v.push_back("A" + s);
      v.push_back("N" + s);
      val += prev * 3;
    }
    return val;
  } 
  else if (day == 3) 
  {
    int pprev = getCount(day-2);
    int prev = getCount(day-1);
    vector<string>::iterator itor = v.begin();
    for (int i = 0; i < size; i++) 
    {
      string s = v.at(0);
      v.erase(v.begin());
      string s_new = "L" + s;
      if (s_new != "LLL")
        v.push_back(s_new);
      s_new = "A" + s
      v.push_back(s_new);
      s_new = "N" + s;
      v.push_back(s_new);
      val += prev * 26;
    }
    return val;
  } 
  else if (day > 3) 
  {
    // L * L * A * p(n-3);
    // L * L * N * p(n-3);
    int prev = getCount(day-1);
    int pprev = getCount(day-2);
    int ppprev = getCount(day-3);
    int size = v.size();

    vector<string>::iterator itor = v.begin();

    for (int i = 0; i < size; i++) 
    {
      string s = v.at(0);
      v.erase(v.begin());
      // N * p(n-1);
      // A * p(n-1);
      // L * A * P(n-2);
      // L * N * p(n-2);
      // L * L * A * p(n-3);
      // L * L * N * p(n-3);
    }
    return val;
  }
}

int main() 
{
  cout << getCount(3) << endl;
  for_each(v.begin(), v.end(), [](string& s) {
    cout << s << endl;
  });  
  return 1;
}
