#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  unordered_map<int, int> scan;
  queue<int> que;
  int val;
  while(cin >> val)
  {
    if(!scan[val])
      que.push(val);
    scan[val]++;
  } 
  while(!que.empty())
  {
    int f = que.front();
    cout << f <<' '<< scan[f] << endl;
    que.pop();
  }
  return 0;
}
  
