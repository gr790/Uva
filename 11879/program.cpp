#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
using namespace std;

typedef int BigN[10000];
BigN num;
BigN quo;

void print(BigN a)
{
	cout << a[0] <<' ';
	for( int i = 1; i <= a[0]; ++i)
		cout << a[i];
	cout << endl;
}

void is_17( string &s)
{
	num[0] = s.size();
	for(int i = 0; i < num[0]; ++i)
		num[i+1] = s[i] - '0';

	print(num);
	memset(&quo, 0, sizeof(quo));

	int tmp = 0;
	for(int i = 1; i <= num[0]; ++i)
	{
		tmp = (tmp * 10) + num[i];
		quo[i] = tmp / 17;
		tmp = tmp - ( quo[i] * 17 );
		quo[0]++;
	}
	if(tmp == 0)
		cout <<"1"<< endl;
	else
		cout <<"0"<<endl;
}
int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	string lstr;

	while( infile >> lstr )
	{
		if( lstr == "0")
			break;

		is_17(lstr);
		lstr.clear();
	}

	return 0;
}
