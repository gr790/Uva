#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int base26(string &s)
{
  int n = 0, j;
  int sz = s.size();
  for(int i = sz-1, j=0; i >=0; --i,++j)
    n += (s[i]-'A')*pow(26,j); 
  return n;
  
}

int dec(string &s)
{
  int n = 0;
  int sz = s.size();
  for(int i = 0; i < sz;  ++i)
  {
    n  = (s[i]-'0')+(n*10);
  }
  return n;
}


bool is_nice(string &line)
{
  string ft = line.substr(0,3);
  string sec = line.substr(4,7);
  if( abs(base26(ft)-dec(sec))<=100)
    return true;
  return false;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int t;
  scanf("%d\n", &t);
  while(t--)
  {
    string line;
    getline(cin, line);
    stringstream ss;
    ss << line;
    char c;
    string first, sec;
    bool found = is_nice(line);
    if(found)
      cout <<"nice" << endl;
    else
      cout <<"not nice" << endl;
  }
  return 0;
}
