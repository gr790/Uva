#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int main()
{
  freopen("./sample.txt", "r", stdin);
  int n, q;
  int k = 0;
  while( cin >> n >> q)
  {
    if(!n && !q) break;
    multimap<int, int> mar;
    int i = 1, val;
    while(i <= n )
    {   
      cin >> val;
      mar.insert(pair<int, int>(val, i));
      i++;
    }
    i = 1;
    multimap<int, int>::iterator it;
    for(it = mar.begin(); it!=mar.end(); ++it)
    {
      it->second = i;
      ++i;
    }
    printf("CASE# %d:\n", ++k);
    int j = 0;
    while(j < q)
    {
      cin >> val;
      bool found = false;
      it = mar.find(val);
      if(it != mar.end())
        printf("%d found at %d\n", val, it->second);
      else
        printf("%d not found\n", val);
      j++;
    }
    mar.clear();
  }
  return 0;
}
