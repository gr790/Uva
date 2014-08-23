#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;

int hex_to_dec(string &s)
{
	int len = s.size();
	int sum = 0;
	for(int i = 0; i < len; ++i)
	{
		sum += (s[i] * pow(16,i));
	}
	
	return sum;
	
}

int count_1(int n)
{
	int cnt = 0;
	while(n)
	{
		n = n&n-1;
		cnt++;
	}
	return cnt;
}

void to_hex(int num, string &hex)
{
	while(num)
	{
		hex += num % 10;
		num = num/10;
	}
}

void solve(int num)
{
	int dec_cnt = count_1(num);

	string hex;
	to_hex(num, hex);
	int hex_dec = hex_to_dec(hex);
	int hex_cnt = count_1(hex_dec);

	cout << dec_cnt <<" "<< hex_cnt <<endl;
}

int main()
{
	int test;
	ifstream infile;
	infile.open("./sample.txt");

	infile >> test;
	infile.ignore();
	int k = 0;
	
	while( k < test )
	{
		int num = 0;
		infile >> num;
		solve(num);
		k++;
	}	

	return 0;
}
