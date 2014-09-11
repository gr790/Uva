#include <iostream>
#include <map>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  map<string, string> dict;
  while(!cin.eof())
  {
    string eng, oth, line;
    while(getline(cin, line))
    {
      if(line.empty())
        break;
      stringstream ss;
      ss << line;
      ss >> eng >> oth;
      dict[oth] = eng;
    }
    string word;
    while(cin >> word)
    {
      map<string, string>::iterator it;
      it = dict.find(word);
      if(it != dict.end())
        cout << dict[word] << endl;
      else
        cout << "eh" << endl;
    }
    break;
  }
  return 0;
}
