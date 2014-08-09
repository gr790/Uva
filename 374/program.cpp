#include <iostream>
#include <fstream>
using namespace std;

long rep_sq(int b, int p)
{
	if(p==1) return b;
	if(p%2==0)
		return rep_sq(b*b, p/2);
	else
		return b * rep_sq(b*b, (p-1)/2);
}

long int big_mod(int b, int p, int m)
{
	if(b==0) return 0;
	if(p==1) return b%m;
	if(p == 0) return 1;
	if(p%2 == 0)
		return big_mod(b, p/2, m)%m * big_mod(b, p/2, m)%m;
	else
		return (b%m) * big_mod((b%m)*(b%m), (p-1)/2, m)%m;
	
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	int b, p, m;
	while( infile >> b )
	{
		infile >> p;
		infile >> m;

		cout << big_mod(b, p, m) << endl;
	}

	return 0;
}
