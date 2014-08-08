#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <stdio.h>
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
    int i = 0;
    int max = 0;
    multimap<int, string> myset;
    while(i++ < 10)
    {
      string url;
      int rank;
      infile >> url >> rank;
      if ( max < rank)
        max = rank;
      myset.insert(pair<int, string>(rank,url));
      infile.ignore();
    }
    printf("Case #%d:\n", k);
    multimap<int, string>::iterator it;
    for(it = myset.begin(); it != myset.end(); ++it)
    {
      if( it->first == max )
        cout << it->second << endl;
    }
    myset.clear();
  }
  
  return 0;
}
