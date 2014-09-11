#include <iostream>
#include <fstream>
using namespace std;
typedef signed long long int llong;

int main()
{
  freopen("./sample.txt", "r", stdin);
  llong a, b, c;
  int t, k = 1;;
  cin >> t;
  while(k <= t)
  {
    cin >> a >> b >> c;
    if( (a+b > c) && ( a+c > b) && ( b+c > a) )
    {
      if( ((a==c) && (c!=b)) || ((a==b) &&(b!=c)) || ((b==c) && (b!=a)))
        printf("Case %d: Isosceles\n", k);
      else if( (a == b) && ( b == c) && ( c == a))
        printf("Case %d: Equilateral\n", k);
      else if( (a != b) && ( b != c) && ( c != a))
        printf("Case %d: Scalene\n", k);
    }
    else
      printf("Case %d: Invalid\n", k);
    k++;
  }
  return 0;
}

