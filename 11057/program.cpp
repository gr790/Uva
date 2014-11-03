#include <bits/stdc++.h>
using namespace std;
vector<int> prices;

int binary_index(int val)
{
  int l = 0, mid;
  int h = prices.size();
  while(h >= l)
  {
    mid = l + (h-l)/2;
    if( prices[mid] < val)
      l = mid+1;
    else if( prices[mid] > val)
      h = mid-1;
    else
      return mid;
  }
  return -1;
}

void solve(int tot)
{
  sort(prices.begin(), prices.end());
  int sz = prices.size();
  int a, b;
  int m = INT_MAX;
  for(int i = 0; i < sz; ++i)
  {
    int j = binary_index(tot-prices[i]);
    if( j >= 0 && i < j )
    {
      if( (prices[j]-prices[i]) < m)
      {
        a = prices[i];
        b = prices[j];
        m = b - a;
      }
    }
  }
  printf("Peter should buy books whose prices are %d and %d.\n", a, b);
}

int main()
{
  freopen("./critical.txt", "r", stdin);
  int nb;
  while(scanf("%d\n", &nb) != EOF)
  {
    int val = 0;
    for(int i = 0; i < nb; ++i)
    {
      cin >> val;
      prices.push_back(val);
    }
    int tot;
    scanf("%d\n", &tot);
    solve(tot);
    cout << endl;
    prices.clear();
  }
  return 0;
}
