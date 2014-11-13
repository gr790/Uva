#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("./sample.txt", "r", stdin);
	int t,k =0;
	scanf("%d\n", &t);
	while(k++ < t)
	{
		int n, val;
		vector<int> vi;
		cin >> n;
		for(int i=0;i<n;++i)
		{
			cin >> val;
			vi.push_back(val);
		}

		sort(vi.begin(), vi.end());
		int med = 0;
		if(n&(n-1)==0)
		{
			int am = vi[n/2];
			int bm = vi[(n/2)-1];
			med = (am+bm)/2;
		}
		else
		{
			/* no of element is odd */
			med = vi[n/2];
		}
		printf("Case %d: %d\n", k, med);
		vi.clear();
	}
	return 0;
}
