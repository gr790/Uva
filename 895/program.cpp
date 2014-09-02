#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

vector<string> dict;
map<string, int> map_dict;
void reformat(string &line)
{
  int sz = line.size();
  int j = 1;
  for(int i = 1; i < sz; ++i)
  {
    if(isalpha(line[i]))
      line[j++] = line[i];
  }
  line.resize(j);
}

int main()
{
  freopen("./critical.txt", "r", stdin);
  string word;
  while(cin>>word)
  {
    if(word[0]=='#')
      break;
    if(word.size() <= 7)
    {
      dict.push_back(word);
      map_dict[word]++;
    }
  }
  sort(dict.begin(), dict.end());
  cin.ignore();
  string line;
  while(getline(cin, line))
  {
    if(line[0] == '#')
      break;
    reformat(line); 
    sort(line.begin(), line.end());
    map<string,int> key;
    do
    {
      int sz = line.size();
      for(int i = 0; i < sz; ++i)
      {
        string s = line.substr(i, sz);
        if(!key[s])
          key[s]++;
      }
    }while(next_permutation(line.begin(),line.end()));

    int cnt = 0;
    map<string, int>::iterator it;
    for(it = key.begin(); it != key.end(); ++it)
    {
      if(binary_search(dict.begin(), dict.end(), it->first))
      {
          if(map_dict[it->first] > 1)
            cnt += map_dict[it->first];
          else
            cnt++;
      }
    }
    cout << cnt << endl;
    key.clear();
    line.clear();
  }
  return 0;
}
