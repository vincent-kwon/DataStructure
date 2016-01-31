#include <iostream>
#include <limits.h>

using namespace std;
/*
 * Find maximum area rectangle by color
 */
#define MAX_ARRAY 100000

int minTry;
typedef enum {NORTH, EAST, SOUTH, WEST} direction_e;
int rows, cols, node_num, target;

typedef struct {
  int start_row;
  int start_col;
  int end_row;
  int end_col;
} area_s;

typedef struct pt {
  int row;
  int col;
} pt_s;

void grind(area_s area, pt_s points[MAX_ARRAY], int points_size, int target, int currentNodes, int currentMove, string path) {  
  if (target >= currentNodes) {
    if (minTry > currentMove) {
      minTry = currentMove;
    }
    return;
  }

  int c_height = area.end_row - area.start_row + 1;
  int c_width  = area.end_col - area.start_col + 1;

  if (c_height <= 1 && c_width <= 1) {
    return;
  }

  for (int i = 0; i < 4; i++) {
    string new_path = path;
    area_s new_a;
    pt_s new_points[MAX_ARRAY];
    int  new_points_size = 0;

    new_a.start_row = area.start_row;
    new_a.start_col = area.start_col;
    new_a.end_row = area.end_row;
    new_a.end_col = area.end_col;

    int deadNodes = 0;

    switch (i) {
    case NORTH:
        //move up
	if (c_height > 1) {
          for (int j = 0; j < points_size; j++) { //only valid nodes
            if (points[j].row == 0) {//dead 
              deadNodes++;
            } else {
              new_points[new_points_size].row = points[j].row - 1;
              new_points[new_points_size].col = points[j].col;
              new_points_size++;
            }
	  }
          new_a.end_row -= 1;
          new_path += "N";
        }
        else 
	  continue;

	break;
    case EAST:
        if (c_width > 1) {
          for (int j = 0; j < points_size; j++) { //only valid nodes
            if (points[j].col == (cols-1)) { //dead 
              deadNodes++;
            } else {
              new_points[new_points_size].row = points[j].row;
              new_points[new_points_size].col = points[j].col+1;
              new_points_size++;
            }
	  }
          new_a.start_col += 1;
          new_path += "E";
        }
        else 
          continue;

	break;
    case SOUTH:
        if (c_height > 1) {
          for (int j = 0; j < points_size; j++) { //only valid nodes
            if (points[j].row == (rows-1)) { //dead 
              deadNodes++;
            } else {
              new_points[new_points_size].row = points[j].row+1;
              new_points[new_points_size].col = points[j].col;
              new_points_size++;
            }
	  }
          new_a.start_row += 1;
          new_path += "S";
        }
        else 
          continue;

	break;
    case WEST:
	if (c_width > 1) {
          for (int j = 0; j < points_size; j++) { //only valid nodes
            if (points[j].col == 0) { //dead 
              deadNodes++;
            } else {
              new_points[new_points_size].row = points[j].row;
              new_points[new_points_size].col = points[j].col-1;
              new_points_size++;
            }
	  }
          new_a.end_col -= 1;
          new_path += "W";
        }
        else 
          continue;

    	break;
    }
    grind(new_a, new_points, new_points_size, target, currentNodes - deadNodes, currentMove + 1, new_path);
  }
}

int main() {
  int testnum;
  int i, j, k, h;
  int x1, y1; //row, col

  cin >> testnum;
  
  while (testnum-- > 0) {
    cin >> rows;
    cin >> cols;
    cin >> target;
    cin >> node_num;
    pt_s points[MAX_ARRAY]; 

    int index = 0;
    minTry = 9999999;

    int node_num_tmp = node_num;
    while (node_num-- > 0) {

      cin >> x1;
      cin >> y1;

      points[index].row = x1;
      points[index].col= y1;
    
      index++;
    }
    
    area_s area;
    area.start_row = 0;
    area.start_col = 0;
    area.end_row = rows - 1;
    area.end_col = cols - 1;

    if (target >= node_num_tmp) {
      cout << "Min num: " << 0 << endl;
    }  
    grind(area, points, index, target, node_num_tmp, 0, "");  
   
    cout << "Min num: " << minTry << endl;
  }
  return 0;
}
