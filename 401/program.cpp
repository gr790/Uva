#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

char mirr[][2] = { 
		   {'A', 'A'},
                   {'E', '3'},
                   {'H', 'H'},
                   {'I', 'I'},
                   {'J', 'L'},
                   {'L', 'J'},
                   {'M', 'M'},
                   {'O', 'O'},
                   {'S', '2'},
                   {'T', 'T'},
                   {'U', 'U'},
                   {'V', 'V'},
                   {'W', 'W'},
                   {'X', 'X'},
                   {'Y', 'Y'},
                   {'Z', '5'},
                   {'0', '0'},
                   {'1', '1'},
                   {'2', 'S'},
                   {'3', 'E'},
                   {'5', 'Z'},
                   {'8', '8'}
                };

int find_index(char ch)
{
        int i = 0;
        while( i < (sizeof(mirr)/2)-1)
        {
                if( mirr[i][0] == ch )
                        return i;
                i++;
        }

        return -1;
}

bool is_palin(string &s)
{
        int len = s.size();
        if( len < 2 ) return true;
        for( int i = 0; i < (int)len/2; ++i)
        {
                if( s[i] != s[len-i-1])
                        return false;
        }
        return true;
}

bool is_mirror(string &s)
{

        int len = s.size();
        if( len < 2 ) return false;
        for( int i = 0; i < (int)len/2; ++i)
        {
		int ind = find_index(s[len-i-1]);
		if( ind < 0 ) return false;
                if( (s[i] != mirr[ind][1]) ) 
                {
                        return false;
                }
        }

        return true;
}

int main()
{
        string lstr;
        ifstream infile;
        infile.open("./sample.txt");
	bool mirror, palin;
	mirror = palin = false;
	vector<string> vs;

        while( infile >> lstr )
        {
		vs.push_back(lstr);
		lstr.clear();
	}

	vector<string>::iterator iter;
	for(iter = vs.begin(); iter != vs.end(); ++iter)
	{
		string s = *iter;
		palin = is_palin(s);
		mirror = is_mirror(s);

		if( palin && mirror)
			cout << s <<" -- is a mirrored palindrome." << endl;
		else if(mirror && !palin)
			cout << s <<" -- is a mirrored string." << endl;
		else if(palin  && !mirror)
			cout << s <<" -- is a regular palindrome." << endl;
		else if(!palin && !mirror)
			cout << s <<" -- is not a palindrome." << endl;

		cout << endl;
        }

        return 0;
}
