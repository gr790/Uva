#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void decode(vector<string> &vs, int k)
{
	bool is_ok = true;
	vector<string>::iterator it;
	for(it = vs.begin(); it != vs.end(); ++it)
	{
		vector<string>::iterator jt;
		for(jt = vs.begin(); jt != vs.end(); ++jt)
		{
			if( it != jt)
			{
				string s = *it;
				string t = *jt;
				if(s.substr(0, t.size()) == t)
				{
					is_ok = false;
					break;
				}
			}
		}
		if(!is_ok)
			break;
	}
	if(is_ok)
		printf("Set %d is immediately decodable\n", k);
	else
		printf("Set %d is not immediately decodable\n", k);
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	vector<string> vs;

	string codes;
	int k = 0;
	while( !infile.eof())
	{
		infile >> codes;
		cout <<" codes : " << codes << endl;
		if(codes[0] != '9')
			vs.push_back(codes);
		else
		{
			k++;
			decode(vs, k);
		}
		codes.clear();
	}

	return 0;
}
