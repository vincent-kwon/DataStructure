/*
 * =====================================================================================
 *
 *       Filename:  stl_map.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/19/2015 12:03:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

struct comp {
  bool operator() (const int left, const int right) const 
  {return left>right;} // 여기서는 left>right 즉, 왼쪽이 더 크도록 정의했습니다. 내림차순으로 정렬해보는 것이죠. 
}; 

int main () 
{ 
  map<int,int,comp> data; 
  data[2]=100; 
  data[1]=4;  
  data[3]=150; 

  //sort by key
  map<int, int, comp>::const_iterator it;// 
  for(it = data.begin(); it!= data.end(); it++){ 
    cout << it->first <<" "<<it->second << endl; 
  }

  it = data.find(2);
  
  if (it != data.end()) {
    cout<<it->first<<","<<it->second<<endl;
  }
  //sort by value 
  return 0;
}

