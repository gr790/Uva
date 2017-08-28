#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

#define maxn 20000

void kadane_1d(int arr[maxn],int size)
{
   int max=0;
   cout << max << endl;
}

int main()
{
  freopen("sample.txt", "r", stdin);
  int n;
  int arr[maxn]={0};
  while(!cin.eof())
  {
    int i = 0;
    while( (cin>>n) && (n != -999999))
      arr[i++] = n;

      kadane_1d(arr, i);
      memset(arr,0,sizeof(arr));
  }
  return 0;
}
