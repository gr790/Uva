#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;

void solve( string &s, string &t)
{
	int slen = s.size();
	int tlen = t.size();

	bool found = false;
	int next_index = 0;
	for( int i = 0; i < slen ; ++i )
	{
		found = false;
		for( int j = next_index; j < tlen; ++j)
		{
			if( s[i] == t[j] )
			{
				next_index = j + 1;
				found = true;
				break;
			}
		}
		if( !found )
			break;
	}
	if( found )
		cout <<"Yes" << endl;
	else	
		cout <<"No" << endl;

	
}

int main()
{
  freopen("./sample.txt", "r", stdin);
	string s,t;
	while( cin >> s >> t )
	{
		solve(s, t);
	}
	return 0;
}
