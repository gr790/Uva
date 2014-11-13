#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("./sample.txt", "r", stdin);
	int t;
	scanf("%d\n", &t);
	while(t--)
	{
		int e, f, c;
		cin >> e >> f >> c;
		int tb = 0;
		/* total no of empty bottles before drinking..*/
		e = e + f;
		while(e>=c)
		{
			e = e - (c-1); 
			tb++;
		}
		cout << tb << endl;
	}
	return 0;
}
