#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	int test;
	infile >> test;
	while(test--)
	{
		double len;
		infile >> len;
		double wdt = (double)(len * 60)/100.00;
		double rad = (double)(len * 20)/100.00;
		double tot = len * wdt;
		
		double red = (double)(acos(-1) * rad * rad);
		double grn = (double)(tot - red);
		printf("%.2f %.2f\n", red, grn);
	}
	return 0;
}
