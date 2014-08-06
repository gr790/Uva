#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

bool is_fit(int l, int w, int h)
{
  if( l <= 20 && w <= 20 && h <= 20)
    return true;
  else
    return false;
}

int main()
{
  ifstream infile;
  infile.open("./sample.txt");
  int test;
  infile >> test;
  infile.ignore();
  int k=0;
  while(k++ < test)
  {
     int l, w, h;
     infile >> l >> w >> h;
     if( is_fit(l, w, h) )
       printf("Case %d: good\n", k);
     else
       printf("Case %d: bad\n", k);
       
  }

  return 0;
}
