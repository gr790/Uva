#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	freopen("./sample.txt", "r", stdin);
	map<char, int> f1;
	map<char, int> f2;

	string s1, s2;
	while( getline(cin, s1) )
	{
		getline(cin, s2);
		int len1 = s1.size();
		for(int i = 0; i < len1; ++i)
			f1[s1[i]]++;

		sort(s2.begin(), s2.end());

		int len2 = s2.size();
		for(int i = 0; i < len2; ++i)
		{
			if(f1[s2[i]])
			{
				cout << s2[i];
				f1[s2[i]]--;
			}
		}

		f1.clear();
		f2.clear();
		cout << endl;
	}
	return 0;
}
