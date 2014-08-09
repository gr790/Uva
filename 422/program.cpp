#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
#define U(x)	((x >= 'a' && x <= 'z') ? ( x - 32) : x)

char grid[101][101] = {0};
int rows;

void up(string &s)
{
	int len = s.size();
	for(int i = 0; i < len; ++i)
		s[i] = U(s[i]);
}

void to_upper()
{
	for( int i = 0; i < rows; ++i)
		for(int j = 0; j < rows; ++j)
			grid[i][j] = U(grid[i][j]);
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

bool solve_direction( int r, int c, int rd, int cd, string &p)
{ 
	int i,j;
	string word = "";
	word = grid[r][c];
	for(i = r + rd, j = c + cd; i >= 0 && j >= 0 && i < rows && j < rows; i += rd, j += cd)
	{
		word += grid[i][j];
		if( !is_prefix(word, p))
			break;
		
		if(p == word)
		{
			cout << r+1 <<','<< c+1 <<" "<< i+1 <<',' << j+1 << endl;
			return true;
		}
	}
	return false; 
}

bool solve(string &p)
{
	bool found = false;
	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < rows; ++j) {
			for(int rd = -1; rd <= 1; ++rd) {
				for( int cd = -1; cd <= 1; ++cd) {
					if( rd != 0 || cd != 0)
					{
						found = solve_direction(i, j, rd, cd, p);
						if(found)
							return true;
					}
				}
			}
		}
	}

	return found;
}


int main()
{
	int test;
	ifstream infile;
	vector<string> vs;
	infile.open("./sample.txt");

	int p = 0;
	infile >> rows;
	infile.ignore();
	for( int i = 0; i < rows; ++i)
		for(int j = 0; j < rows; ++j)
			infile >> grid[i][j];

	to_upper();
	string str;
	while(infile >> str)
	{
		if(str[0] == '0')
			break;
		up(str);
		vs.push_back(str);
		str.clear();
	}

	vector<string>::iterator it;
	bool found = false;
	for(it = vs.begin(); it != vs.end(); ++it)
	{	
		found = solve(*it);
		if(!found)
			cout <<"Not found"<<endl;
	}
	vs.clear();
	memset(&grid, 0, sizeof(grid));
	return 0;
}
