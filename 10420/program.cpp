#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<string, int> mypair;

bool valueComp( const mypair &lhs, const mypair &rhs)
{
	return lhs.first < rhs.first;
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	
	int test;
	infile >> test;
	infile.ignore();

	string lstr;
	stringstream ss;
	map<string, int> freq;
	while(test--)
	{
		getline(infile, lstr);

		ss.str(lstr);
		string country;
		ss >> country;
	
		freq[country]++;

		lstr.clear();
		ss.clear();
	}

	vector<mypair> myvec(freq.begin(), freq.end());
	sort(myvec.begin(), myvec.end(), valueComp);

	vector<mypair>::iterator it;
	for(it = myvec.begin(); it != myvec.end(); ++it)
		cout << it->first <<" "<< it->second << endl;

	return 0;
}
