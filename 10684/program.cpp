#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

#define maxn 10000

void kadane_1d(int arr[maxn],int size)
{
   int max=0;
   if(max > 0)
     printf("The maximum winning streak is %d.\n", max);
   else
     printf("Losing streak.\n");
}

int main()
{
  freopen("sample.txt", "r", stdin);
  int n;
  int arr[maxn]={0};
  while(cin>>n)
  {
    if (!n) break;
    int i;
    for(i=0;i<n;++i)
      cin >> arr[i];

      kadane_1d(arr, i);
      memset(arr,0,sizeof(arr));
  }
  return 0;
}
