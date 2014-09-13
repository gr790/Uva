#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

string reformat(string line)
{
  sort(line.begin(), line.end());
  int sz = line.size();
  string s;
  for(int i = 0; i < sz; ++i)
  {
    if(!isspace(line[i]))
      s += line[i];
  }
  return s;
  
}
int main()
{
  freopen("./sample.txt", "r", stdin);
  int t;
  scanf("%d\n", &t);
  while(t--)
  {
    vector<string> words;
    multimap<string, string> dict;
    while(true)
    {
      string line;
      getline(cin, line);
      if(line.empty())
        break;
      words.push_back(line);
      dict.insert(pair<string, string>(line,reformat(line))); /* remove the spaces from the line */
    }

    sort(words.begin(), words.end());
    vector<string>::iterator vit;
    multimap<string, string>::iterator top = dict.begin();
    multimap<string, string>::iterator mit;
    for(vit = words.begin(); vit != words.end(); ++vit)
    {
      string s = *vit;
      ++top;
      mit = top;
      for(; mit != dict.end(); ++mit)
      {
        /* compare the value with other val in dictionary, if found, print their keys */
        if(dict.find(s)->second == mit->second)
          cout << s <<" = "<< mit->first << endl;
      }
    }
    if(t)
      cout << endl;
    words.clear();
    dict.clear();
  }
  return 0;
}
