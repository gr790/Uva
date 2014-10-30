#include <bits/stdc++.h>
using namespace std;

vector<long int> head;
multiset<long int> knight;

bool solve()
{
  int sz = head.size();
  int coins = 0;
  for(int i = 0; i < sz; ++i)
  {
    multiset<long int>::iterator it = knight.lower_bound(head[i]);
    if( it == knight.end()) 
      return false;
    coins += *it;
    knight.erase(it);
  }
  cout << coins << endl;
  return true;

}

int main()
{
  freopen("./critical.txt", "r", stdin);
  long int d,h;
  while(scanf("%ld %ld\n", &d, &h)!=EOF)
  {
    if( !d && !h)
      break;
    long int val;
    while(d--)
    {
      cin >> val;
      head.push_back(val);
    }
    while(h--)
    {
      cin >> val;
      knight.insert(val);
    }
    if(!solve())
      cout <<"Loowater is doomed!"<<endl;
    head.clear();
    knight.clear();
  }
  return 0;
}
