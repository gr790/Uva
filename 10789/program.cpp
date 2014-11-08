#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <bitset>
#include <math.h>
#include <algorithm>
using namespace std;

/* Prime Number */

#define SIZE 1000000LL
bitset<SIZE+1> prime;

void sieve()
{
        int sq = ceil(sqrt(SIZE));
        for(int i = 2; i <= sq; ++i)
        {
                if(!prime.test(i))
                {
                        for(int j = i*i; j <= SIZE; j += i)
                                prime.set(j,1);
                }
        }
}

bool is_sieve_prime(int num)
{
	if(num < 2) 
		return false;
        return !prime.test(num);
}

void prime_count(string &s, string &ns)
{
	int len = s.size();
	map<char, int> freq;
	for(int i = 0; i < len; ++i)
	{
		freq[s[i]]++;
	}
	map<char, int>::iterator it;
	for(it = freq.begin(); it != freq.end(); ++it)
	{
		if(is_sieve_prime(it->second))
			ns += it->first;
	}
	freq.clear();
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	int test;
	infile >> test;
	infile.ignore();
	sieve();

	string lstr;
	int k = 0;

	while(k < test)
	{
		k++;
		infile >> lstr;
		string ns = "";
		prime_count(lstr, ns);
		cout <<"Case " << k << ": ";
		if(ns == "")
			cout << "empty" << endl;
		else
		{
			sort(ns.begin(), ns.end());
			cout << ns << endl;
		}
		lstr.clear();
		ns.clear();
	}
	return 0;
}
