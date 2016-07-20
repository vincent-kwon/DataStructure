#include <iostream>
#include <sstream>

using namespace std;

void getAllString(string org, string toAdd, int startIndex)
{
  
  if (startIndex == toAdd.size()) {
    cout << "found:" << org << endl;
    return;
  }

  for (int i = startIndex; i < toAdd.size(); i++) {    
    string nextOrg = "(" + org + toAdd.substr(startIndex, i-startIndex+1) + ")";
    getAllString(nextOrg, toAdd, i+1);
  }
}

int main() {
  int t;
  cin >> t;
  
  while (t-- > 0) 
  {
    int num;
    cin >> num;
    
    cout << "iterate all possible combinations: " << endl;
    string s = "";
    stringstream ss("");

    for (int i = 0 ; i < num ; i++) 
    {
      ss << i;       
    }
    cout << ss.str() << endl;
    
    getAllString("", ss.str(), 0);
  }
  return 0;
}
