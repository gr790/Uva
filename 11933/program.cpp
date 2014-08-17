#include <iostream>
#include <fstream>
#define set_bit(x, i)   (x = x | (0x1 << i) )
#define check_bit(x, i)   (x & (0x1 << i) )
using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  unsigned int num;
  while(cin >> num)
  {
    if(!num) break;

    int a = 0, b = 0, a_index = 0, b_index = 0, one = 0;
    while(num)
    {
      if(check_bit(num, 0) == 1) {
        if(one%2!=0) 
        {
          set_bit(b, b_index++);
          a_index++;
          one++;
        }
        else
        {
          set_bit(a, a_index++);
          b_index++;
          one++;
        }
      }
      else
      {
        a_index++;
        b_index++;
      }
      num = num >> 1;
    }
    printf("%d %d\n", a, b);
  }
  return 0;
}
