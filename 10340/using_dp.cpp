#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <stdlib.h>
/* This program giving TLE on Uva */
using namespace std;
void lcs( string &s, string &t)
{
	int slen = s.size();
	int tlen = t.size();
  int max_size = max(slen, tlen);
  int **dp = (int**)calloc(max_size+1, sizeof(int*));
  for(int i = 0; i <= max_size; ++i)
    dp[i] = (int*)calloc(max_size+1, sizeof(int));
  for(int i = 1; i <= slen; ++i)
  {
    for(int j = 1; j <= tlen; ++j)
    {
      if(s[i-1] == t[j-1])
        dp[i][j] = dp[i-1][j-1]+1;
      else
        dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
    }
  }
  if(slen == dp[slen][tlen])
		cout <<"Yes" << endl;
	else	
		cout <<"No" << endl;
  for(int i = 0; i <= max_size; ++i)
    free(dp[i]);
  free(dp);
}
int main()
{
  freopen("./sample.txt", "r", stdin);
	string s,t;
	while( cin >> s >> t )
		lcs(s, t);
	return 0;
}
