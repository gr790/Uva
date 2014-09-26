#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string.h>
using namespace std;
#define MAX 25
int order[MAX];
int stu[MAX];

void print_dp(int *from, int *to, int n, int d[MAX][MAX]);

void print_dp(int *from, int *to, int n, int d[][MAX])
{
  int fz,tz;
  fz = tz = n ;
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


int lcs_to_lis(int *order, int *stu, int n)
{
  int dp[MAX][MAX] = {0};
  for(int i = 0; i <= n; ++i)
    for(int j = 0; j <= n; ++j)
      dp[i][j] = 0;
  for(int i = 1; i <= n; ++i)
  {
    for(int j = 1; j <= n; ++j)
    {
      if( order[i] == stu[j])
        dp[i][j] = dp[i-1][j-1]+1;
      else
        dp[i][j] = max( dp[i][j-1], dp[i-1][j]);
    }
  }
  return dp[n][n];
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int n, val;
  scanf("%d\n", &n);
  
  for(int i = 1; i <= n; ++i)
  {
    /* read the correct order */
    scanf("%d", &val);
    /* index these val */
    order[val] = i;
  }
  while(true)
  {
    for(int i = 1; i <= n; ++i)
    {
      if(scanf("%d",&val) == EOF)
        return 0;
      stu[val] = i;
    }
    cout << lcs_to_lis(order, stu, n) << endl;
    memset(&stu, 0, MAX);
  }
  return 0;
}

