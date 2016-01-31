/*
 * =====================================================================================
 *
 *       Filename:  stl_string.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/19/2015 12:28:20 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

int main() {
  //string major functions.
  string s = "1234567";
  cout<<"size:"<<s.size()<<endl;
  cout<<s.at(1)<<endl;
  cout<<s.substr(1, 5)<<endl;
  cout<<s.find("4")<<endl;
  int pos = s.find("4", 6);
  if (pos == string::npos)
    cout<<"no position"<<endl;
  s.append("8");
  cout<<s<<endl;
  cout<<s.c_str()<<endl;

  //int to string
  char str_ptr[10];
  sprintf(str_ptr, "%d", 1000);
  cout<<"int to strPtr: "<<str_ptr<<endl;
  string s3(str_ptr);
  cout<<"string from strPtr: "<<s3<<endl;
  int int_val = atoi(str_ptr);
  cout<<"atoi: "<<int_val<<endl;
}
