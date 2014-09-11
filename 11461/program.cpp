#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  int a, b;
  while( cin >> a >> b)
  {
    if(!a && !b) break;
    int cnt = 0, i = 1;
    /* first find next perfect square greater than a */
    while(i)
    {
      if( (i*i) >= a)
        break;
      i++;
    }

    while(i)
    {
      int j = i*i;
      if( j >= a && j <= b)
          cnt++;
      else
        break;
      i++;
    }
    cout << cnt << endl;
  }
  return 0;
}
