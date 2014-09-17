#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

string reformat(string line)
{
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
    vector<pair<string, string> > dict;
    int dict_size;
    cin >> dict_size;
    getchar();
    string line;
    while(dict_size--)
    {
      getline(cin, line);
      if(line.empty())
        break;
      reformat(line); /* remove extra spaces or punct char */
      string tmp = line;
      sort(tmp.begin(), tmp.end());
      dict.push_back(pair<string, string>(line, tmp)); /* remove the spaces from the line */
      line.clear();
    }
    /* read the words, for which we need to search their combincation in dict */
    string org;
    while(getline(cin, org))
    {
      string words;
      /* end of 1 data set */
      if(org == "END")
        break;
      words = org;
      /* sort the words to generate the correct sequence of next permutation */
      sort(words.begin(), words.end());
      bool found = false;
      printf("Anagrams for: %s\n", org.c_str());  
      int cnt = 0;
      vector<pair<string, string> >::iterator it;
      for(it = dict.begin(); it != dict.end(); ++it)
      {
        if(it->second == words)
        {
          cnt++;
          if(!found)
            found = true;
          printf("%3d) %s\n", cnt, it->first.c_str());
        }
      }
      if(!found)
        printf("No anagrams for: %s\n", org.c_str());
      words.clear();
      org.clear();
    }
    if(t)
      cout << endl;
    dict.clear();
  }
  return 0;
}
