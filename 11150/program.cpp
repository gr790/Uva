#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("./sample.txt", "r", stdin);
	int in;
	while(cin >> in)
	{
		long int tb = in;
		while(in >=3 )
		{
			in = in - 2;
			tb++;
		}
		if(in==2)
			tb++;
		cout << tb << endl;
	}
	return 0;
}
