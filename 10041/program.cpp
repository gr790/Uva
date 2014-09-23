#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

bool valueComp( const int &lhs, const int &rhs)
{
	return lhs < rhs;
}

int main()
{
	int test;
	ifstream infile;
	infile.open("./sample.txt");
	infile >> test;
	infile.ignore();
	
	while(test--)
	{
		int r,n;
		long int median = 0;
		infile >> r;
		vector<int> v;
		while(r--)
		{
			infile >> n;
			v.push_back(n);
		}
		
		sort(v.begin(), v.end(), valueComp);
		int num = v.size();
		if( num%2 == 0)
		{
			median = v[num/2] + v[(num/2)-1];
			median /= 2;
		}
		else
		{
			median = v[num/2];
		}
	
		long long int sum = 0;
		for(int i = 0; i < num; ++i)
		{
			sum += labs(median-v[i]);
		}
		cout << sum << endl;
		v.clear();
	}
	return 0;
}
