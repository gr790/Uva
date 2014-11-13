#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("./sample.txt", "r", stdin);
	string a,b;
	while(getline(cin, a))
	{
		if(a.empty())
			break;
		/* used for sorted input */
		set<int> sa, sb;
		getline(cin, b);
		stringstream ss;
		ss << a;
		int val;
		while(!ss.eof())
		{
			ss >> val;
			sa.insert(val);
		}
		ss.clear();
		ss << b;
		while(!ss.eof())
		{
			ss >> val;
			sb.insert(val);
		}
		ss.clear();
		set<int> inter;
		set_intersection(sa.begin(), sa.end(), sb.begin(), sb.end(), insert_iterator<set<int> >( inter, inter.begin()));
		if( sa == sb)
			printf("A equals B\n");
		else if( sa == inter)
			printf("A is a proper subset of B\n");
		else if( sb == inter)
			printf("B is a proper subset of A\n");
		else if(inter.size()==0)
			printf("A and B are disjoint\n");
		else
			printf("I'm confused!\n");
	}
	return 0;
}
