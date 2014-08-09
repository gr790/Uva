#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	int num;
	vector<int> v;
	ifstream infile;
	infile.open("./sample.txt");

	printf("PERFECTION OUTPUT\n");
	while( infile >> num)
	{
		if(!num)
			break;
		long long int sum = 0;
		int m = (int)num/2;
		for(int i = 1; i <= m; ++i)
		{
			if(num%i == 0)
				sum += i;
		}
		if(sum == num)
			cout << right << setw(5) << num <<"  PERFECT" << endl;
		else if ( sum < num )
			cout << right << setw(5) << num <<"  DEFICIENT" << endl;
		else if ( sum > num )
			cout << right << setw(5) << num <<"  ABUNDANT" << endl;
	}
	printf("END OF OUTPUT\n");

	return 0;
}
