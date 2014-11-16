#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, int> oper;
void pop_op()
{
	oper.insert(make_pair("<", 1));
	oper.insert(make_pair(">", 1));
	oper.insert(make_pair("<=", 1));
	oper.insert(make_pair(">=", 1));
	oper.insert(make_pair("=", 1));
}

int to_int(string &vt)
{
	int len = vt.size();
	int j = 0;
	int val = 0;
	for(int i = 0; i < len; ++i)
	{
		if(vt[i] != '.')
			val = (val * 10) + (vt[i] - '0');
	}

	return val;
}

bool check_guess(int val, string &op, int final_value)
{
	if( op == "<")
		return (val < final_value);
	else if( op == ">")
		return (val > final_value);
	else if( op == "<=")
		return (val <= final_value);
	else if( op == ">=")
		return (val >= final_value);
	else
		return (val == final_value);
}

int main()
{
	int parties, guess;
	ifstream infile;
	infile.open("./sample.txt");
	
	infile >> parties >> guess;
	map<string, float> party;
	while(parties--)
	{
		string name,votep;
		infile >> name >> votep;	
		int val = to_int(votep);	
		party.insert(make_pair(name, val));
	}
	pop_op();

	infile.ignore();
	int k = 0;
	while(k < guess)
	{
		k++;
		string line;
		getline(infile, line);	
		stringstream ss;
		ss << line;
		string symb, op;
		int val = 0, final_value = 0;
		while(!ss.eof())
		{
			ss >> symb;
			if(party[symb])
				val += party[symb];
			else if (oper[symb])
				op = symb;
			else
				final_value = to_int(symb) * 10;
		}
		bool is_true = check_guess(val, op, final_value);
		if(is_true)
			printf("Guess #%d was correct.\n", k);
		else
			printf("Guess #%d was incorrect.\n", k);
	}
	
	return 0;
	
}
