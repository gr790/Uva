#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
bool process( string &str)
{
	stack<char> s;
	bool extra = false;
	int len = str.size();
	for(int i=0; i < len; ++i)
	{
		switch(str[i])
		{
			case '(':
				s.push(str[i]);
				break;
			case '{':
				s.push(str[i]);
				break;
			case '[':
				s.push(str[i]);
				break;
			case ')':
				if( !s.empty() )
				{
					if(s.top() == '(')
						s.pop();
				}
				else
					extra = true;
				break;
			case '}':
				if( !s.empty() )
				{
					if(s.top() == '{')
						s.pop();
				}
				else
					extra = true;
				break;
			case ']':
				if( !s.empty() )
				{
					if(s.top() == '[')
						s.pop();
				}
				else
					extra = true;
				break;
			default:
				break;
		}
		if(extra)	/* don't process further */
			break;
	}
	if(extra)
		return !extra;
	else
		return s.empty();
}

int main()
{

	unsigned int lines;
  freopen("./sample.txt", "r", stdin);

	cin >> lines;
        cin.ignore();

	while(lines--)
        {
                string lstr;
                getline(cin, lstr);


		bool flag = process(lstr);

		if(flag)
			cout <<"Yes";
		else
			cout <<"No";

		cout << endl;
	}

	return 0;
}
