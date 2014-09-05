#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

map<string, string> tbl;

bool is_vowel(char ch)
{
  if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return true;
  return false;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int L, N;
  cin >> L >> N;
  cin.ignore();
  while(L--)
  {
    string first, second;
    cin >> first >> second;
    tbl[first] = second;
  }
  cin.ignore();
  while(N--)
  {
    string word;
    cin >> word;
    if(!tbl[word].empty())
      cout << tbl[word];
    else
    {
      int sz = word.size();
      if( word[sz-1] == 'y')
      {
        if( is_vowel(word[sz-2]))
          cout << word.insert(sz, "s");
        else
        {
          word.erase(sz-1);
          cout << word.insert(sz-1, "ies");
        }
      }
      else if ( word[sz-1] == 'o' || word[sz-1] == 's' || word[sz-1] == 'x')
      {
        cout << word.insert(sz, "es");
      }
      else if ( (word[sz-1] == 'h' && word[sz-2] == 'c') || (word[sz-1] == 'h' && word[sz-2] == 's') || word[sz-1] == 'x')
      {
        cout << word.insert(sz, "es");
      }
      else 
        cout << word << 's';
    }
    cout << endl;
  }
  return 0;
}
