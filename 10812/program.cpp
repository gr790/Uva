#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main()
{
	ifstream infile;
	infile.open("./sample.txt");

	int test;
	infile >> test;
	infile.ignore();
	int s, d;
	
	while(test--)
	{
		infile >> s >> d;
		if( s < d)
		{
			cout <<"impossible"<< endl;
			continue;
		}
		else if( (s+d)%2) 
		{
			cout <<"impossible"<< endl;
			continue;
		}
		else if( (abs(s-d))%2)
		{
			cout <<"impossible"<< endl;
			continue;
		}
		
		cout << (s+d)/2 <<" "<< abs(s-d)/2 << endl;
	}
	return 0;
}
