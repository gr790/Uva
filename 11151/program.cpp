#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
using namespace std;
int c[1005][1001] = {0};
int b[1005][1001] = {0};
void print_lcs(string &s, int x, int y);

int lps_len(string x, string y)
{
  int x_z = x.size();
  int y_z = y.size();
  /* fill first column of all rows with zero's */
  for(int i = 0; i <= x_z; ++i)
    c[i][0] = 0;
  /* fill first row of all column with zero's */
  for(int j = 0; j <= y_z; ++j)
    c[0][j] = 0;
  for(int i = 0; i < x_z; ++i)
  {
    for(int j = 0; j < y_z; ++j)
    {
      if( x[i] == y[j])
      {
        c[i+1][j+1] = c[i][j]+1;
        b[i+1][j+1] = 1;
      }
      else if( c[i][j+1] >= c[i+1][j])
      {
        c[i+1][j+1] = c[i][j+1];
        b[i+1][j+1] = 2;
      }
      else
      {
        c[i+1][j+1] = c[i+1][j]; 
        b[i+1][j+1] = 3;
      }
    }
  }
  return c[x_z][y_z]; 
}

void print_lcs(string &s, int x, int y)
{
  if( x == 0 || y == 0)
    return;

  if(b[x][y] == 1)
  {
    print_lcs(s, x-1, y-1);
    printf("%c", s[x-1]);
  }
  else if( b[x][y] == 2)
    print_lcs(s, x-1, y);
  else
    print_lcs(s, x, y-1);
}


string reverse(string s)
{
  string r = "";
  int sz = s.size();
  for(int i = sz; i >=0; --i)
    r += s[i];
  return r;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int zero = 0;
  int t;
  scanf("%d", &t);
  getchar();
  while(t--)
  {
    string x, y;
    getline(cin, x);
    if(x.empty())
      cout << zero << endl;
    else
      cout << lps_len(x, reverse(x)) << endl;
    memset(&c, 0, sizeof(c));
    memset(&b, 0, sizeof(b));
  }
  return 0;
}
