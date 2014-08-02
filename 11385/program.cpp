#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
#define C(x)	( (x >= 'A' && x <= 'Z') ? x : 0)
#define U(x)	( (x >= 'a' && x <= 'z') ? (x-32) : x)
unsigned long long int table[47];
map<unsigned long long int, int> enc;
typedef pair<long long int, char> mypair;
void fab()
{
  table[0] = 1;
	table[1] = 1;
	table[2] = 2;
	enc.insert(make_pair(0,1));
	enc.insert(make_pair(1,1));
	enc.insert(make_pair(2,2));
	for(int i = 3; i < 47; ++i)
	{
		table[i] = table[i-1] + table[i-2];
		enc.insert(make_pair(table[i],i));
	}
}
void process_text(string &s)
{
	int len = s.size();
	int j = 0;
	for(int i = 0; i < len; ++i)
	{
		if(C(s[i]))
			s[j++] = s[i];
	}
	s.resize(j);
}

void create_output(string &s, int pos, char ch)
{
  int i;
  for(i =0; i < pos-1; i++)
  {
    if(!isalpha(s[i]) && s[i] != ' ')
      s += ' ';  
  }
  s += ch;
}

int main()
{
  ifstream infile;
  infile.open("./sample.txt");
	fab();
	int test;
	infile >> test;
	infile.ignore();
	while(test--)
	{
		int N, num;
		string line;
		vector<int> v;
		infile >> N;
		infile.ignore();
    for(int i = 0; i < N; ++i)
    {
      infile >> num;
      v.push_back(num);
    }

		infile.ignore();
		string text;
		getline(infile, text);

		process_text(text);

		int len = text.size();

		map<int, char> final;
		int i,j;
		for(i = 0, j = 0; i < len && j < v.size(); ++i, ++j)
		{
			char ch = text.at(i);
			int val = v.at(j);
			int in = enc.find(val)->second;
			if(C(ch))
			{
				if(in)
					final.insert(make_pair(in, U(ch)));
      }
		}

		char ch = ' ';
    while( i == len && j < v.size() )
    {
      int val = v.at(j);
      int in = enc.find(val)->second;
      final.insert(make_pair(in, ' '));
      j++;
    }

		map<int, char>::iterator it;
    string s;
		for(it = final.begin(); it != final.end(); ++it)
		{
      create_output(s, it->first, it->second);
		}
    cout << s << endl;
		final.clear();
		text.clear(); v.clear(), s.clear();
	}

	return 0;
}
