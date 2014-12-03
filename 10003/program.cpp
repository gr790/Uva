#include <bits/stdc++.h>
using namespace std;
int c[100];
int dp[100][100];

int solve(int left, int right)
{
  if(dp[left][right] != -1)
    return dp[left][right];
  if( left + 1 == right)
    return dp[left][right] = 0;
  int best = INT_MAX;
  for(int i = left+1; i < right; ++i)
    best = min(best, solve(left, i)+ solve(i, right) + c[right]-c[left]); 
  return dp[left][right] = best;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int len;
  while( scanf("%d\n", &len)==1)
  {
    if(!len)
      break;
    int n;
    scanf("%d\n", &n);
    for(int i = 1; i <= n; ++i)
      scanf("%d", &c[i]);
    c[0] = 0;
    c[n+1] = len;
    memset(dp, -1, sizeof(dp));
    printf("The minimum cutting is %d.\n", solve(0, n+1));
    memset(c, 0, sizeof(c));
  }
  return 0;
}
