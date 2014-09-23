#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<char, int> freq;
typedef pair<char, int> mypair;

bool valueComp( const mypair &lhs, const mypair &rhs)
{
        if ( lhs.second < rhs.second )
		return true;
	if ( lhs.second == rhs.second )
	{
		if( lhs.first > rhs.first)
			return true;
	} 

	return false;
}

void solve(string &lstr)
{
	int len = lstr.length();
	for(int j=0; j < len; j++)
	{
		char ch = lstr.at(j);
		freq[ch]++;
	}

	vector<mypair> myvec(freq.begin(), freq.end());
	sort( myvec.begin(), myvec.end(), valueComp);

	vector<mypair>::iterator iter;
	for(iter = myvec.begin(); iter != myvec.end(); ++iter)
		cout <<toascii(iter->first)<<" "<<iter->second<<endl;

	myvec.clear();
	freq.clear();
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	string lstr;
	int nlines = 0;
	vector<string> vs;
	
	while( getline( infile, lstr) )
	{
		vs.push_back(lstr);
		lstr.clear();
		nlines++;
	}

	vector<string>::iterator iter;
	for( iter = vs.begin(); iter != vs.end(); ++iter)
	{
		solve(*iter);
		nlines--;
		if( nlines != 0)
			cout << endl;
	}
	return 0;
}
