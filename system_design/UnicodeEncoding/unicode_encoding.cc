/*
 * =====================================================================================
 *
 *       Filename:  unicode_encoding.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/25/2016 06:10:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdio.h>
#include <sstream>

char baseMap[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789/=";

unsigned char fetch(unsigned char c, int toFill, unsigned char* fetchedBits) {
  //mask for first n bits
  unsigned char maskFirstN = ~0 << (8-toFill);
  unsigned char maskReverse = ~maskFirstN;
  unsigned char r = c & maskReverse;
  //printf("remaining %d\n", r);
  *fetchedBits = (c & maskFirstN) >> (8-toFill);
  //printf("fetched %d\n", *fetchedBits);
  //printf("c %c\n", *fetchedBits);
  return r;
}

using namespace std;
string encode (string type, string input_str) 
{
  string encoded = ""; 

  if (type == "base64") 
  {
    int len = input_str.size();
    int toFill = 6; 
    unsigned char remainingBits;
    unsigned char nextChar = 0; 
    unsigned char fetchedBits; // initialize baseChar with 0

    for (int i = 0; i < len; i++) 
    {
      if (toFill == 6) 
      {
        // get 6 
        remainingBits = fetch(input_str.at(i), toFill, &fetchedBits);
        encoded.append(1, baseMap[fetchedBits]);  
        // fill 2
        nextChar = remainingBits << 4;
        toFill = 4;
       
      }
      else if (toFill == 4) 
      {
        // get 4
        remainingBits = fetch(input_str.at(i), toFill, &fetchedBits);
        nextChar = nextChar | fetchedBits;
        encoded.append(1, baseMap[nextChar]);
        // fill 4
        nextChar = remainingBits << 2;
        toFill = 2;
      }
      else if (toFill == 2) 
      {
        // get 2
        remainingBits = fetch(input_str.at(i), toFill, &fetchedBits);
        nextChar = nextChar | fetchedBits;
        encoded.append(1, baseMap[nextChar]);
        // fill 6
        nextChar = remainingBits;
        encoded.append(1, baseMap[nextChar]);
        // set toFill 6 and clear nextChar
        toFill = 6;
        nextChar = 0;
      }
    }
    
    if (toFill != 6) 
    {
      encoded += baseMap[nextChar];
    }
  }
  return encoded;
};

using namespace std;
string decode (string type, string input_str) 
{
  string encoded = ""; 

  if (type == "base64") 
  {
    int len = input_str.size();
    int toFill = 8; 
    unsigned char nextChar = 0; 

    for (int i = 0; i < len; i++) 
    {
      // get bits from encoded char 
      char c = input_str.at(i);
      unsigned char bits;
      for (int j = 0 ; j < 64; j++) {
        if (baseMap[j] == c) {
          bits = j;
          break;
        }
      }

      if (toFill >= 6) {
        nextChar = nextChar | (bits << (toFill - 6));
        if (toFill == 6) {
          encoded.append(1, nextChar);
          toFill = 8; // 6 - 6;
          nextChar = 0;
        }
        else {
          toFill = 2; // 8 - 6;
        }
      } 
      else 
      {
        nextChar = nextChar | (bits >> (6 - toFill)); 
        encoded.append(1, nextChar);
        int remaining = 6 - toFill;
        nextChar = bits << (8 - remaining);
        toFill = 8 - remaining; 
      }
    }
    if (toFill != 8) {
      encoded.append(1, nextChar);
    }
  }
  return encoded;
};

int main() {
  char bit = 1;
 
  for (int i = 0; i < 8 ; i++) {
    char tmp = (bit << i);
    printf("%d, ", tmp);
    printf("%X\n", tmp);
   
    char padding = 1; 
    
    printf("%d, ", tmp | padding);
    printf("%X\n", tmp | padding);
  }

  // count 1 in a num
  int count = 0;
  unsigned char num = 128 | (1 << 0);
  num = num | (1 << 1);
  num = num | (1 << 3);

  for (int i = 0; i < 8; i++) {
     int tmp = num >> i;
     unsigned char firstBitMask = 1; 

     if (tmp & firstBitMask)
       count++;
  }

  cout << "count: " << count << endl;
  // if it is not known which bit computer
  
  count = 0;

  unsigned int flag = 1;
 
  while (flag) {
    if (num & flag)
      count++;
    flag = flag << 1;
  }  

  cout << "inifinate: " << count << endl;


  cout << "make binary representation of 3.25" << endl;

  int num2 = 7;
  string result = "";

  while (num2) 
  {
    int modVal = num2 % 2;
    int divVal = num2 / 2;
    num2 = divVal;
    stringstream s("");
    s << modVal;
    result = s.str() + result;
  }

  cout << "111? " << result << endl;

  cout << ". ???? " << endl; 

  double decPart = 0.625; 

  string s2 = "";
  
  while (decPart > 0) {
    stringstream ss("");

    if (s2.size() > 32) {
      cout << "Error: " << endl;
    }

    if (decPart == 1) {
      ss << decPart ;
      s2 = s2 + ss.str();      
      break;
    }

    double r = decPart * 2;

    if (r >= 1) {
      ss << 1;
      s2 = s2 + ss.str();
      decPart = r - 1; 
    } else {
      ss << 0;
      s2 = s2 + ss.str();
      decPart = r;
    }
  }

  cout << s2 << endl;

  // swap even and odd number
  
  // base64 encoding 
  string s3 = "AB01";

  // get 6bit from the beginning
  printf ("A: %d \n", s3.at(0));
  printf ("B: %d \n", s3.at(1));
  printf ("0: %d \n", s3.at(2));
  printf ("1: %d \n", s3.at(3));
  unsigned char c1 = s3.at(0);

  // how to print values bit representation? 
  unsigned char mask1 = 1;
  string s4 = "";
  while (mask1) {
    stringstream ss(""); 

    if (mask1 & c1) {
       ss << 1 << s4;
    }
    else {
       ss << 0 << s4;
    }
    s4 = ss.str();

    cout << " :" << s4 << ": " << endl;
    mask1 = mask1 << 1;
  }
 
  cout << "01000001 (48) " << s4 << endl;

  // read first 
  string e_str = encode("base64", "abc123ZYX#$");
  cout << "original: abc123ZYX#$" << endl;
  //string e_str = encode("base64", "A");
  cout << "encoded: " << e_str << endl;
  string d_str = decode("base64", e_str);
  cout << "decoded: " << d_str << endl;
  return 1;
}
