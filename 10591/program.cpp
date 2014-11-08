#include <iostream>
#include <fstream>
#include <map>
using namespace std;

bool is_happy( int num)
{
	bool happy = false;
	unsigned long int sum = 0;
	int orig = num;
	map<int, int> mymap;
	while(num)
	{
		int newd = num % 10;
		sum += (newd * newd);	
		num = num / 10;
		if(num==0)
		{
			if( mymap[sum] )
			{
				happy = false;	
				break;
			}
			mymap[sum]++;
			if(sum == 1)
			{
				happy = true;	
				break;
			}
			num = sum;
			sum = 0;
		}
	}	
	return happy;
}
int main()
{
	int test;
	ifstream infile;
	infile.open("./sample.txt");
	infile >> test;
	infile.ignore();

	int k = 0;
	while( k++ < test )
	{
		unsigned int num;
		infile >> num;
		if(is_happy(num))
			printf("Case #%d: %d is a Happy number.\n", k, num);
		else
			printf("Case #%d: %d is an Unhappy number.\n", k, num);
	}

	return 0;
}
