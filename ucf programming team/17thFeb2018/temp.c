#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

double inline degree2radian(int a) { return (a * 0.017453292519); }

void getEndPoint(double angle, int len, int start_x, 
    int start_y, int *end_x, int *end_y) {
        *end_x = start_x + len * cos(angle);
        *end_y = start_y + len * sin(angle);
} // getEndPoint

int main(int argc, char *argv[]) {
  double angle = -90;
  int length   = 10;
  int start_x  = 0;
  int start_y  = 0;
  int x, y;

  getEndPoint(degree2radian(angle), length, start_x, start_y, &x, &y);
  printf("end x=%d, end y=%d\n", x, y);

  return 0;
} // main