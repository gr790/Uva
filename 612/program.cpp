#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int bsort(string s)
{
	int op = 0;
	int len = s.size();
	for(int i = 0; i < len; ++i)
	{
		for(int j = 0; j < len-i-1; ++j)
		{
			if(s[j] > s[j+1])
			{
				char ch = s[j];
				s[j] = s[j+1];
				s[j+1] = ch;
				op++;
			}
		}
	}
	
	return op;
}

bool valueComp( const pair<string,int> &lhs, const pair<string, int> &rhs)
{
	return lhs.second < rhs.second;
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");

	int test,k=0;
	infile >> test;
	infile.ignore();
	infile.ignore();

	while(k < test)
	{
		int len, num;
		string str;
		infile >> len >> num;
		k++;
		typedef pair<string, int> mypair;
		vector<mypair> dna;

		int i=0;
		while(i++ < num)
		{
			infile >> str;
			int cnt = bsort(str);
			dna.push_back(make_pair(str, cnt));
			str.clear();
			
		}
		infile.ignore();

		stable_sort(dna.begin(), dna.end(), valueComp);
		vector<mypair>::iterator it;
		for(it = dna.begin(); it != dna.end(); ++it)
			cout << it->first << endl;

		if(k != test)
			cout << endl;
		dna.clear();
	}
	return 0;
}
