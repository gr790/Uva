#include <iostream>
#include <fstream>
#include <iomanip>
#define MAX 8001
using namespace std;
typedef unsigned long long int ullong;
int coins[] = {0, 1, 5, 10, 25, 50};
ullong dp[6][MAX+1];

void print_dp();

void dp_table()
{
  /* if there is no change, use no coins */
  for(int i = 1; i <= 5; ++i)
    dp[i][0] = 1;

  /* i coins */
  for(int i = 1; i <= 5; ++i)
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
  for(int i = 1; i < 6; ++i)
  {
    cout << setw(2) << coins[i];
    for(int j = 0; j <= MAX; ++j)
    {
      cout << setw(4) << dp[i][j] ; //"("<<i+1<<','<<j<<")";
    }
    cout << endl;
  }
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  /* coin available are 1c, 5c, 10c, 25c, 50c */
  dp_table();
  int change;
  while(cin >> change)
    cout << dp[5][change] << endl;
  return 0;
}
