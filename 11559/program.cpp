#include <iostream>
#include <fstream>
using namespace std;
typedef unsigned long long int uint;

bool is_ok(uint n, uint b, uint h, uint w, uint &mc)
{
  bool found = false;
  uint c = 0;
  mc = b;
  while(h)
  {
    uint p;
    scanf("%ld\n", &p);
    uint we = w;
    while(we)
    {
      uint ab;
      scanf("%ld", &ab);
      if(ab >= n)
      {
        c = n * p; 
        if(c <= b)
        {
          found = true;
          if(c < mc)
            mc = c;
        }
      }
      we--;
    }
    h--;
  }
  return found;
}

int main()
{
  freopen("./critical.txt", "r", stdin);
  uint n, b, h, w;
  while(scanf("%ld %ld %ld %ld\n", &n, &b, &h, &w)==4)
  {
    uint min_cost = 0;
    if(is_ok(n, b, h, w, min_cost))
      cout << min_cost << endl; 
    else 
      cout <<"stay home" << endl;
  }
  return 0;
}
