#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long int ullong;

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

void to_binary(ullong dec, string &bin)
{
	while(dec)
	{
		int rem = dec % 2;
		bin += rem + '0';
		dec = dec / 2;
	}
	for(int i = bin.size(); i <= 12; ++i)
		bin += '0';
	reverse(bin, 0, bin.size()-1);
}

ullong to_dec( string &str)
{
	ullong dec = 0;
	int len = str.size();
	for(int i=0; i < len; ++i)
	{
		if( (str[i] >= '0') && (str[i] <= '9'))
			dec += ( str[i] - '0') * (long long int) pow(16, len-i-1);
		if( (str[i] >= 'A') && (str[i] <= 'F'))
			dec += ( str[i] + 10 - 'A') * (long long int) pow(16, len-i-1);
	}

	return dec;
}

void solve( string &num1, string &symb, string &num2)
{
	char op = symb[0];
	string bin1, bin2;

	ullong dec1 = to_dec(num1);
	to_binary(dec1, bin1);

	ullong dec2 = to_dec(num2);
	to_binary(dec2, bin2);

	if( op == '+')
		cout << bin1 <<' '<< symb <<' '<< bin2 <<" = "<< dec1 + dec2 << endl;
	else if( op == '-')
	{
		if( dec1 > dec2 )
			cout << bin1 <<' '<< symb <<' '<< bin2 <<" = "<< dec1 - dec2 << endl;
		else
			cout << bin2 <<' '<< symb <<' '<< bin1 <<" = "<< dec2 - dec1 << endl;
	}
}

int main()
{
	uint n;
  freopen("./sample.txt", "r", stdin);

	cin >> n;
	cin.ignore();

	istringstream ss;
	string num1, num2, symb;

	while(n--)
	{
		string lstr;
		getline(cin, lstr);
		ss.str(lstr);
		
		ss >> num1;
		ss >> symb;
		ss >> num2;
	
		solve(num1, symb, num2);

		ss.clear();
		lstr.clear();
	}

	return 0;
	
}
