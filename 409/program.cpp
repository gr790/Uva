#include <iostream>
#include <vector>
#include <fstream>
#include <map>
using namespace std;
map<string, int> tbl;
string to_lower(string &lhs)
{
  string str;
  int sz = lhs.size();
  for(int i =0; i < sz; ++i)
    str += tolower(lhs[i]);
  return str;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int n, qry, set = 0;
  while( cin >> n >> qry )
  {
    string word;
    while(n--)
    {
      cin >> word;
      tbl[to_lower(word)]++;
    }
    cin.ignore();
    vector<pair<string, int> > final;
    int max = 0;
    while(qry--)
    {
      string line;
      int found = 0;
      bool in_word = false;
      string w = "";
      getline(cin, line);
      int sz = line.size();
      for(int i = 0; i < sz; ++i)
      {
        if(isalpha(line[i]))
        {
          w += line[i];
          if(!in_word)
            in_word = true;
        }
        else
        {
          if(in_word)
            in_word = false;
        }
        if(!in_word)
        {
          if(tbl[to_lower(w)])
            found++;
          w.clear();
        }
      }
      final.push_back(pair<string, int>(line,found));
      if( found > max )
        max = found;
      line.clear();
    }
    printf("Excuse Set #%d\n", ++set);
    vector<pair<string, int> >::iterator it;
    for(it = final.begin(); it != final.end(); ++it)
    {
        if( it->second == max)
          cout << it->first << endl;
    }
    final.clear();
    tbl.clear();
    cout << endl;
  }
  return 0;
}
