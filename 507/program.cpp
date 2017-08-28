#include <iostream>
#include <fstream>
using namespace std;

#define maxn 20000

void kadane_1d(int arr[maxn], int stops, int k)
{
  int left, right, max=0;
  if(max)
    printf("The nicest part of route %d is between stops %d and %d\n", k, left, right);
  else
    printf("Route %d has no nice parts\n", k);
}

int main()
{
  freopen("sample.txt", "r", stdin);
  int routes,k=0;
  cin >> routes;
  int stops;
  int arr[maxn]={0};
  while(k++ < routes)
  {
    memset(arr,0,sizeof(arr));
    cin >> stops;
    for(int i=0;i<stops-1;++i)
      cin >> arr[i];
    kadane_1d(arr,stops-1, k);
  }
  return 0;
}
