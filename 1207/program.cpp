#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <sstream>
using namespace std;

#define min(a,b)  ( (a <= b)? a: b)
#define MAX 1005
void reformat(string &s)
{
  int sz = s.size();
  int j = 0;
  for(int i = 0; i < sz; ++i)
  {
    if(!isspace(s[i]))
      s[j++] = s[i];
  }
  s.resize(j);
}


void edit_distance(string &from, string &to)
{
  int d[MAX][MAX] = {0};
  int p[MAX][MAX] = {0};
  reformat(from);
  reformat(to);
  int fz = from.size();
  int tz = to.size();
  p[0][0] = -1; 
  for(int i = 0; i <= fz; ++i)
    d[i][0] = i;
  for(int i = 0; i <= tz; ++i)
    d[0][i] = i;

  for(int i = 1; i <= fz; ++i)
    p[i][0] = 2;
  for(int i = 1; i <= tz; ++i)
    p[0][i] = 1;

  /* contain the optimal solution */
  int opt[3] = {0}; 

  for(int i = 0; i < fz; ++i)
  {
    for(int j = 0; j < tz; ++j)
    {
      int val = 0;
      if( from[i] != to[j])
        val = 1;
      /* match or substitute */
      /* 0 is used for match or substitute */
      opt[0] = d[i][j]+val; 
      /* insert operation */
      opt[1] = d[i+1][j]+1;
      /* delete operation */
      opt[2] = d[i][j+1]+1;

      d[i+1][j+1] = opt[0];
      /* this matrix used for back-tracking */
      p[i+1][j+1] = 0;
      /* now apply algo to get the min among above operation */
      int k;
      for(k = 0; k < 3; ++k)
      {
        if(opt[k] < d[i+1][j+1])
        {
          d[i+1][j+1] = opt[k];
          p[i+1][j+1] = k;
        }
      }
    }
  }
  cout << d[fz][tz] << endl;
}
  

int main()
{
  freopen("./critical.txt", "r", stdin);
  string line, from, to;
  int flen, tlen;
  while(true)
  {
    stringstream ss;
    getline(cin, line);
    ss << line;
    while(!ss.eof())
    {
      ss >> flen >> from;
    }
    ss.clear();
    getline(cin, line);
    ss << line;
    while(!ss.eof())
    {
      ss >> tlen >> to;
    }
    edit_distance(from, to);
    int c = cin.peek();
    if( c == EOF)
    {
      if(cin.eof())
        break;
    }
    from.clear();
    to.clear();
  }
  return 0;
}
