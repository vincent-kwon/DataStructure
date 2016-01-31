#include <iostream>
#include <algorithm>
#include <math.h>       /* sin */
#include <limits.h>

using namespace std;

int m[100][100];
int f[100][100] = {0, };
int ft[100][100] = {0, };

int bt[100][100] = {0, };
int b[100][100] = {0, };

int maxForwardTotal;
int grandMaster;
int getValueSub(int,int,int,int);
int main() {
  int testnum;
  int rows, cols;
  int i, j, k, h;
  int shot;

  cin >> testnum;

  while (testnum-- > 0) {
    maxForwardTotal = INT_MIN;
    grandMaster = INT_MIN;

    cin >> rows;
    cin >> cols;

    for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
        cin >> m[i][j];        
      }
    }
    
    for (i = 0; i < rows-2; i++) {  
      for (j = 0; j < cols-2; j++) {
        int total_sum = 0;

        if (i == 0) {
          f[i][j] = m[i][j];
        }
        else {
          f[i][j] = m[i][j] + f[i-1][j];  
        }

        total_sum = total_sum + f[i][j];
        ft[i][j] = total_sum;

        int sub = getValueSub(i+1,j+1,rows,cols);

        cout << "my : " << ft[i][j] << endl;
        cout << "sub : " << sub << endl;

        int all = ft[i][j] + sub;
         
        if (all > grandMaster) {
          grandMaster = all;
        }
      }
    }
    cout <<"Grand # " << grandMaster << endl;;
  }
}

int getValueSub(int r_s, int c_s, int rows, int cols) {
  int subTotal = INT_MIN;
  int i,j,k,h;
  int upperRect, lowerRect;

  {
    for (i = r_s; i < rows - 1; i++) {
      int total_sum = 0;
      for (j = c_s; j < cols - 1; j++) {
        int thisColSum = 0;

        if (i > r_s) {
          f[i][j] = m[i][j] + f[i-1][j];
        } 
        else { 
          f[i][j] = m[i][j];
        }

        total_sum = total_sum + f[i][j];
        ft[i][j] = total_sum;

        cout << "f[" << i << "," << j <<"] : " << f[i][j] << "," << ft[i][j] << endl;
        if (ft[i][j] > maxForwardTotal)
          maxForwardTotal = ft[i][j];
      }
    }

    //cout << "F#" << maxForwardTotal << endl;

    for (i = rows-1; i >= r_s+1; i--) {
      int total_sum = 0;
      for (j = cols-1; j >= c_s+1; j--) {
        int thisColSum = 0;

        if (i < (rows-1)) {
          b[i][j] = m[i][j] + b[i+1][j];
        } 
        else { 
          b[i][j] = m[i][j];
        }

        total_sum = total_sum + b[i][j];
        bt[i][j] = total_sum;

        cout << "b[" << i << "," << j <<"] : " << b[i][j] << "," << bt[i][j] << endl;
        if (bt[i][j] > maxForwardTotal) {
          maxForwardTotal = bt[i][j];
        }
      }
    } 
           
    //cout << "FB#" << maxForwardTotal << endl;

    for (i = r_s + 1; i <= rows - 1; i++) {
      for (j = c_s + 1; j <= cols - 1; j++) {
        int lowerRect = bt[i][j];
        int upperRect = ft[i-1][j-1];

        if ((upperRect + lowerRect) > subTotal) {
          subTotal = upperRect + lowerRect;
        }
        cout << "deck: " << (upperRect+lowerRect) << "  , " << upperRect << "," << lowerRect << endl;
      }
    }
  }

  return subTotal;
}
