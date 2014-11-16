#include <bits/stdc++.h>
using namespace std;
int main()
{
  freopen("./sample.txt", "r", stdin);
	int test;

	cin >> test;
	cin.ignore();
	cin.ignore();
	stringstream s1;
	stringstream s2;
	while(test--)
	{
		map<int, string> freq;
		s1.clear();
		s2.clear();
		int a;
		string inp, fnp, b;
		getline(cin, inp);
		getline(cin, fnp);
		s1 << inp;
		s2 << fnp;
		while( s1 >> a  && s2 >> b)
			freq.insert(make_pair(a, b));

		map<int, string>::iterator it;
		for(it = freq.begin(); it != freq.end(); ++it)
			cout << it->second << endl;
		if(test)
			cout << endl;
		freq.clear();
		cin.ignore();
	}

	return 0;
}
