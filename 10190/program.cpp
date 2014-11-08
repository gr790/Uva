#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> v;

bool gcd( int n , int m )
{
	bool is_boring = false;
	while(n!=1)
	{
		v.push_back(n);
		int q = n / m;
		int r = n - (q * m);
		if(r!=0)
		{
			is_boring = true;
			break;
		}
		n = q;
	}
	return is_boring;
}

int main()
{
	int n, m;
	ifstream infile;
	infile.open("./sample.txt");
	
	while ( infile >> n >> m )
	{
		if( n < 2 || m < 2) 
		{
			printf("Boring!\n");
			continue;
		}
		
			
		if(!gcd(n, m))
		{
			vector<int>::iterator it;
			for(it = v.begin(); it != v.end(); ++it)
				printf("%d ", *it);
			printf("1");
		}
		else
			printf("Boring!");
		printf("\n");
		v.clear();
	}

	return 0;

}
