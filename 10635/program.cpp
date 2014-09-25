#include <iostream>
#include <fstream>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <map>

using namespace std;
#define MAX 62501
typedef unsigned long long ull;

int main()
{
  freopen("./critical.txt", "r", stdin);
  int t, k = 0;
  scanf("%d\n", &t);
  while(k < t)
  {
    int p,q, n;
    cin >> n >> p >> q;
    map<int, int> prince;

    int val;
    /* take down the steps of prince in array */
    /* ith step */
    for(int i = 1; i <= p+1; ++i)
    {
      cin >> val;
      prince[val] = i;
    }
    
    /* keep a another array for inserting princess steps in increasing order */
    /* all elements of array will be set to max int */
    int *a = new int[MAX];
    for(int i = 0;i < MAX; ++i)
        a[i] = INT_MAX; 

    /* now read princess array one by one, and check if there is corresponding step in prince array or not */
    /* if not, ignore it, else */
    /* insert this step into array at correct position */
    for(int i = 1; i <= q+1; ++i)
    {
      cin >> val;
      if(prince[val])
      {
         val = prince[val];
         int l, r, mid;
         l = 0, r = n * n;
         while( l+1 < r)
         {
           mid = (r+l) >> 1;
           if(a[mid] < val)
             l = mid;
          else
             r = mid;
         }
         a[l+1] = val;
      }
    }
    /* now iterate thru array to find out all entry which are less than INT_MAX */
    int res = 0;
    for(int i = n*n; i >= 0; --i)
    {
      if(a[i] <= n*n)
        res++;
    }
    printf("Case %d: %d\n", ++k, res);
    if(a != NULL)
      delete []a;
    prince.clear();
  }
  return 0;
}
   
