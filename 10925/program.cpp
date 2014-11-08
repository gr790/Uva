#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;
typedef int BigN[1000];

BigN a;
BigN result;
BigN costs;

void print(BigN array)
{
	int j = 1;
	while( array[j] == 0)
		j++;
	if( j > array[0])
		cout << '0';
	for(int i = j; i <= array[0]; ++i)
		cout << array[i];
}

void big_add(string &str)
{
	int len = str.size();
	a[0] = len;
	for(int i = 1; i <= len; ++i)
		a[i] =  str[len-i] - '0';

	len = a[0] > result[0] ? a[0] : result[0];
	result[0] = 0;

	int c = 0;
	for(int i = 1; i <= len; ++i)
	{
		int newdig = result[i] + a[i] + c;
		if(newdig > 9)
		{
			result[i] = newdig % 10;
			c = 1;
		}
		else
		{
			result[i] = newdig;
			c = 0;
		}
		++result[0];
	}
	if(c)
		result[++result[0]] = c;
	memset(&a, 0, sizeof(a));

}

void find_avg(int div)
{
	int rem = 0;
	int len = result[0];
	result[0] = 0;
	for(int i = 1; i <= len; ++i)
	{
		rem = (rem * 10) + result[i];
		result[i] = rem / div;
		rem = rem - ( result[i] * div);
		++result[0];
	}
}

void reverse_big()
{
	int half = (int) result[0] / 2;
	for(int i = 0; i < half; ++i)
	{
		int tmp = result[result[0]-i];
		result[result[0]-i] = result[i+1];
		result[i+1] =  tmp;
	}
	for( int i = 0; i <= result[0]; ++i)
		costs[i] = result[i];
}

void solve( vector<string> &vs, int friends, int nip)
{
	vector<string>::iterator it;
	for(it = vs.begin(); it != vs.end(); ++it)
	{
		big_add(*it);
	}
	reverse_big();
	find_avg(friends);
	cout <<"Bill #" << nip <<" costs ";
	print(costs);
	cout <<": each friend should pay ";
	print(result);
	cout << endl;
	
	memset(&result, 0, sizeof(result));
}

int main()
{
	int items, friends;
	ifstream infile;
	infile.open("./sample.txt");
	int nip = 0;
	vector<string> vs;
	while( infile >> items >> friends )
	{

		if( !items && !friends )
			break;
		nip++;
		while(items--)
		{
			string lstr;
			infile >> lstr;
			vs.push_back(lstr);
			lstr.clear();
		}

		solve(vs, friends, nip);
		cout << endl;
		vs.clear();
	}
	
	return 0;
}
