#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

typedef int BigN[100000];

int result[1000][1000] = {0};

BigN a;
BigN b;
BigN final;
int max_rows = 0;

void print(BigN num)
{
	int j = 1;
	while( num[j] == 0)
		j++;
	if( j > num[0])
		cout << '0' << endl;
	else
	{
		for(int i = j; i <= num[0]; ++i)
			cout << num[i];
		cout << endl;
	}
}

void reverse_big()
{
        int half = (int) final[0] / 2;
        for(int i = 0; i < half; ++i)
        {
                int tmp = final[final[0]-i];
                final[final[0]-i] = final[i+1];
                final[i+1] =  tmp;
        }
}


void read_big(string &s, BigN arr)
{
	int len = s.size();
	arr[0] = len;
	for(int i = 1; i <= len; ++i)
		arr[i] = s[len-i] - '0';
}

void sum(void)
{
	memset(&final, 0, sizeof(final));
	for(int i = 0; i < max_rows; ++i)
	{
		int len = result[i][0] > final[0] ? result[i][0] : final[0];
		final[0] = 0;
		int c = 0;
		for(int j = 1; j <= len; ++j)
		{
			int newdig = result[i][j] + final[j] + c;
			final[j] = newdig % 10;
			c = newdig / 10;
			++final[0]; 
		}
	
		if(c)
			final[++final[0]] = c;
	}
	reverse_big();
	print(final);
	memset(&final, 0, sizeof(final));

	for(int i = 0; i < 1000; ++i)
		for(int j = 0; j < 1000; ++j)
			result[i][j] = 0;
	
}

void solve(string &str1, string &str2)
{
	read_big(str1, a);
	read_big(str2, b);

	int k = 0;
	int l = 1;
	for( int i = 1; i <= a[0]; ++i)
	{
		result[k][0] = 0;
		for(int j = 1; j < l; ++j)
		{
			result[k][j] = 0;
			++result[k][0];
		}
		int c = 0;
		for( int j = 1; j <= b[0] || c; ++j)
		{
			int newdig = (a[i] * b[j]) + c;
			result[k][l] = newdig % 10;
			c = newdig / 10;
			++result[k][0];
			++l;
		}
		l = k + 2;
		k++;
	}
	max_rows = k;
	memset(&a, 0, sizeof(a));
	memset(&b, 0, sizeof(b));
	sum();
	
}


int main()
{
	string lstr1, lstr2;
	ifstream infile;
	infile.open("./sample.txt");
	while( infile >> lstr1 )
	{
		infile >> lstr2;

		cout << lstr1 <<' '<< lstr2 << endl;

		solve(lstr1, lstr2);
		lstr1.clear();
		lstr2.clear();
	}

	return 0;
}
