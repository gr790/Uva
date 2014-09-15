#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int lcs_len(string x, string y)
{
  int x_z = x.size();
  int y_z = y.size();
  int c[1001][1001] = {0};

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
        c[i+1][j+1] = c[i][j]+1;
      else if( c[i][j+1] >= c[i+1][j])
        c[i+1][j+1] = c[i][j+1];
      else
        c[i+1][j+1] = c[i+1][j]; 
    }
  }

  return c[x_z][y_z]; 
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int k = 0;
  while(!cin.eof())
  {
    string x, y;
    getline(cin, x);
    if(x == "#")
      break;
    getline(cin, y);
    if(x.empty() || y.empty())
      printf("Case #%d: you can visit at most 0 cities.\n", ++k);
    else 
      printf("Case #%d: you can visit at most %d cities.\n", ++k, lcs_len(x, y));
  }
  return 0;
}
