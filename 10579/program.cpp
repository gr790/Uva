#include <iostream>
#include <fstream>
using namespace std;

// Big Number Fabonacci Series 

int table[20001][50000] = {0};

void print_fab(int num)
{
  int len = table[num][0];
  for(int i = len; i > 0; --i)
		cout << table[num][i];
	cout << endl;
}
void calc_fab(int i)
{
	int len = table[i-1][0] > table[i-2][0] ? table[i-1][0] : table[i-2][0];
	int carry, tmp;
	carry = tmp = 0;
	for(int j=1; j <= len; ++j)
	{
		int newdig = table[i-1][j] + table[i-2][j] + carry;
		table[i][j] = newdig % 10;
		carry = newdig / 10;
		tmp++;
		table[i][0] = tmp;
	}

	if(carry)
		table[i][++table[i][0]] = carry;
}

void pre_cal()
{
	table[0][0] = 1;
	table[0][1] = 0;

	table[1][0] = 1;
	table[1][1] = 1;
	int i;
	for(i=2; i < 20001; ++i)
		calc_fab(i);
}


int main()
{

	pre_cal();
	unsigned int num;
	ifstream infile;
	infile.open("./sample.txt");
	while( infile >> num )
	{
		print_fab(num);
	}

	return 0;
}
