#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
  ifstream infile;
  infile.open("./sample.txt");
  int test;
  infile >> test;
  infile.ignore();
  while(test--)
  {
    int r, c;
    infile >> r >> c;
    /* 3 block each on row & column */
    cout << (r/3)*(c/3) << endl;
  }
  return 0;
}
