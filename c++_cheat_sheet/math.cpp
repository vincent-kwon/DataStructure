/*
 * =====================================================================================
 *
 *       Filename:  math.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/19/2015 01:24:56 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <math.h>

using namespace std;

int main() {
  int i = 100;
  double d = 1.3;
  cout<<"floor: "<<floor(d)<<endl;
  cout<<"ceil: "<<ceil(d)<<endl;
  cout<<log2(8)<<endl;
  cout<<log10(1000)<<endl;
  cout<<pow(2, 10)<<endl;
  cout<<sqrt(100)<<endl;
}
