#include <iostream>
#include <fstream>
#include <map>
#include <math.h>
#include <iomanip>
using namespace std;

int gpf[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
const int gpf_size = sizeof(gpf)/sizeof(gpf[0]);

int main()
{
	ifstream infile;
	infile.open("./sample.txt");

	int num;
	while( infile >> num )
	{
		if(!num)
			break;
		map<int, int> freq;
		if( num < 2)
			continue;
		long int fact = 1;
		cout << setw(3) << right << num <<'!'<<" =";
		for(int i = num; i >= 1; --i)
		{
			fact *= i;
			int sq = ceil(sqrt(fact));
			for(int j = 0; (j <= gpf_size && gpf[j] <= sq); ++j)
			{
				do
				{
					int rem = fact%gpf[j];
					if(!rem)
					{
						freq[gpf[j]]++;
						fact = fact/gpf[j];
					}
					else
						break;
				}while(fact!=1);
			}
		}
		map<int, int>::iterator it;
		int cnt = 0;
		int size = freq.size();
		for(it = freq.begin(); it != freq.end(); ++it)
		{
			cnt++;
			printf("%3d", it->second);
			if(size > 15 && cnt%15==0)
			{
				cout << endl;
				cout <<"      ";
			}
		}
		cout << endl;
		freq.clear();
	}

	return 0;
}

