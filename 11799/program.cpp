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
  int k = 0;
  while(k++ < test)
  {
    int num;
    infile >> num;
    int m = 0;
    int max = 0, val;
    while(m++ < num)
    {
      infile >> val;
      if(max < val)
        max = val;
    }
    printf("Case %d: %d\n", k, max);
  }
  return 0;
}
