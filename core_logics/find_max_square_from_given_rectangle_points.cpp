#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
/*
 * From given start point (r,c), and end point to a matrix filled with values,
 * find maximum sum of area must start from start point. End can't be bigger than
 * end point.
 *
 * 
 */
int M[300][300] = {0, };
int A[300][300];
int H;
int W;

typedef struct {
  int sr;
  int sc;
  int er;
  int ec;
} square_s;

int P;
square_s PS[100000];

int addIfNew(int index, int value, int* cA) {
  for (int i = 0; i < index ; i++) {
    if (cA[i] == value) {
      return index;
    }
  }

  cA[index] = value;
  index++;
  return index;
}


bool checkFit(int sr, int sc, int er, int ec, int i) {
  if (sr <= PS[i].sr && 
      sc <= PS[i].sc && 
      er >= PS[i].er && 
      ec >= PS[i].ec) {
    return true;
  }
  else {
    return false;
  }    
}

bool checkFitAll(int sr, int sc, int er, int ec, int* cA, int nextIndex) {
  for (int i = 0 ; i < nextIndex ; i++ ) {
    if (!checkFit(sr,sc,er,ec, cA[i])) return false;
  }
  return true;    
}

int findMaxValue(int sr, int sc, int er, int ec) {
  int max = -99999999;
  int i,j,k;

  int target = (H > W) ? W : H;
  int nextIndex = 0;
  int C[300];

  for (i = 0 ; i < target ; i++) {
    for (j = 0 ; j < i ; j++) {
      int colMove = M[sr+i][sc+j];
      int rowMove = M[sr+j][sc+i];
      nextIndex = addIfNew(nextIndex, colMove, (int *)C);
      nextIndex = addIfNew(nextIndex, rowMove, (int *)C);
    }
    nextIndex = addIfNew(nextIndex, M[sr+i][sc+i], (int *)C); 
    if (checkFitAll(sr, sc, sr+i+1, sc+i+1, (int *)C, nextIndex)) {
      if ( (sr+i+1 - sr) > max ) {
        max = (sr+i+1 - sr);
       //cout << "FIT: (" << (sr+i+1 - sr)  << ") " << sr << " " << sc << " " << sr + i + 1 << " " << sc + i + 1 << endl;
      }
    }
  }

  return max;
}

int main() {
  int test;
  int i,j,k,m,v;

  scanf("%d", &test);
  while (test-- > 0) {
    scanf("%d %d", &H,&W);      
    scanf("%d", &P);


    for (i = 0 ; i < P; i++) {
      scanf("%d", &v);
      scanf("%d %d %d %d", &PS[v].sr, &PS[v].sc, &PS[v].er, &PS[v].ec);

      for (k = PS[v].sr ; k < PS[v].er; k++ ) {
        for (m = PS[v].sc ; m < PS[v].ec; m++) {
          M[k][m] = v;
        }
      }
    }

    int maxValue = findMaxValue(0,0,H,W);
    cout << maxValue << endl;
  }
}
