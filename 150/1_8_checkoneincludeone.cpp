/*
 * =====================================================================================
 *
 *       Filename:  1_8_checkoneincludeone.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/02/2015 09:58:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int main() {
  string s1;
  string s2;

  cin>>s1;
  cin>>s2;

  if (s2.find(s1) != string::npos) 
    cout<<"include"<<endl;
  else
    cout<<"not include"<<endl;
}
