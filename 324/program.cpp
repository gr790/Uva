#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

int fact[1001][3000];
int count[10];
void calc_fact(void)
{
	fact[0][0] = 1; 
	fact[0][1] = 1; 
	int i;
	for(i=1; i <= 1000; ++i)
	{
		int carry = 0;
		int j=1, tmp=0;
		for(j; (j <= fact[i-1][0]) || (carry) ; ++j)
		{
			int digit = (fact[i-1][j] * i ) + carry;
			fact[i][j] = digit % 10;
			carry = digit / 10;
			tmp++;
			fact[i][0] = tmp;
		}
	}
}

void count_dig(int num)
{
	for(int i=1; i <= fact[num][0]; ++i)
	{
		int tmp = fact[num][i];
		++count[tmp];
	}
}

void print_format(int num)
{
	cout << num <<"! --" << endl;
	for(int i=0; i <= 9; ++i)
	{
		if( i == 5) cout <<'\n';
		cout << right << setw(4) << "(" << i << ")" << right << setw(4) << count[i]; 
	}
	cout << endl;
}

int main()
{
	calc_fact();
	int n;
	ifstream infile;
	infile.open("./sample.txt");
	while( infile >> n) 
	{
		if(!n) break;
		count_dig(n);
		print_format(n);	
		memset(&count,0, sizeof(count));
	}
	return 0;
}


