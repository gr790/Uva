/** 
 *  LDS( Longest decreasing problem 
 **/
#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
using namespace std;
typedef long long int ullong;

int lds(vector<int> &a) {
  int N = a.size();
  ullong *best, i, j, max = 1;
  best = (ullong*) malloc ( sizeof( ullong ) * N );
 
  for ( i = 0; i < N; i++ ) 
     best[i] = 1;
 
  for ( i = 1; i < N; i++ )
  {
     for ( j = 0; j < i; j++ )
     {
        if ( a[i] <= a[j] && best[i] < best[j] + 1 )
        {
          best[i] = best[j] + 1;
          if(max < best[i])
            max = best[i];
        }         
     }
  }

  free(best);
  return max;
}

int main(){
  freopen("./sample.txt", "r", stdin);
  int val,t = 0;
  vector<int> hyt;
  while(scanf("%d\n", &val))
  {
    if(val == -1)
      break;
      
    hyt.push_back(val);
    while(scanf("%d\n", &val))
    {
      if(val == -1)
        break;
      hyt.push_back(val);
    }
    int cnt = lds(hyt);
    printf("Test #%d:\n", ++t);
    printf("  maximum possible interceptions: %d\n", cnt);
    if( cin.peek() != '-')
      printf("\n");
    hyt.clear();
  }
  return 0;
}
