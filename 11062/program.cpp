#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
using namespace std;
#define L(ch) ( (ch >= 'A' && ch <= 'Z')? (ch+32):ch)
string tolower(const string &s)
{
  string rs;
  int sz = s.size();
  for(int i =0; i < sz; ++i)
    rs += L(s[i]);
  return rs;
}
int main()
{
  freopen("./critical.txt", "r", stdin);
  map<string, int> dict;
  string line;
  string save_word = "";
  while(!cin.eof() && getline(cin, line))
  {
    line += '\n';
    int sz = line.size();
    line.resize(sz+1);
    string word = "";
    for(int i = 0; i < sz; ++i)
    { 
      if(isalpha(line[i]))
        word += line[i];
      else if ( line[i] == '-')
      {
        /* if '-' found */
        int j = i; 
        if(line[++j] == ' ') /* if next to '-' is space, then '-' is part of word */
          word +=  line[i];
        else if(line[j] == '\n') /* we need to check the next word too, hyphented word it is */
        {
          save_word += word; 
          word.clear();
          break;
        }
        else if(isalpha(line[j])) /* if next char is alpha, add '-' to current word */
          word += line[i];
      }
      else if (ispunct(line[i]) || isspace(line[i]) || line[i] == '\0') /*  if char is space or eol, this is the end of word */
      {
        if(!save_word.empty())
        {
          save_word += word;
          dict[tolower(save_word)]++;
          word.clear();
          save_word.clear();
        }
        else
        {
          if(!word.empty())
            dict[tolower(word)]++;
          word.clear();
        }
      }
    }
  }
  map<string, int>::iterator it;
  for(it = dict.begin(); it != dict.end(); ++it)
    cout << it->first << endl;
  return 0;
}
