#include <iostream>
#include <fstream>
using namespace std;

typedef long long int llong;
llong max_prod(int *arr, int n)
{
  llong max = 0;
  llong prod = 1;
  for(int i = 0; i < n; ++i)
  {
    prod = 1;
    for(int j = i; j < n && prod; ++j)
    {
      prod *= arr[j];
      if(max < prod)
        max = prod;
    }
  }
  return max;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
	int n = 0;
	int arr[100] = {0};
	int cases = 0;
	while( cin >> n )
	{
		int i = 0;
		while(i < n)
			cin >> arr[i++];
		cin.ignore();
    llong prod = max_prod(arr, n);
		printf("Case #%d: The maximum product is %lld.\n", ++cases, prod);
		cout << endl;
	}
	return 0;
}
