#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
#define U(x)	((x >= 'A' && x <= 'Z') ? ( x + 32) : x)
char grid[51][51] = {0};
int rows,cols;
typedef pair<int, int> mypair;
vector<mypair>pos;

bool valueComp(const mypair &lhs, const mypair &rhs)
{
	if( lhs.first < rhs.first )
		return true;
	if( lhs.first == rhs.first )
	{
		return lhs.second < rhs.second;
	}
	
	return false; 
}

void low(string &s)
{
	int len = s.size();
	for(int i = 0; i < len; ++i)
		s[i] = U(s[i]);
}

void to_lower()
{
	for( int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < cols; ++j)
			grid[i][j] = U(grid[i][j]);
	}
}

bool is_prefix(const string &prefix, const string &word)
{
	if(word.size() < prefix.size())
		return false;
	for(int i = 0; i < prefix.size(); ++i)
		if(prefix[i] != word[i])
			return false;
	return true;	
}

void solve_direction( int r, int c, int rd, int cd, string &p)
{ 
	int i,j;
	string word = "";
	word = grid[r][c];
	for(i = r + rd, j = c + cd; i >= 0 && j >= 0 && i < rows && j < cols; i += rd, j += cd)
	{
		word += grid[i][j];
		if( !is_prefix(word, p))
			break;
		
		if(p == word)
			pos.push_back(make_pair(r+1,c+1));
	}
	return ; 
}

void solve(string &p)
{
	for(int i = 0; i < rows; ++i)
		for(int j = 0; j < cols; ++j)
			for(int rd = -1; rd <= 1; ++rd)
				for( int cd = -1; cd <= 1; ++cd)
					if( rd != 0 || cd != 0)
						solve_direction(i, j, rd, cd, p);

	sort(pos.begin(), pos.end(), valueComp);
}


int main()
{
	int test;
	ifstream infile;
	vector<string> vs;
	infile.open("./10010.txt");
	infile >> test;
	infile.ignore();

	rows = cols = 0;
	int p = 0;
	while(p < test)
	{
		p++;
		infile >> rows >> cols;
		for( int i = 0; i < rows; ++i)
			for(int j = 0; j < cols; ++j)
				infile >> grid[i][j];
		to_lower();
		int k = 0;
		infile >> k;
		string str;
		while(k--)
		{
			infile >> str;
			low(str);
			vs.push_back(str);
			str.clear();
		}

		vector<string>::iterator it;
		for(it = vs.begin(); it != vs.end(); ++it)
		{
			solve(*it);
			cout << pos.front().first <<" "<< pos.front().second << endl;
			pos.clear();
		}
		vs.clear();
		memset(&grid, 0, sizeof(grid));
		if(p != test)
			cout << endl;
	}
	
	return 0;
}
