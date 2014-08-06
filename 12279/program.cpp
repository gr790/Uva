#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
  ifstream infile;
  infile.open("./sample.txt");
  int num, k=0;
  
  while(infile >> num)
  {
    if(!num) break;
    k++;
    int val, give = 0, expected = 0;
    for(int i = 0; i < num; ++i)
    {
      infile >> val;
      if(!val) 
        give++;
      else
        expected++;
    }
    printf("Case %d: %d\n", k, expected-give);
  }
}
