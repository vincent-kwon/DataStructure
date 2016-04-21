/*
 * =====================================================================================
 *
 *       Filename:  christmas_doll.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/21/2016 06:50:52 AM
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

int N = 6;
int K = 4;

int box[100] = {0, };
int sum[100] = {0, };

int main() 
{
  for (int i = 0; i < N; i++) 
  {
    cin >> box[i];
    sum[i] = (box[i] + (i==0?0:sum[i-1])) % K;
    cout<< sum[i] << endl;
  }

  int count = 0; 
  for (int i = 0; i < N; i++) 
  {
    for (int j = i+1; j < N; j++) 
    {
      if (sum[i] == sum[j]) count++;
    }
  } 

  cout << "count: " << count << endl;
  // print all feasibility

  // print biggest possible
  
  return 0;
}

