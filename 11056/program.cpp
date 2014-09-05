#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include <string.h>

typedef unsigned long long int ULL;

using namespace std;

ULL cal_time(int m, int s, int ms)
{
	unsigned long long int t;
	t = (m * 60000) + (s * 1000) + ms;
	return t;
}

bool valueComp( const pair<string, ULL> &lhs, const pair<string, ULL> &rhs)
{
	if ( lhs.second < rhs.second )
		return true;
	else if ( lhs.second == rhs.second )
	{
		for (string::const_iterator c1 = lhs.first.begin(), c2 = rhs.first.begin(); 
			(c1 != lhs.first.end() && c2 != rhs.first.end());  ++c1, ++c2) 
		{
        		if (tolower(*c1) < tolower(*c2)) 
            			return true;
			else if (tolower(*c1) > tolower(*c2) )
				return false;
        	}
	}
	
	return false;	
}

typedef pair<string, ULL> mypair;

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	stringstream ss;

	while(!infile.eof())
	{
		string name;
		int m, s, ms;
		int r;
		infile >> r;
		infile.ignore();
		multimap<string, ULL> driver;
		
		while(r--)
		{
			string str, dump;
			char c;
			getline(infile, str);
			ss << str;
			ss >> name >> c >> m >> dump >> s >> dump >> ms >> dump;
			driver.insert(make_pair(name, cal_time(m,s, ms)));
			ss.clear();
		}
		infile.ignore();

		vector<mypair> myvec(driver.begin(), driver.end());
		sort(myvec.begin(), myvec.end(), valueComp);
		vector<mypair>::iterator it;
		bool print = false;
		int row = 0,j = 0;

		for(it = myvec.begin(); it != myvec.end(); ++it)
		{
			if(!print)
			{
				printf("Row %d\n", ++row);
				print = true;
			}
			cout << it->first << endl;
			j++;
			if(j == 2)
			{
				print = false;
				j = 0;
			}
		}

		driver.clear();
		myvec.clear();
		cout << endl;
	}

	return 0;
}
