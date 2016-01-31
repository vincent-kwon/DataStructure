/*
 * =====================================================================================
 *
 *       Filename:  5_1_bit.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/06/2015 08:05:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 *       Remember:  int (X) => unsigned int
 *                  sstream
 *                  pow
 *                  mask creation
 * =====================================================================================
 */

#include <iostream>
#include <math.h>
#include <sstream>

using namespace std;

unsigned int convertBinary(string s) {
  int size = s.size();
  unsigned int retValue = 0;
  for (int i = 0; i < size; i++) {
    char value = s.at(size - 1 - i);
    if (value == '0') 
      continue;
    else if (value == '1') {
      retValue += pow(2, i);
    }
  } 
  return retValue;
}

string convertString(unsigned int i) {
  string rs = "";
  
  while (true) {
    unsigned int d = i / 2;
    unsigned int m = i % 2;
    
    stringstream ss;
    ss << m << rs;
    rs = ss.str();
    if (d != 0) {
      i = d;
    } 
    else {
      break;
    }  
  }
  return rs;
}

int problem_5_1() {
  int j = 6;
  int i = 2;
  string sN,sM;
  cout<<"input N"<<endl;
  cin>>sN;
  cout<<"input M"<<endl;
  cin>>sM;
  
  unsigned int N = convertBinary(sN);
  unsigned int M = convertBinary(sM);

  unsigned int topMask = ~0;
  topMask = topMask << (j+1);
  unsigned int bottomMask = (1 << i) - 1;
  unsigned int fullMask = topMask | bottomMask;
  string maskStr = convertString(fullMask);
  cout<<"Mask:"<<maskStr<<endl;
  N = N & fullMask;
  unsigned int M2 = M;
  unsigned int M2_len = 0;
  while (M2 != 0) {
    M2_len++;
    M2 = M2 >> 1;
  }
  int diff = j - (M2_len - 1);
  M = M << diff;

  N = N | M;

  string sr = convertString(N);
  cout<<"Result:"<<sr<<endl;
  return 0;
  //length - 1 is current index, j is to be index, to_be_index - current_index => # of shift needed
}

int problem_5_2() {
  cout<<"input 0.0 ~ 1.0 "<<endl;
  double d;
  cin>>d;
  cout<<d<<endl;
  if (d == 1.0 || d == 0.0) {
    cout<<d<<endl;
    return 0;
  }
  string resultValue = "0.";

  while (true) {
    if (d == 0) 
      break;
    d = d * 2;
    
    if (d >= 1.0) {
      double d_extra = d - 1.0;
      stringstream ss;
      cout<<"next:"<<d_extra;
      ss << resultValue << 1;
      resultValue = ss.str();
      d = d_extra;
    } 
    else {
      stringstream ss;
      ss << resultValue << 0;
      resultValue = ss.str();
    }
  }
  cout<<"result:"<<resultValue<<endl;
  return 0;
}

int problem_5_3() {
  // start next
  int n;
  cout<<"input number: "<<endl;
  cin>>n;
  int c = n;
  int c0 = 0;
  int c1 = 0;
  // 0 with following 1
  while (((c & 1)==0) && (c != 0)) {
    c0++;
    c >>= 1;
  }

  while ((c & 1) == 1) {
    c1++;
    c >>= 1;
  }
  
  if (c0 + c1 == 31 || c0 + c1 == 0) { // TODO: Need to 111000 which can't have next num 01 => 10 is next num
    return -1;
  }

  int p = c0 + c1; 

  n |= (1 << p);
  n &= ~((1 << p) - 1);
  n |= (1 << (c1 - 1)) - 1;
  cout<<"next: "<<n<<endl;

  // start prev
  int temp = n;
  c0 = 0;
  c1 = 0;

  while ((temp & 1) == 1) {
    c1++;
    temp >>= 1;
  }

  if (temp == 0) return -1;
  
  while ((temp & 1) == 0 && (temp != 0)) {
    c0++;
    temp >>= 1;
  }

  p = c0 + c1;
  n &= ((~0) << (p + 1));

  int mask = (1 << (c1 + 1)) - 1;
  n |= mask << (c0 -1);
  return 0;
}

int main() {
  //problem_5_1();
  //problem_5_2();
  problem_5_3();
}
