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
double b[MAX_WORDS+1];
double n[MAX_WORDS+1][MAX_WORDS+1];
double r[MAX_WORDS+1][MAX_WORDS+1];
bool bruteForce = false;
string wordStr[MAX_WORDS+1];
string p[MAX_WORDS+1];
double gMax = 0;
int choice[102][502];
double cache[102][502];

int getIndex(string s) {
  for (int i = 0; i < words; i++) {
    if (wordStr[i] == s) return i;
  }
  return -1;
}

int getIndex2(string s) {
  for (int i = 1; i <= words; i++) {
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

string corpus[501];

string reconstruct(int segment, int previousMatch) { // seg 1, 2, 3, 4
  int choose = choice[segment][previousMatch];
  string ret = wordStr[choose];
  cout << "seg: " << segment << "choose: " << choose << ", ret: " << ret << ", prevMatch : " << previousMatch << ", given: " << given << endl;
  if (segment < given)
    ret = ret + " " + reconstruct(segment+1, choose);
  return ret;
}

double recognize(int segment, int previousMatch) {
  //cout << "rec: " << segment << "," << previousMatch << "," << given << endl;
  if (segment == (given+1)) return 0;

  double &ret = cache[segment][previousMatch];

  if (ret != 1.0) {
    cout << "cached: " << segment << "," << previousMatch << endl;
    return ret;
  }

  ret = -1e200;

  int& choose = choice[segment][previousMatch]; // for reference variable set

  for (int thisMatch = 1; thisMatch <= words; ++thisMatch) {
    double cand = n[previousMatch][thisMatch] // segment 1, previousMatch I 0
                 + r[thisMatch][getIndex2(p[segment])]   // ok 
                 + recognize(segment+1, thisMatch); // 1,I or 1,am or 1,a or 1,boy or 1,buy <== index current no

    if (ret < cand) {
      ret = cand;
      choose = thisMatch; // this saves max value for segment, prevMatch. For example 1-I, choose[1][0] = next value;   
      cout << "[cand] " << cand << ", [seg] " << segment << ", [c] " << choose << ", [p] " << previousMatch << endl;
    }
  }
  return ret;
}

int main() {   
  cin >> words;
  cin >> tests;

  if (bruteForce) {
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
      cin >> p[i];

    vector<string> v;
    getMaxStrBF(0, given, v, 1.0);
  }
  else {
    for (int i = 0; i < 102; i++) {
      for (int j = 0; j < 502; j++) {
        cache[i][j] = 1;
        choice[i][j] = -1;
      }
    }
 
    for (int i = 1; i <= words; i++) {
      cin >> wordStr[i];
    }

    for (int i = 1; i <= words; i++)
      cin >> b[i];

    for (int i = 1; i <= words; i++)
      for (int j = 1; j <= words; j++) 
        cin >> n[i][j];

    for (int i = 1; i <= words; i++) 
      n[0][i] = b[i]; // imaginary word 0-i probability

    for (int i = 1; i <= words; i++)
      for (int j = 1; j <= words; j++) 
        cin >> r[i][j];
    
    cin >> given; 

    for (int i = 1; i <= given; i++) {
      cin >> p[i];
      //cout << p[i];
    }
     
    double r = recognize(1, 0);
    string result = reconstruct(1,0);
    cout << result << endl;
  }

  return 0;
}
