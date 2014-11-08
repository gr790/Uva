#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

typedef unsigned long long int ULL;

ULL table[21];

void fact()
{
	table[0] = 1;
	for(int i = 1; i <= 21; ++i)
		table[i] = i * table[i-1];
}

int main()
{
	freopen("./sample.txt", "r", stdin);

	int test;
	cin >> test;
	cin.ignore();
	fact();

	string word;

	int k = 0;
	while(k++ < test)
	{
		cin >> word;
		int len = word.size();
		map<char, int> freq;
		for(int i = 0; i < len; ++i)
		{
			freq[word[i]]++;
		}
		map<char, int>::iterator it;
		ULL fac = table[len];
		for(it = freq.begin(); it != freq.end(); ++it)
		{
			int p = it->second;	
			if( p > 1)
			{
				fac /= table[p];
			}
		}
		
		printf("Data set %d: %lld\n", k, fac);
	}

	return 0;
}
