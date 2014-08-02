#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream infile;
  infile.open("./sample.txt");
  int num;
  infile >> num;
  infile.ignore();
  while(num--)
  {
    int G, L, fail;
    fail = -1;
    infile >> G >> L;
    infile.ignore();
    if(L%G==0)
      cout << G <<' '<< L << endl;
    else
      cout << fail << endl;
  }
  return 0;
} 
