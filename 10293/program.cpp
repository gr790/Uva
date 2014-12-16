#include <bits/stdc++.h>
using namespace std;
map<int, int> tbl;
bool is_sep(char ch)
{
  if( isblank(ch) || ch == '?' || ch == '!' || ch == ',' || ch == '.')
    return true;
  return false;
}
int word_size(string &word)
{
  int sz = word.size();
  int cnt = 0;
  for(int i = 0; i < sz; ++i)
  {
    if(!ispunct(word[i]))
      cnt++;
  }
  return cnt;
}
int main()
{
  freopen("./sample.txt", "r", stdin);
  char ch;
  string word;
  while( (ch=getchar())!=EOF)
  {
    if( ch == '#')
    {
      map<int,int>::iterator it;
      for(it = tbl.begin(); it != tbl.end(); ++it)
        cout << it->first <<' '<< it->second << endl;
      tbl.clear();
      cout << endl;
      continue;
    }
    else
    {
      if(is_sep(ch) || ch == '\n')
      {
        int len = word_size(word);
        if( len > 0)
          tbl[len]++;
        word.clear();
      }
      else if( isalpha(ch))
        word += ch;
      else if( ch == '-')
      {
        char nc = getchar();
        if( nc == '\n')
          continue;
        else
           word += nc;
      }
    }
  }
  return 0;
}
