#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int test;
void rev(string &s, int st, int end)
{
	if( st < end)
	{
		char ch = s[st];
		s[st] = s[end];
		s[end] = ch;
		rev(s, ++st, --end);
	}
}

void count_dig(string &s, int k)
{
	int arr[10] = {0};
	int len = s.size();
	for(int i = 0; i < len; ++i)
	{
		int tmp = s[i] - '0';
		arr[tmp] = arr[tmp] + 1;
	}
	for(int i = 0; i < 10; ++i)
	{
		printf("%d", arr[i]);
		if(i != 9)
			printf(" ");
	}
}
void solve( int num, int k)
{
	string s = "";
	for(int i = 1; i <= num; ++i)
	{
		string ls = "";
		if ( i < 10)
			s += (i + '0');
		else {
			int j = i;
			int rem = 0;
			while(j)
			{
				rem = j%10;
				ls += ( rem + '0');
				j = j/10;
			}
			rev(ls, 0, ls.size()-1);
		}
		s += ls;
		ls.clear();
	}
	count_dig(s, k);
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	
	infile >> test;
	infile.ignore();
	int k = 0;
	
	while(k < test)
	{
		int num;
		infile >> num;
		solve(num, k);
		cout << endl;
		k++;	
	}
	return 0;
}
