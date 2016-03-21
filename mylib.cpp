#include "mylib.h"

/* cs is number of coins */
void print_dp(int amount, int cs)
{
  cout << setw(4) <<' ';
  for(int i = 0; i <= amount; ++i)
    cout << setw(4) << i;
  cout << endl;
  cout << setw(4) <<' ';
  for(int j = 0; j <= amount; ++j)
    cout << setw(4) << dp[0][j];
  cout << endl;
  for(int i = 1; i <= cs; ++i)
  {
    cout << setw(4) << coins[i];
    for(int j = 0; j <= amount; ++j)
    {
      cout << setw(4) << dp[i][j] ; //"("<<i+1<<','<<j<<")";
    }
    cout << endl;
  }

  cout <<"Printing only DP." << endl;
  for(int i = 0; i <= cs; ++i)
  {
    for(int j = 0; j <= amount; ++j)
    {
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }
  cout << dp[cs][amount] << endl;
}

