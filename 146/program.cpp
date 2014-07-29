#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

void solve(string &str)
{
  if( next_permutation(str.begin(), str.end()))
  {
    cout << str << endl;
  }
  else { 
    cout <<"No Successor" << endl;
  }
}

int main()
{
  ifstream infile;
  infile.open("./sample.txt");
  string lstr;
  
  while ( infile >> lstr)
  {
     if (lstr[0] == '#')
      break;
     solve(lstr);
  }

  return 0;

}
