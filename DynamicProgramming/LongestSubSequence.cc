#include <iostream>
#include <unistd.h>
#include <stdio.h>

using namespace std;

int m[100][100];

int main() 
{
  string s1 = "abec";
  string s2 = "aefdc";

  cout << s1 << endl;
  cout << s2 << endl;

  int maxLen = (s1.size() > s2.size() ? s1.size() : s2.size());

  for (int i = 0; i <= maxLen; i++) 
    for (int j = 0; j <= maxLen; j++)
      m[i][i] = 0;
 
  for (int r = 1; r <= s1.size(); r++) 
  {
    for (int c = 1; c <= s2.size(); c++) 
    {
      if (s1[r-1] == s2[c-1]) 
      {
        m[r][c] = 1 + m[r-1][c-1];
      }
      else 
      {
        m[r][c] = max(m[r-1][c], m[r][c-1]);
      }
    }
  }

  cout << "max: " << m[s1.size()][s2.size()] << endl;

  int r = s1.size();
  int c = s2.size();

  while (!(r == 0 && c ==0)) 
  {
    if (s1[r-1] == s2[c-1]) {
      cout << s1[r-1] << endl;
      r -= 1;
      c -= 1;
    }
    else {
      if (m[r][c] == m[r-1][c]) {
        r -= 1;
      }
      else if (m[r][c] == m[r][c-1]) {
        c -= 1;
      }
      else {
        cout << "bad algorithm.... " << endl;
        return 1; 
      }
    }
  }
  return 0;
}
