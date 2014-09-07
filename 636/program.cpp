#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
typedef unsigned int uint;
typedef unsigned long long int ullong;
bool validate(string &str, uint orig_b)
{
	bool is_ok = true;
        switch(orig_b)
        {
                default:
                        {
                                int len = str.size();
                                for(int i=0; i < len; ++i)
                                {
                                       if( (str[i]-'0') >= orig_b )
                                       {
                                             is_ok = false;
                                             break;
                                       }
                                }
                        }
                        break;
        }

        return is_ok;
}
ullong to_dec(string &str, uint orig_b)
{
        int len = str.size();
        ullong value = 0;
        for(int i=0; i < len; ++i)
            value += (str[i] - '0') * (long long int)pow(orig_b, len-i-1);
        return value;
}
void solve(string &num)
{
	int start_b = 2;
	int end_b = 100;
	
	for(int i=start_b; i <= end_b; ++i)
	{
		if(validate(num, i))
		{
			ullong dec = to_dec(num, i);
			int n = (int)sqrt(dec); 
			if( n * n == dec)
			{
				cout << i << endl;
				break;
			}
		}
	}

	return;
}

int main()
{
	string num;
	ifstream infile;
	infile.open("./sample.txt");
	while( infile >> num )
	{
		if(num[0] == '0') break;
		solve(num);
		
	}
	return 0;
}
