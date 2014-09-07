#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
bool valueComp(const int &lhs, const int &rhs)
{
	return lhs < rhs;
}
int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	int test;
	infile >> test;
	infile.ignore();
	while(test--)
	{
		int s, a, f;
		infile >> s >> a >> f;
		vector<int> st;
		vector<int> av;
		int i, j;
		int k = f;
		while(k--)
		{
			infile >> i >> j;
			st.push_back(i);
			av.push_back(j);
		}
		sort(st.begin(), st.end(), valueComp);
		sort(av.begin(), av.end(), valueComp);
		int median_st = 0, median_av = 0;
		if(f%2 == 0)
		{
			median_st = st[(f-1)/2];
			median_av = av[(f-1)/2];
		}
		else
		{
			median_st = st[f/2];
			median_av = av[f/2];
		}
		
		printf("(Street: %d, Avenue: %d)\n", median_st, median_av);
		st.clear();av.clear();
	}
	return 0;
}
