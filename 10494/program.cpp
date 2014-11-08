#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
using namespace std;
typedef int BigN[1000]; 
BigN a;
BigN quo;

void print()
{
	int j = 1;
	int i = 0;
	while( (j <= quo[0]) && ( quo[j] == 0) )
		j++;
	if( j > quo[0])
		cout << i << endl;
	else	
	{
        	for(i = j; i <= quo[0]; ++i)
              		cout << quo[i];
        	cout << endl;
	}
}

void read_big(string &str)
{
        a[0] = str.size();
        for(int i = 1; i <= a[0]; ++i)
                a[i] = str[i-1] - '0';
}
void divide( char symb, unsigned int div)
{
	long long int rem = 0;
	memset(&quo, 0, sizeof(quo));
	for(int i = 1; i <= a[0]; ++i)
	{
		rem = (rem * 10) + a[i];
		quo[i] = rem / div;
		long long int temp = (long long)quo[i] * div;
		rem = rem - temp;
		++quo[0];
	}

	switch(symb)
	{
		case '/':
			print();
			break;
		case '%':
			cout << rem << endl;
			break;
		default:
			break;
	}
}

int main()
{
	char lstr[1000] = {0};
	freopen("./sample.txt", "r", stdin);
	unsigned int div = 0;
	char symb;
	
	while(scanf("%s %c %d", lstr, &symb, &div) != EOF)
	{
		getchar();
		string num(lstr);

		read_big(num);
		divide(symb, div);

		num.clear();

		memset(&a, 0, sizeof(a));
		memset(&lstr, 0, sizeof(lstr));
	}
	return 0;
}
