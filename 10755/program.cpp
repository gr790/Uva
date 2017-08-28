#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

#define maxn 20
typedef unsigned long long int ullong;
int depth, row, col;
int arr[maxn][maxn][maxn]={0};

ullong kadane_3d(int arr[maxn][maxn][maxn])
{
}

int main()
{
  freopen("sample.txt", "r", stdin);
  int tests;
  cin >> tests;
  while(tests)
  {
    memset(arr,0,sizeof(arr));
    cin >> depth >> row >> col;
    for( int i=0;i<depth;++i)
    {
      for(int j=0;j<row;++j)
      {
        for(int k=0;k<col;++k)
        {
          cin >> arr[i][j][k];
        }
      }
    }
    ullong ans = kadane_3d(arr);
    cout << ans;
    if (tests--) cout << endl;
  }
  return 0;
}
