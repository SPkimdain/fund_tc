//@checker FORMAT_STRING
#pragma warning(disable: 4996)

#include <stdio.h>


void formatStringTest(char* buf) {
  float log[8][12][13] = { 0.F, };
  char ctmp[10] = { 0, };

  sscanf(buf, "%9s, %f %f %f %f %f %f %f %f %f %f %f %f",
    ctmp, &log[0][0][1], &log[0][1][1], &log[0][2][1],
    &log[0][3][1], &log[0][4][1], &log[0][5][1],
    &log[0][6][1], &log[0][7][1], &log[0][8][1],
    &log[0][9][1], &log[0][10][1], &log[0][11][1]);
}
