#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;
int lcs_len(const vector<string> &vx, const vector<string> &vy)
{
  int x_z = vx.size();
  int y_z = vy.size();
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
      if( vx[i] == vy[j])
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
  freopen("./critical.txt", "r", stdin);
  int k = 0;
  stringstream ss;
  string x, y; 
  while(getline(cin, x))
  {
    ss.clear();
    string word;
    vector<string> vx;
    vector<string> vy;

    int xsz = x.size();
    for(int i = 0; i < xsz; ++i)
    {
      if(isalnum(x[i]))
        continue;
      else
        x[i] = ' ';
    }
    ss << x;
    while(!ss.eof())
    {
      ss >> word;
      if(!word.empty())
        vx.push_back(word);
      word.clear();
    }
    getline(cin, y);
    int ysz = y.size();
    for(int i = 0; i < ysz; ++i)
    {
      if(isalnum(y[i]))
        continue;
      else
        y[i] = ' ';
    }
    ss.clear();
    word.clear();
    ss << y;
    while(!ss.eof())
    {
      ss >> word;
      if(!word.empty())
        vy.push_back(word);
      word.clear();
    }
    if( xsz == 0 || ysz == 0)
      printf("%2d. Blank!\n",++k);
    else
      printf("%2d. Length of longest match: %d\n",++k, lcs_len(vx, vy));
  }
  return 0;
}
