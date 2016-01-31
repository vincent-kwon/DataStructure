/*
 * =====================================================================================
 *
 *       Filename:  file.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/19/2015 02:01:12 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  //read by type: char, int, long....
  ifstream infile("a.txt", ios_base::in);
  while(infile.eof() != true) {
    char c;
    infile>>c;
    cout<<c<<endl;
  }
  //read by line: 
  cout<<"now seekg..."<<endl; 
  //jumping around seek and tell
  infile.seekg(ios_base::beg);
  ios_base::streampos curPos = infile.tellg();
  if (curPos == ios_base::beg)
    cout<<"we are the beginning:ok"<<curPos<<endl;
 
  infile.seekg(ios_base::end);
  curPos = infile.tellg();
  
  if (curPos == ios_base::beg)
    cout<<"we are the beginning:not ok"<<curPos<<endl;
  
  char c2;
  infile>>c2;
  cout<<c2<<endl;
  return 0;
}

