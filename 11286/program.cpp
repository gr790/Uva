#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	int num;
	/* read no of frosh */
	while(infile >> num)
	{
		infile.ignore();
		if(!num)
			break;
		map< vector<int>, int> pop;
		vector< vector<int> > frosh_rec;
		/* for each frosh, read his subject code */
		while(num--)
		{
			vector<int> sub;
			int c = 0; string line;
			getline(infile, line);
			stringstream ss;
			ss << line;
			while(ss >> c)
				sub.push_back(c);
			sort(sub.begin(), sub.end());
			frosh_rec.push_back(sub);
			pop[sub]++;
			ss.clear();
			sub.clear();
		}
		/* find out the most popular suject combination using begin on map */
		int max_pop_course = 0;
		map< vector<int>, int>::iterator it;
		for(it = pop.begin(); it != pop.end(); ++it)
		{
			if(it->second > max_pop_course)
				max_pop_course = it->second;
		}
		long int nfrosh = 0;
		/* iterate thru map rec and look for max rec in map, which is max popular
 		 * and count the no of frosh */
		for(it = pop.begin(); it != pop.end(); ++it)
		{
			if( it->second == max_pop_course )
				nfrosh += max_pop_course;
		}
		cout << nfrosh << endl;
		pop.clear();
		frosh_rec.clear();
	}
	return 0;
}
