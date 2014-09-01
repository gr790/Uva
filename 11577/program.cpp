#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
std::map<char, int> freq;
int main()
{
  freopen("./sample.txt", "r", stdin);
	int n;
  cin >> n ;
  cin.ignore();
  string line;
  while(getline(cin, line))
  {
    int sz = line.size();
    for(int i = 0; i < sz; ++i)
    {
		  if(isalpha(line[i]))
			  freq[tolower(line[i])]++;
    }

	  map<char, int>::const_iterator it;
    int max = 0;
	  for(it = freq.begin(); it != freq.end(); ++it)
    {
      if ( it->second > max )
       max = it->second;
    }

	  for(it = freq.begin(); it != freq.end(); ++it)
    {
      if ( it->second == max )
		    cout <<it->first;
    }
    cout << endl;
    line.clear();
    freq.clear();
	}

	return 0;
}
