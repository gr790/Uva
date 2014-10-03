#include <iostream>
#include <map>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  int t;
  scanf("%d\n", &t);
  while(t--)
  {
    int n, m;
    scanf("%d %d\n", &n, &m);
    map<int, int> list;
    int val;
    for(int i = 0; i < n; ++i)
    {
      scanf("%d", &val);
      list[val]++;
    }
    for(int i = 0; i < m; ++i)
    {
      scanf("%d", &val);
      list[val]--;
    }
    int diff = 0;
    map<int, int>::iterator it;
    for(it = list.begin(); it != list.end(); ++it)
      diff += abs(it->second);
    cout << diff << endl;
    list.clear();
  }
  return 0;
}
