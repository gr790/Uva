#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
using namespace std;
int last_digit(int m)
{
  int last = 1, d2 = 0;
  for(int i=1;i<=m;++i)
  {
    int ii = i;
    while(ii%2==0)
    {
      d2++;
      ii/=2;
    }
    while(ii%5==0)
    {
      d2--;
      ii/=5;
    }
    
    last = (last * ii) % 10;
  }
  for(int i = 0;i < d2 ;++i)
  {
    last = (last * 2)%10;
  }
  return last;
}
  
int main()
{
  freopen("./sample.txt", "r", stdin);
  int num;
  while( scanf("%d\n", &num)==1)
  {
    int n = num;
    cout << right << setw(5) << num <<" -> " << setw(1) << last_digit(n) << endl;
  }
  return 0;
}
