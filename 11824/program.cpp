#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <math.h>
#define MAX 5000000UL
using namespace std;
bool valueComp(const int &l, const int &r)
{
  if ( l < r ) 
    return false; 
  else
    return true;
}
int main()
{
  freopen("./sample.txt", "r", stdin);
  int t;
  cin >> t;
  cin.ignore();
  while(t--)
  {
    int val;
    vector<int> vi;
    while(cin>>val)
    {
      if(!val) break;
      vi.push_back(val);
    }
    sort(vi.begin(), vi.end(), valueComp);
    int sz = vi.size();
    unsigned long long int cost = 0;
    for(int i = 0; i < sz; ++i)
    {
      cost += (2 * pow(vi[i], i+1));
    }
    if ( cost > MAX)
      cout << "Too expensive" << endl;
    else
      cout << cost << endl;
    vi.clear();
  } 
  return 0;
}
