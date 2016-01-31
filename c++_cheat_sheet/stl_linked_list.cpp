/*
 * =====================================================================================
 *
 *       Filename:  stl_linked_list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/18/2015 11:47:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <sys/time.h>
#include <iostream>

using namespace std;

int main() {
  srand(time(NULL));
  list<int> l;
  for (int i = 0; i < 10 ; i++) {
    int i = rand() % 100;
    l.push_front(i);
  }

  /* algorithm sort is available to only [] ones */
  sort(l.begin(), l.end());
  l.sort();

  list<int>::iterator itor = l.begin();
  for (auto& v : l) {
    cout<<v<<endl;
  }
  return 0;
}
