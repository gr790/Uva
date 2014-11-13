#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("./sample.txt", "r", stdin);
	int a, b, c, d, L;
	while(scanf("%d %d %d %d %d\n", &a, &b, &c, &d, &L)==5)
	{
		if(!a && !b && !c && !d && !L)
			break;
		int i = 0, cnt = 0;
		while(i <= L)
		{
			long int f = (a*i*i)+(b*i)+c;
			if(f%d==0)
				cnt++;
			i++;
		}
		cout << cnt << endl;
	}
	return 0;
}
