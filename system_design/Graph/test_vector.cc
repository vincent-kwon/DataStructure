/*
 * =====================================================================================
 *
 *       Filename:  test_vector.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/06/2016 11:27:05 PM
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
#include <queue>

class TestObj 
{
 public: 
  TestObj() { };
  int get_num () { return 1000 ; }
};

using namespace std;

int main() 
{
  vector<TestObj> v;
  queue<TestObj> q;

  for (int i = 0 ; i < 3600000; i++)
  {
    TestObj to; 
    q.push(to);
    v.push_back(to);
    if (!i%10000) q.pop();
  }
  cout << v.size() << endl;
  return 0;
}
