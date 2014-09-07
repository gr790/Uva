#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>

using namespace std;

typedef int BigN[10000]; 

BigN a;
BigN b;
BigN result;

void print(BigN num)
{

	int j = 1;
	while(num[j] == 0)
		j++;
        for(int i = j; i <= num[0]; ++i)
                cout << num[i];
        cout << endl;
}


void reverse(string &str, int start, int end)
{
        if( start < end )
        {
                char tmp = str[start];
                str[start] = str[end];
                str[end] = tmp;
                reverse(str, ++start, --end);
        }
}


void read_big(string &str1, string &str2)
{
        a[0] = str1.size();
        for(int i = 1; i <= a[0]; ++i)
                a[i] = str1[a[0]-i] - '0';

        b[0] = str2.size();
        for(int i = 1; i <= b[0]; ++i)
                b[i] = str2[b[0]-i] - '0';
}

void add( BigN a, BigN b, BigN result)
{
        int len = a[0] > b[0] ? a[0] : b[0];
        int i, c = 0;

        for(i=1; i<=len; ++i)
        {
                int newdig = a[i] + b[i] + c;
                if(newdig > 9)
                {
                        result[i] = newdig % 10;
                        c = 1;
                }
		else
		{
			result[i] = newdig;
			c = 0;
		}
		result[0]++;
        }

        if(c != 0)
                result[++result[0]] = c;
}


void solve()
{

	add(a,b, result);
	print(result);
}

int main()
{
	int test;
	ifstream infile;
	istringstream ss;
	infile.open("./sample.txt");
	
	infile >> test;
	infile.ignore();

	while(test--)
	{

		
		string lstr, a_str, b_str;
		getline(infile, lstr);
	
		ss.str(lstr);
		ss >> a_str;
		ss >> b_str;

		reverse(a_str, 0, a_str.size()-1);
		reverse(b_str,0, b_str.size()-1);

		read_big(a_str, b_str);
		solve();

		a_str.clear();
		b_str.clear();
		lstr.clear();
		ss.clear();
		memset(&a, 0, sizeof(a));
		memset(&b, 0, sizeof(b));
		memset(&result, 0, sizeof(result));
		
	}
	
	return 0;
	
}
