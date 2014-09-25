#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;
#define MAX 1005

void backtrack(string &s, string &rev, int p[][MAX], int len);
void print_dp(string &from, string &to, int d[MAX][MAX]);

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


string reverse(string &s)
{
  string str;
  int sz = s.size();
  for(int i = sz-1; i >= 0; --i)
    str += s[i];

  str.resize(sz);
  return str;
}

/* function return the min insert requireed and final palindrome string */
int min_insert(string &s, string &palin)
{
  int fz = s.size();
  /* get the reverse of the string */
  string rev = reverse(s);

  /* DP matrix */
  int d[MAX][MAX] = {0}; 
  /* back track matrix */
  int p[MAX][MAX] = {0};
  /* zero'd first row and column to zero */
  for(int i = 0; i <= fz; ++i)
  {
    d[i][0] = 0;
    d[0][i] = 0;
  }

  /* iterate over the matrix */
  for(int i = 0; i < fz; ++i)
  {
    for(int j = 0; j < fz; ++j)
    {
      if( s[i] == rev[j])
      {
        d[i+1][j+1] = d[i][j]+1;
        p[i+1][j+1] = 1; /* if str matches, move to diagnal position */
      }
      else if( d[i][j+1] >= d[i+1][j])
      {
        d[i+1][j+1] = d[i][j+1];
        p[i+1][j+1] = 2;
      }
      else
      {
        d[i+1][j+1] = d[i+1][j];
        p[i+1][j+1] = 3;
      }
    }
  }
  backtrack(s, rev, p, d[fz][fz]);
}

void backtrack(string &from, string &to, int p[][MAX], int len)
{
  int fsz = from.size();
  int tsz = to.size();

  int i = fsz;
  int j = tsz;
  int k = 0;

  /* this array is used to store the operation command (when moving from left to right) */
  int pt[MAX] = {0};
  /* backtrack from the right bottom to left upper part */
  /* this contains information from right to left( bottom up approach */
  print_dp(from, to, p);
  while(p[i][j]>0)
  {
    if(p[i][j] == 1 && from[i-1] == to[j-1])
    {
      /* in case of pt , move to upper diagonal position */
      --i;
      --j;
      pt[i] = 1;
    }
    else if (p[i][j] == 3)
    {
      --j;
    }
    else if(p[i][j] == 2)
    {
      --i;
    }
    else
    {
      --i;
      --j;
      pt[i] = 1;
    }
  }

  cout << fsz - len <<' ';

  char ans[MAX] = {0};
  i = 0;
  int s = 0, t = fsz - 1;
  while(s <= t)
  {
    if(!pt[s] && !pt[t])
    {
      ans[i++] = from[s++];
    }
    else if(pt[s] && pt[t])
    {
      ans[i++] = from[s];
      s++;
      t--;
    }
    else if(!pt[s] && pt[t])
    {
      ans[i++] = from[s++];
    }
    else if(pt[s] && !pt[t])
    {
      ans[i++] = from[t--];
    }
  }
  for(int j=0; j<i; j++){
      putchar(ans[j]);
  }

  for(int j=(len%2==0?i-1:i-2); j>=0; j--){
     putchar(ans[j]);
  }
  putchar('\n');


}

int main()
{
  freopen("./sample.txt", "r", stdin);
  string line;
  while(cin >> line)
  {
    int zero  = 0;
    if(line.empty())
    {
      cout << zero << endl;
      continue;
    }
    string palin_str;
    /* function do everything required by the problem */
    min_insert(line, palin_str);
  }
  return 0;
}
