#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
std::map<char, int> freq;
typedef std::pair<char, int> mypair;

bool valueComp( const mypair &lhs, const mypair &rhs)
{
	return lhs.second > rhs.second;
}

int main()
{
	int n;

  ifstream infile;
  infile.open("./sample.txt");
  infile >> n ;
  infile.ignore();

	char ch = 0;
  while( infile >> ch )
  {
		if(isalpha(ch))
     freq[toupper(ch)]++;
	}

	vector<mypair> myvec( freq.begin(), freq.end());
	sort( myvec.begin(), myvec.end(), valueComp);

	vector<mypair>::const_iterator iter;
	for(iter = myvec.begin(); iter != myvec.end(); ++iter)
		cout <<iter->first<<" "<<iter->second<<endl;

	return 0;
}
