#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  int n, m;
  while(cin >> n >> m)
  {
    if( !n && !m) break;
    int val, cnt = 0;
    vector<int> vn(n);
    vector<int> vm(m);
    for(int i = 0; i < n; ++i)
    {
      cin >> val;
      vn.push_back(val);
    }
    for(int j = 0; j < n; ++j)
    {
      cin >> val;
      if(binary_search(vn.begin(), vn.end(), val))
        cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
