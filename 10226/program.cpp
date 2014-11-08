#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	freopen("./sample.txt", "r", stdin);
	int test;
	scanf("%d\n\n", &test);
	map<string, int> forest;
	int k = 0;
	while(k < test)
	{
		k++;
		int ntree = 0;
		string tree;
		while ( getline(cin, tree) )
		{
			if( tree.empty())
				break;
			forest[tree]++;
			ntree++;
			
		}
		map<string, int>::iterator it;
		for(it = forest.begin(); it != forest.end(); ++it)
		{
			double st = double( (it->second) * 100.00)/ntree;
      cout << it->first <<' ';
      printf("%.4f\n", st);
		}
		if(k != test)
			cout << endl;
		forest.clear();
	}
	return 0;
}
