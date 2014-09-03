#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  freopen("./sample.txt", "r", stdin);
  int m, n;
  while(scanf("%d %d\n", &m, &n)==2)
    cout << (m*n)-1 << endl;
  return 0;
}
