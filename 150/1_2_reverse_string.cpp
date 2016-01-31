/*
 * =====================================================================================
 *
 *       Filename:  1_2_reverse_string.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/02/2015 09:25:57 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

void reverse(char *str) {
  //search for \0
  char* end = str;
  char* print_ptr = str;
  char tmp;
  int strlen_value = 0;

  while (*end) {
    end++;
    strlen_value++;
  }
  cout<<"size:"<<strlen_value<<endl;
  --end;

  while (str < end) {
    tmp = *end;
    *end-- = *str;
    *str++ = tmp;
  }  
  cout<<print_ptr<<endl;
}

int main() {
  char str[] = "hello";
  reverse(str);
  return EXIT_SUCCESS;
}
