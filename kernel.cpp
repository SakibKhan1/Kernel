/* Name: Sakib Khan
Professor: Tong Yi
Assignment: Kernel
The operation replaces pixel e (in the middle of the 3x3 window) with some function of its neighbors f(a,b,c,d,e,f,g,h,i)
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
char c;
int x;
ifstream instr;
instr.open("inImage.pgm");
instr >> c;
assert(c == 'P');
instr >> c;
assert(c == '2');

// skip the comments (if any)
while ((instr>>ws).peek() == '#') {
// while loop
instr.ignore(4096, '\n');
}

instr >> width;
instr >> height;

assert(width <= MAX_W);
assert(height <= MAX_H);
int max;
instr >> max;
assert(max == 255);

for (int row = 0; row < height; row++)
