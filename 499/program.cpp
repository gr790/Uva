#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<char, int> mypair;
bool valueComp( const mypair &lhs, const mypair &rhs)
{
	if( lhs.second < rhs.second ) 
		return false;
	if( lhs.second == rhs.second )
	{
		return lhs.first < rhs.first;
	}

	return true;
}

#define C(x)	((x >= 'A' && x <= 'Z') ? 1 : ( x >= 'a' && x <= 'z') ? 1 : 0) 

int main()
{
	ifstream infile;
	infile.open("./sample.txt");

	string line;
	while(getline(infile, line))
	{
		map<char, int> freq;
		int len = line.size();
		for(int i = 0; i < len; ++i)
		{
			if( C(line[i]) )
				freq[line[i]]++;
		}
		
		vector<mypair> myvec(freq.begin(), freq.end());

		sort(myvec.begin(), myvec.end(), valueComp);
		int max = myvec.at(0).second;
		vector<mypair>::iterator it;
		for(it = myvec.begin(); it != myvec.end(); ++it)
		{
			if( it->second == max )
				cout << it->first;
		}
		cout <<" "<< max << endl;
		myvec.clear();
		freq.clear();
		line.clear();
	}
}
