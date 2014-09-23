#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <stdlib.h>
using namespace std;
typedef int BigN[100000];
BigN year;
BigN quo;
int div(int num)
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
void solve(string &str)
{
        int len = str.size();
        year[0] = len;

        for(int i=1; i <= len; ++i)
               year[i] = str[i-1] - '0';
	
	bool fest_year = false;
	bool leap_year = false;
	if( ((div(4) == 0) && (div(100) != 0)) || ( (div(400) == 0)) )
	{
		cout <<"This is leap year." << endl;
		leap_year = true;
	}
	if(div(15) == 0)
	{
		cout <<"This is huluculu festival year." << endl;
		fest_year = true;
	}
	if( (div(55) == 0) && leap_year)
	{
		cout <<"This is bulukulu festival year." << endl;
		fest_year = true;
	}

	if( (!fest_year) && (!leap_year) )
		cout <<"This is an ordinary year." << endl;

}

int main()
{
  freopen("./sample.txt", "r", stdin);
	string lstr;
	vector<string> vs;
	int lines = 0;
	while( cin >> lstr )
	{
		vs.push_back(lstr);
		lstr.clear();
		lines++;
	}

	int i=1;
	vector<string>::iterator it;
	for(it = vs.begin(); it != vs.end(); ++it)
	{
		solve(*it);
		if( i != lines)
			cout << '\n';
		memset(&year, 0, sizeof(year));
		++i;
	}

	return 0;
}
