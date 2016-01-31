/*
 * =====================================================================================
 *
 *       Filename:  find_collision.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/27/2015 07:45:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorith>

typedef enum { NOT_OVERLAP, INTERSECT, ON_TOP, ON_BOTTOM, ON_LEFT, ON_RIGHT, INCLUDED, INCLUDING, EXACT } collision_state_e;
 
typedef struct {
  int top_x;
  int top_y;
  int bottom_x;
  int bottom_y;
} points_s;

int checkRects(points_s p1, points_s p2) {
  return 0;
}

int main() {
  int test;
  cin >> test ;

  while (test--) {

    points_s p1, p2;

    cin >> p1.top_x;
    cin >> p1.top_y;
    cin >> p1.bottom_x;
    cin >> p1.bottom_y;

    cin >> p2.top_x;
    cin >> p2.top_y;
    cin >> p2.bottom_x;
    cin >> p2.bottom_y;
 
    collision_state_e state = checkRects(p1, p2);

    cout << "collision state: " << state << endl;
  }

  return 0;
} 
