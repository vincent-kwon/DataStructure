/*
 * =====================================================================================
 *
 *       Filename:  real_test_0315.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/19/2015 06:41:20 PM
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
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector< set<int> > finals;

// recursion 
void getAllSubsetsR(vector<int> &v, int start, set<int> resultSet) {

  if (start >= v.size()) {
    finals.push_back(resultSet);
    return;
  }

  for (int i = start; i < v.size(); i++) {
    resultSet.insert(v[i]);
    getAllSubsetsR(v, i + 1, resultSet); 
    resultSet.erase(v[i]);
  }
}

// nested for loop
void getAllSubsets() {
  vector<int> v;
  v.push_back(1);
  v.push_back(3);
  v.push_back(22);
  v.push_back(4);

  sort(v.begin(), v.end());

  //from 1st, can go
  cout<<"all sets:"<<endl;
  for (int i = 0 ; i < v.size(); i++) {
    set<int> threeSome;
    threeSome.insert(v[i]);
    for (int j = i + 1; j < v.size(); j++) {
      threeSome.insert(v[j]);
      for (int k = j + 1; k < v.size(); k++) {
        threeSome.insert(v[k]);
        set<int>::iterator itor = threeSome.begin();
        for (itor ; itor != threeSome.end(); itor++) {
          cout<<*itor<<" ";
        }
        cout<<""<<endl;
        threeSome.erase(v[k]);
      }    
      threeSome.erase(v[j]);
    }
    threeSome.erase(v[i]); 
  } 
}

int main() {
  int T;
  vector<int> m;
  m.push_back(1);
  m.push_back(2);
  m.push_back(3);
  m.push_back(4);
  set<int> st;

  getAllSubsetsR(m, 0, st);
  vector< set<int> >::iterator itorFinals = finals.begin();
  for (itorFinals; itorFinals != finals.end(); itorFinals++) {
    set<int> it = *itorFinals;
    set<int>::iterator itorSets = it.begin();
    for (itorSets; itorSets != it.end(); itorSets++) { 
      cout<<*itorSets<<",";
    }
    cout<<"next:"<<endl;
  }

  getAllSubsets();
}
