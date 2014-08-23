#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	
	int test;
	infile >> test;
	infile.ignore();

	while(test--)
	{
		string s;
		getline(infile, s);
		int len = s.size();
		
		int sq = sqrt(len);
		if( len != sq * sq )
		{
			cout <<"INVALID" << endl;
			continue;
		}
		int n;
		n = sq;
		for(int i = 0; i < n; ++i)
		{
			for(int j = i; j < len; j+=n)
				cout << s[j];
		}
		cout << endl;
		s.clear();
		
	}

	return 0;
}
