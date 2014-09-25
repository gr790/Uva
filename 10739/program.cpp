#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;

#define MAX 1001

void print_dp(string &s, int d[][MAX]);

int min_req(string &s, int st, int len)
{
  int c[MAX][MAX] = {0};
  int i = 0, j = 0;
  /* zero'd the dp matrix */
  memset(&c, 0, sizeof(c));
  /* calculate the upper right matrix */
  for(i = len-1; i >= 0; --i)
  {
    for(j = i; j <= len-1; ++j)
    {
      if(s[i] == s[j])
        c[i+1][j+1] = c[i+2][j];
      else
        c[i+1][j+1] = 1 + min( c[i+2][j+1], min(c[i+1][j], c[i+2][j])); 
    }
  }
  return c[st+1][len];
}

void print_dp(string &from, int d[][MAX])
{
  int fz = from.size();
  int tz = fz;
  cout << setw(6) <<' ';
  for(int i = 0; i < tz; ++i)
    cout << setw(4) << from[i];
  cout << endl;
  cout << setw(2) <<' ';
  for(int i = 0; i <= tz; ++i)
    cout << setw(4) << d[0][i];
  cout << endl;
  int zero = 0;
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


int main()
{
  freopen("./sample.txt", "r", stdin);
  int t, k =0;
  scanf("%d\n", &t);
  while(k < t)
  {
    string x;
    getline(cin, x);
    printf("Case %d: %d\n", ++k, min_req(x, 0, x.size()));
  }
  return 0;
}
