#include <iostream>
#include <fstream>

using namespace std;

void reverse(string &str, int start, int end)
{

        if( start < end )
        {
                char tmp = str[start];
                str[start] = str[end];
                str[end] = tmp;
                reverse(str, ++start, --end);
        }

        return;
}


int to_binary(int dec, string &bin)
{
	int count = 0;
        while(dec)
        {
                int rem = dec % 2;
		if(rem) count++;
                bin += rem + '0';
                dec = dec / 2;
        }
        reverse(bin, 0, bin.size()-1);

	return count;
}

void solve( int num)
{
	int count = 0;
	string bin;
	count = to_binary(num, bin);
	cout <<"The parity of " << bin <<" is "<< count <<" (mod 2)." << endl;
	
}

int main()
{
	int num = 0;
  freopen("./sample.txt", "r", stdin);

	while ( cin >> num )
	{
		if(!num) break;
		solve(num);
	}
	return 0;
}
