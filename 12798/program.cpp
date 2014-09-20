#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  int n, m;
  while(scanf("%d %d\n", &n, &m)==2)
  {
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
      bool missed = false;
      int val = 0;
      for(int j = 0; j < m; ++j)
      {
        cin >> val;
        if(!val)
          missed = true;
      }
      if(!missed)
        cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
  
