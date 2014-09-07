#include <iostream>
#include <string>
#include <stack>
#include <fstream>

using namespace std;

bool prec(char cur)
{
	if( cur == '*' || cur == '/') return 1;
	if( cur == '+' || cur == '-') return 0;
}

bool is_oper(char ch)
{
	if( ch == '*' || ch == '+' || ch == '/' || ch == '-' )
		return true;
	else
		return false;
}

void reverse(string &s, int st, int en)
{
	if( st <= en )
	{
		char ch = s[st];
		s[st] = s[en];
		s[en] = ch;
		reverse(s, ++st, --en);
	}
}


void infix_to_postfix(string &s)
{
	stack<char> output;
	stack<char> oper;
	int len = s.size();

	for(int i = 0; i < len; ++i)
	{
		if( isdigit(s[i]))
			output.push(s[i]);
		else 
		{
			if( s[i] == '(' )
				oper.push(s[i]);
			else if( s[i] == ')')
			{
				while( !oper.empty() && oper.top() != '(')
				{
					output.push(oper.top());
					oper.pop();
				}
				oper.pop();
			}
			else 
			{
#if 0
				if( !oper.empty() && oper.top() != '(' && oper.top() != ')')
				{
#endif
					while( !oper.empty() && is_oper(oper.top()) && (prec(s[i]) < prec(oper.top())) )
					{
						output.push(oper.top());
						oper.pop();
					}
					if( !oper.empty() && is_oper(oper.top()) && (prec(s[i]) == prec(oper.top())) )
					{
						output.push(oper.top());
						oper.pop();
					}
#if 0						
				}
#endif
				oper.push(s[i]);
			}
		}
	}
	while(!oper.empty())
	{
		output.push(oper.top());
		oper.pop();
	}

	string so;
	while(!output.empty())
	{
		so += output.top();
		output.pop();
	}

	reverse(so, 0, so.size()-1);
	cout << so << endl;
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");

	int test;
	infile >> test;
	infile.ignore();
	infile.ignore();
	char ch;
	string s, str;

	int k = 0;
	while(k < test)
	{
		while( getline(infile, str) )
		{
			if(str.size() == 0 )
				break;
			s += str;
		}

		k++;
		infix_to_postfix(s);

		if( k != test)
			cout << endl;

		str.clear();
		s.clear();
	}

	return 0;
}
