#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	freopen("./sample.txt", "r", stdin);
  int n, k;
  n = k = 0;
        
  while( cin >> n >> k )
  {
     int have = n;
     while ( n >= k)
     {
        have += n / k;
        n = n / k + n %k;
     }
     cout << have << endl;
  }
	
	return 0;
}
