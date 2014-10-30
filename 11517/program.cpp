#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits.h>
#define MAX 30000
using namespace std;
typedef unsigned long long int ullong;
ullong dp[MAX+1];

void print_dp(int n);
int coins[101];

void dp_table(int nbc, int buy_price)
{
  /* if there is no change, use no coins */
  for(int i = 1; i <= MAX; ++i)
    dp[i] = INT_MAX;
  dp[0] = 0;

  /* i coins */
  /* This represents no of coins and their values I want to use */
  for(int i = 0; i < nbc; ++i)
  {
    /* j cents */
    /* This represents the value I want to build from the coins mentioned above */
    for(int j = (MAX+1)-coins[i]-1; j >= 0; --j)
    {
      if(dp[j] < INT_MAX)
        dp[j+coins[i]] = min( dp[j+coins[i]], dp[j]+1);
    }
  }
  /* dp contains the no of coins used to get the desired index in dp table ( index represents the value ) */
  int min = INT_MAX;
  for(int i = 1; i < MAX; ++i)
  {
    if(i >= buy_price && dp[i] != INT_MAX)
    {
      if( i < min)
        min = i;
    }
  }
  cout << min <<' '<< dp[min] << endl;
}

int main()
{
  freopen("./critical.txt", "r", stdin);
  int t;
  scanf("%d\n", &t);
  while(t--)
  {
    int buy_price;
    cin >> buy_price;
    int nbc, val;
    cin >> nbc;
    for(int i = 0; i < nbc; ++i)
    {
      cin >> val;
      coins[i] = val; 
    }
    dp_table(nbc, buy_price);
  }
  return 0;
}
