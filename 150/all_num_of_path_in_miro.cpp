/*
 * =====================================================================================
 *
 *       Filename:  all_num_of_path_in_miro.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/15/2015 12:04:23 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

long long num_path(int m, int n) {
  if (map[m][n] == 0) 
    return 0;

  if (m == 0 && n == 0)
    return 1;

  return ( (m>0) ? num_path (m-1,n): 0) + ((n > 0) ? num_path (m , n - 1) : 0);

}

int main() {
  int m, n, i, j;

  int r = num_path (m - 1, n - 1);
}
