#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
bool is_prime(int sum)
{
	if( sum == 2) return true;
	if( sum % 2 == 0) return false;
	int m = (int)sqrt(sum);
	for( int i = 3; i <= m; ++i)
	{
		if( sum % i == 0) 
			return false;
	}
	return true;
}
int main()
{
	string lstr;
	ifstream infile;
	infile.open("./sample.txt");

	while ( infile >> lstr )
	{
		int len = lstr.size();
		int sum = 0;
		for(int i = 0; i < len; ++i)
		{
			int x = 0;
			if(islower(lstr[i]))
				sum += (lstr[i]-96);
			else
				sum += (lstr[i]-38);
		}
		if(is_prime(sum))
			cout <<"It is a prime word."<< endl;
		else
			cout <<"It is not a prime word."<< endl;
		lstr.clear();
	}

	return 0;
}
