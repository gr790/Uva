#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <stdlib.h>
using namespace std;
typedef int BigN[100];
string start = "2148";
BigN c_year;
BigN s_year;
BigN l_year;
BigN result;
BigN final;
BigN quo;
int div(BigN year, int num)
{
	int tmp = 0;
	memset(&quo, 0, sizeof(quo));
	for(int i = 1; i <= year[0]; ++i)
	{
		tmp = (tmp * 10) + year[i];
		quo[i] = tmp / num;
		tmp -= (quo[i] * num);
		++quo[0];
	}
	return tmp;
}

void read_leap(string &str, BigN year)
{
        year[0] = str.size();

        for(int i=1; i <= year[0]; ++i)
               year[i] = str[i-1] - '0';
}

void read_big(string &str, BigN year)
{
        year[0] = str.size();

        for(int i=1; i <= year[0]; ++i)
               year[i] = str[year[0]-i] - '0';
}

void sub(BigN start, BigN current)
{
	int len = start[0] > current[0] ? start[0] : current[0];
	int j = 1, k = 0;
	for (int i = 1; i <= len; ++i)
	{
		if( current[i] < start[i] )
		{
			k = i;
			while(current[++k] == 0)
				;
			current[k]--;
			k--;
		 	while (k > i)
			{
				current[k] = 9;
				k--;
			}
			current[i] = current[i] + 10;
			result[j] = current[i] - start[i];

		}
		else
		{
			result[j] = current[i] - start[i];
		}
		j++;
		++result[0];
	}
	
	while( (result[result[0]] == 0) && (result[0] > 0) )
		result[0]--;
	
	final[0] = result[0];
	for(int i=0; i <= result[0]; ++i)
		final[i+1] = result[result[0] - i];
}

int compare(BigN current, BigN start)
{
	if( current[0] < start[0] )
		return -1;
	if( current[0] > start[0] )
		return 1;
	else
	{
		for(int i=current[0]; i > 0; --i)
		{
			if( current[i] < start[i] )
				return -1;
			else if( current[i] > start[i] )
				return 1;
		}
	}

	return 1;
}

void solve(string &str)
{
	read_big(str, c_year);
	read_leap(str, l_year);
	read_big(start, s_year);
	if(compare(c_year, s_year) < 0)
	{
		cout <<"No ghost will come in this year" << endl;
		return;
	}
	sub(s_year, c_year);
	bool ghost_found = false;
	if(div(final, 2) == 0) {
		cout <<"Ghost of Tanveer Ahsan!!!" << endl;
		ghost_found = true;
	}if (div(final, 5) == 0) {
		cout <<"Ghost of Shahriar Manzoor!!!" << endl;
		ghost_found = true;
	}if (div(final, 7) == 0) {
		cout <<"Ghost of Adrian Kugel!!!" << endl;
		ghost_found = true;
	}if (div(final, 11) == 0) {
		cout <<"Ghost of Anton Maydell!!!" << endl;
		ghost_found = true;
	}if (div(final, 15) == 0) {
		cout <<"Ghost of Derek Kisman!!!" << endl;
		ghost_found = true;
	}if (div(final, 20) == 0) {
		cout <<"Ghost of Rezaul Alam Chowdhury!!!" << endl;
		ghost_found = true;
	}if (div(final, 28) == 0) {
		cout <<"Ghost of Jimmy Mardell!!!" << endl;
		ghost_found = true;
	}if (div(final, 36) == 0) {
		cout <<"Ghost of Monirul Hasan!!!" << endl;
		ghost_found = true;
	}if( ((div(l_year, 4) == 0) && (div(l_year, 100) != 0)) || ( (div(l_year, 400) == 0)) )
	{
		cout <<"Ghost of K. M. Iftekhar!!!" << endl;
		ghost_found = true;
	}
	if(!ghost_found) {
		cout <<"No ghost will come in this year" << endl;
	}
}

int main()
{
	string lstr;
	vector<string> vs;
	ifstream infile;
	infile.open("./sample.txt");
	int lines = 0;
	while( infile >> lstr )
	{
		if(lstr[0] == '0')
			break;
		vs.push_back(lstr);
		lstr.clear();
		lines++;
	}

	int i=1;
	vector<string>::iterator it;
	for(it = vs.begin(); it != vs.end(); ++it)
	{
		cout << *it << endl;
		solve(*it);
		if( i != lines)
			cout << '\n';
		memset(&c_year, 0, sizeof(c_year));
		memset(&s_year, 0, sizeof(s_year));
		memset(&l_year, 0, sizeof(l_year));
		memset(&result, 0, sizeof(result));
		memset(&final, 0, sizeof(final));
		++i;
	}
	return 0;
}
