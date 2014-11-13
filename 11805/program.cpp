#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("./sample.txt", "r", stdin);
	int t,j=0;
	scanf("%d\n", &t);

	while(j++ < t)
	{
		int n, k, p;
		cin >> n >> k >> p;
		int i =0;
		while(i++!=p)
		{
			k++;
			if(k > n)
				k = 1;
		}
		printf("Case %d: %d\n", j, k);
	}
	return 0;
}
