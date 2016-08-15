/*
 * =====================================================================================
 *
 *       Filename:  OpticalCharacterRecognition.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/15/2016 06:58:18 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 *  f(Q) = P(R|Q) * P(Q)
 *  P(R|Q) = i=0 to n-1,  m(Q[i], R[i]);
 *  P(Q) = i=0 to n-1, t(Q[i-1], Q[i]);
 *
 *  I game
 *     I   am   game
 *  I  10  90   70
 *  am 70  1    60
 *  ga 1   1    1
 *
 *      I  am   ga
 *  I   1  1    1
 *  am  1  1    10        
 *  ga  1  50   20
 *
 *  I game vs. I am
 *
 *  70 * 20 Vs. 90 * 50 = 1400 vs 4500
 *
 *  M(Q[i], R[i]) orginal Q, return R possibility
 *
 * I,am,game => I
 * I,am,game => game
 *
 * I I 
 * I am
 * I game
 * am I
 * am am
 * am game
 * game I
 * game am
 * game game 
 *
 * Dynamic Programming?
 *
 * I game am
 *
 * => 
 *
 * I 
 * game 
 * am 
 *
 * all individual calculation
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

#define MAX_WORDS 10

int words, tests, given;
double b[MAX_WORDS];
double n[MAX_WORDS][MAX_WORDS];
double r[MAX_WORDS][MAX_WORDS];
bool bruteForce = false;
string wordStr[MAX_WORDS];
string p[MAX_WORDS];
double gMax = 0;

int getIndex(string s) {
  for (int i = 0; i < words; i++) {
    if (wordStr[i] == s) return i;
  }
  return -1;
}

double getMaxStrBF(int index, int maxIndex, vector<string> v, double accum) {
  double prcd;
  double mist;

  if (index == maxIndex) {
    if (accum > gMax) {
      for (int i = 0; i < v.size() ; i++) 
        cout << v[i] << " ";
      cout << " " << accum << endl;
      gMax = accum;
    }
    return 1.0;
  }

  int mIndex = getIndex(p[index]); // matrix index

  for (int i = 0 ; i < words; i++) {

    mist = r[i][mIndex];

    if (index == 0) {
      prcd = b[i];
    }
    else {
      int prev_mIndex = getIndex(v[v.size()-1]);
      prcd = n[prev_mIndex][i];
    }

    v.push_back(wordStr[i]);
    getMaxStrBF(index+1, maxIndex, v, prcd+mist+accum);
    v.pop_back();
  }
  return 1.0;
}

int main() {   
  cin >> words;
  cin >> tests;

  for (int i = 0; i < words; i++)
    cin >> wordStr[i];

  for (int i = 0; i < words; i++)
    cin >> b[i];

  for (int i = 0; i < words; i++)
    for (int j = 0; j < words; j++) 
      cin >> n[i][j];

  for (int i = 0; i < words; i++)
    for (int j = 0; j < words; j++) 
      cin >> r[i][j];

  cin >> given; 

  for (int i = 0; i < given; i++)
  {
    cin >> p[i];
    //cout << str[i];
  }

  if (bruteForce) {
    vector<string> v;
    getMaxStrBF(0,given, v, 1.0);
  }

  vector<string> results;
  
  //cout << "r: " << results << endl;
  return 0;
}
