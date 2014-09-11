#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
  freopen("./sample.txt", "r", stdin);
  map<string, int> dict;
  string word;
  while(!cin.eof())
  {
    cin >> word;
    if(!word.empty())
      dict[word]++;
  }
  map<string, int>::iterator it;
  for(it = dict.begin(); it != dict.end(); ++it)
  {
    string s = it->first;
    int sz = s.size();
    for(int i = 0; i < sz; ++i)
    {
      string a = s.substr(0, i);
      string b = s.substr(i);
      if( dict.find(a)!=dict.end() && dict.find(b)!=dict.end())
      {
        cout << s << endl; 
        break;
      }
    }
  }
  return 0;
}
