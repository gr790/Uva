#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	
	int test,k = 0;
	infile >> test;
	infile.ignore();
	stringstream ss;
	string lstr;
	vector<int> v;

	while(k < test )
	{
		k++;
		getline(infile, lstr);
		ss << lstr;
		int np;
		while( ss >> np )
			v.push_back(np);
		sort(v.begin(), v.end());
	
		cout <<"Case "<< k <<": " << v[1] << endl;
		v.clear();
		ss.clear();
		lstr.clear();
	}

	return 0;
}
