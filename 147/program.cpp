/**
 *  DP problem for counting Number of ways to arrange the change 
 **/
#include <iostream>
#include <fstream>
#include <iomanip>
#define MAX 30000
using namespace std;
typedef unsigned long long int ullong;
int coins[] = {0, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
ullong dp[13][MAX+1];

void print_dp();

void dp_table()
{
  /* if there is no change, use no coins */
  for(int i = 1; i <= 12; ++i)
    dp[i][0] = 1;

  /* i coins */
  for(int i = 1; i <= 12; ++i)
  {
    /* j cents */
    for(int j = 1; j <= MAX; ++j)
    {
      if(coins[i] > j)
        dp[i][j] = dp[i-1][j];
      else
        dp[i][j] = dp[i-1][j] + dp[i][j - coins[i]];
    }
  }
}

void print_dp()
{
  cout << setw(6) <<' ';
  for(int i = 1; i <= MAX; ++i)
    cout << setw(4) << i;
  cout << endl;
  cout << setw(2) <<' ';
  for(int j = 0; j <= MAX; ++j)
    cout << setw(4) << dp[0][j];
  cout << endl;
  for(int i = 1; i < 12; ++i)
  {
    cout << setw(2) << coins[i];
    for(int j = 0; j <= MAX; ++j)
    {
      cout << setw(4) << dp[i][j]; 
    }
    cout << endl;
  }
}

void to_format(string &s, string &d, string &c)
{
  int sz = s.size();
  int i = 0;
  for(;i < sz; ++i)
  {
    if( s[i] != '.')
    {
      d += s[i];
    }
    else
      break;
  }
  for(i++;i < sz; ++i)
  {
    c += s[i];
  }

}

ullong to_int(string &s)
{
  ullong n = 0;
  int sz = s.size();
  for(int i = 0; i < sz; ++i)
  {
    n = (n * 10) + (s[i] - '0');
  }
  return n;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  dp_table();
  string line;
  while(getline(cin, line))
  {
    string d, c;
    to_format(line, d, c);
    if(!to_int(d) && !to_int(c))
      break;
    ullong val = to_int(d)*100 + to_int(c);
    ullong maxr = dp[12][val];
    cout << right << setw(6) << line << right << setw(17) << maxr << endl;
    d.clear();
    c.clear();
  }
  return 0;
}
