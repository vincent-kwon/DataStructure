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

int getMax(int startIndex, int endIndex) 
{
  int ret = 0;

  if (endIndex < 0 || !(startIndex < endIndex))
    return 0;

  // if selected, then endIndex should matching one
  int toSearch = sum[endIndex];
  cout << toSearch << endl;
  int nextIndex = -1;

  for (int i = endIndex-1; i >= startIndex; i--) 
  {
    if (sum[i] == toSearch) {
      nextIndex = i;      
      break;
    }
  }
 
  if (!(startIndex < nextIndex))

  int maxval =  max (getMax(startIndex, endIndex-1), getMax(startIndex, nextIndex) + 1);
  cout << "Next Index: " << nextIndex << " for "  << toSearch << " maxval : " << maxval << endl;
  return maxval;
}

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

  int ret = getMax(0, N-1);
  
  cout << "max: " << ret << endl;
  return 0;
}

