#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int test;
vector<int> v;
vector<vector<int> >all;
bool goNextTest = false;

int main() {
  cin >> test;
  while (test-->0) {
    int fct = 1;
    int i,j,k,m;
    int num;
    int lastIndex;
    int distance = 0;   
    int allCount = 0;
    // initialize and clean up
    all.clear();
    v.clear();
    goNextTest = false;

    cin >> num;
    m = num;
    lastIndex = num - 1;

    // cal factorial
    while (m > 0)
    {
      fct *= m;
      m--;
    }

    // get num
    for (i = 0 ; i < num; i++) {
      cin >> j;
      v.push_back(j);
    }

    // generate one turn flip
    vector<int> ans(v);
 
    sort(ans.begin(), ans.end(), [] (int i, int j) -> bool { if (i <= j) return true; else return false; });
 
    if (v == ans) // vector equal works by == 
    {
      cout << "distance: " << distance << endl;
      break;
    }

    // starting point    
    all.push_back(v);

    while (!all.empty())
    { 
      int allSize = all.size();
      distance++; //iterations

      for (int w = 0 ; w < allSize; w++) 
      {   
        vector<int> vn = all.front();
        all.erase(all.begin(), all.begin()+1);
        cout << "now look : "; 
        for_each(vn.begin(), vn.end(), [] (int arg) {
          cout << arg << " "; 
        });
        cout << "" << endl;

        for (int len =  2; len <= num; len++) 
        {
          for (int start = 0; (start + len - 1) <= lastIndex; start++) 
          {
            vector<int> f(vn);
            vector<int> r; 
        
            for (int j = start; j < (start+len); j++)
              r.push_back(vn[j]);

            reverse(r.begin(), r.end());

            int tmpIndex = 0;
            for (int j = start; j < (start+len); j++)
              f[j] = r[tmpIndex++];
        
            cout << "Add: ";
            for_each(f.begin(), f.end(), [] (int arg) {
              cout << arg << " "; 
            });
            cout << "" << endl;
            allCount++;
            // compare two vectors
            if (f == ans) 
            {
              cout << "found answer at distance: " << distance << ", count: " << allCount << endl;
              goNextTest = true;
            }
            else 
              all.push_back(f);
      
            if (goNextTest) break;
          }
          if (goNextTest) break;
        } 
      
        if (goNextTest) break;
      } // for as element size of all
      if (goNextTest) break; 
    } // while 
  }
}

