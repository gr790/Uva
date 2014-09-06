#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  freopen("./sample.txt", "r", stdin);
  string line;
  string save_word = "";
  while( getline(cin, line))
  {
    if(line == "#")
      break;
    int sz = line.size();
    line += '\n';
    line.resize(sz+1);
    string word = "";
    bool in_word = false;
    for(int i = 0; i < sz+1; ++i)
    {
      if(isalpha(line[i]))
      {
        word += line[i];
      }
      else if ( line[i] == '-')
      {
        i++;
        if( line[i] == '\n')
        {
          save_word = word;
          putchar('\n');
          break;
        }
      }
      else if (isspace(line[i]) || line[i] == '\0')
      {
        if(!save_word.empty())
        {
          save_word += word;
          cout << save_word << endl << line[i];
          save_word.clear();
        }
        else
          cout << word << line[i];
        word.clear();
      }
    }
  }
  return 0;
}
