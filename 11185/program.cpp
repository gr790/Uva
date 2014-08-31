#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void reverse( string &s, int start, int end)
{
        if( start < end )
        {
                char tmp = s[start];
                s[start] = s[end];
                s[end] = tmp;
                reverse( s, ++start, --end);
        }
}
void solve( long int num)
{
	string value;
	if( num == 0 )
	{
		cout << '0' << endl;
		return;
	}
        while(num)
        {
                int rem = num % 3;
                value += ( rem + '0');
                num = num / 3;
        }
        reverse(value, 0, value.size() - 1);
	cout << value << endl;
}
int main()
{
	long int num;
	ifstream infile;
	infile.open("./sample.txt");
	while( infile >> num )
	{
		if ( num < 0 )
			break;
		solve(num);
	}
	return 0;
}
