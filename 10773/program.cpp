#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  int t;
  scanf("%d\n", &t);
  for(int i = 0; i < t;)
  {
    double d, v, u;
    cin >> d >> v >> u;
    if(u == 0 || v == 0 || v >= u)
    {
      printf("Case %d: can't determine\n", ++i);
    }
    else
    {
      double diff = ((double(d/sqrt(u*u-v*v))-(double)(d/u)));
      printf("Case %d: %.3lf\n", ++i, diff);
    }
  }
  return 0;
}
    
