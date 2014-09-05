#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
 * 0, succes
 * 1, WA
 * 2, Output Format Error
 */

void format(string &s)
{
	int l = s.size();
	int j;
	for(int i = 0,j = 0; i < l; ++i)
	{
		if(s[i] != ' ')
			s[j++] = s[i];
	}
}

int match(string &user, string &judge)
{
	if(user == judge)
		return 0;
	format(user);
	format(judge);
	int len1 = user.size();
	int len2 = judge.size();
	for(int i = 0, j = 0; (i < len1 && j < len2); ++i, ++j)
	{
		if( user[i] != judge[i] )
			return 1;
	}
	return 2;
}

int main()
{
	int test;
	int k = 0;
	ifstream infile;
	infile.open("./sample.txt");

	infile >> test;
	infile.ignore();
	while(k < test)
	{
		string user,judge;
		getline(infile, user);
		getline(infile, judge);
		k++;

		int out = match(user, judge);
		if(!out)
			printf("Case %d: Yes\n", k);
		if(out == 1)
			printf("Case %d: Wrong Answer\n", k);
		else if(out == 2)
			printf("Case %d: Output Format Error\n", k);
		user.clear();
		judge.clear();
	}

	return 0;
}
