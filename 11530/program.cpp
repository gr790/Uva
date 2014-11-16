#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <map>
using namespace std;

map<char, int> freq;
void create_map()
{
	freq['a'] = 1;
	freq['b'] = 2;
	freq['c'] = 3;

	freq['d'] = 1;
	freq['e'] = 2;
	freq['f'] = 3;

	freq['g'] = 1;
	freq['h'] = 2;
	freq['i'] = 3;

	freq['j'] = 1;
	freq['k'] = 2;
	freq['l'] = 3;

	freq['m'] = 1;
	freq['n'] = 2;
	freq['o'] = 3;

	freq['p'] = 1;
	freq['q'] = 2;
	freq['r'] = 3;
	freq['s'] = 4;

	freq['t'] = 1;
	freq['u'] = 2;
	freq['v'] = 3;

	freq['w'] = 1;
	freq['x'] = 2;
	freq['y'] = 3;
	freq['z'] = 4;
}

int solve_sms(string &s)
{
	int len = s.size();
	int cnt = 0;
	for(int i = 0; i < len; ++i)
	{
		if(s[i] == ' ')
			cnt++;
		else
			cnt += freq[s[i]];
	}

	return cnt;
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");

	int test;	
	int k = 0;
	infile >> test;
	infile.ignore();
	string lstr;

	create_map();
	
	while(k++ < test)
	{
		getline(infile, lstr);
		printf("Case #%d: %d\n", k, solve_sms(lstr));
		lstr.clear();
	}

	return 0;
}
