#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

#define min(a,b)  ( (a <= b)? a: b)
#define MAX 100
void print_dp(string &from, string &to, int d[MAX][MAX]);
void backtrack(string &from, string &to, int p[MAX][MAX]);

void print_dp(string &from, string &to, int d[][MAX])
{
  int fz = from.size();
  int tz = to.size();
  cout << setw(6) <<' ';
  for(int i = 0; i < tz; ++i)
    cout << setw(4) << to[i];
  cout << endl;
  cout << setw(2) <<' ';
  for(int i = 0; i <= tz; ++i)
    cout << setw(4) << d[0][i];
  cout << endl;

  int zero = 0;
  int opt[3] = {0};
  for(int i = 0; i < fz; ++i)
  {
    cout << setw(2) << from[i];
    for(int j = 0; j <= tz; ++j)
    {
      cout << setw(4) << d[i+1][j] ; //"("<<i+1<<','<<j<<")";
    }
    cout << endl;
  }
}

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
  backtrack(from, to, p);
}

void backtrack(string &from, string &to, int p[][MAX])
{
  int fsz = from.size();
  int tsz = to.size();
  
  int i = fsz;
  int j = tsz;
  int k = 0;

  /* this array is used to store the operation command (when moving from left to right) */
  char pt[MAX] = {0};
  /* backtrack from the right bottom to left upper part */
  /* this contains information from right to left( bottom up approach */
  while(true)
  {
    if(p[i][j] == -1)
      break;
    else if(p[i][j] == 0)
    {
      if(from[i-1] != to[j-1])
        pt[k] = 'R';
      else
        pt[k] = 'M';

      /* in case of match , move to upper diagonal position */
      --i;
      --j;
    }
    else if (p[i][j] == 1)
    {
      pt[k] = 'I';
      --j; /* move to left column */
    }
    else if(p[i][j] == 2)
    {
      pt[k] = 'D';
      --i; /* move to row-1 */
    }
    k++; /* these are the no of operation or length of pt */
  }

  int len = k; /* no of operation in pt */

  int s = 0; /* command count for source string */
  int t = 1; /* position in string */
  i = 0; /* i-th position in to string */

  for(int k = len-1; k >= 0; --k)
  {
    switch(pt[k])
    {
      case 'D':
        /* inc the count, inc the position in string */
        ++s;
        printf("%d Delete %d\n", s, t); /* deleting pos ++t from source string */
        break;
      case 'R':
        /* inc the count, inc the position in string, show the char which is going to replace */
        ++s;
        printf("%d Replace %d,%c\n", s, t, to[i]);
        ++i;
        ++t;
        break;
      case 'M':
        /* if both the char matches, do nothing, just incremnet the position as well the char pos */
        ++i;
        ++t;
        break;
      case 'I':
        /* if there is insertion, inc the count, position and char */
        ++s;
        printf("%d Insert %d,%c\n", s, t, to[i]);
        ++i;
        ++t;
        break;
    }
  }
  memset(&pt, 0, sizeof(pt));
}
  

int main()
{
  freopen("./sample.txt", "r", stdin);
  while(true)
  {
    string from, to;
    getline(cin, from);
    getline(cin, to);
    if( from.empty() && to.empty())
      break;
    edit_distance(from, to);
    int c = cin.peek();
    if( c == EOF)
    {
      if(cin.eof())
        break;
    }
    else
      cout << endl;
    from.clear();
    to.clear();
  }
  return 0;
}
