#include <iostream>
#include <string>
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
    string num;
    infile >> num;
    int sz = num.size();
    if( num == "1" || num == "4" || num == "78")
      printf("+\n");
    else if( num[sz-1] == '5' && num[sz-2] == '3')
      printf("-\n");
    else if( num[0] == '9' && num[sz-1] == '4')
      printf("*\n");
    else if ( num[0] == '1' && num[1] == '9' && num[2] == '0')
      printf("?\n");
    else
      printf("");
  }
  return 0;
}
