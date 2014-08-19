#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

bool is_vowel(char ch)
{
  if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'H' || ch == 'W' || ch == 'Y')
    return true;
  else
    return false;
}

int main()
{
  map<char, int> mymap;
  mymap['B'] = mymap['F'] = mymap['P'] = mymap['V'] = 1;
  mymap['C'] = mymap['G'] = mymap['J'] = mymap['K'] = mymap['Q'] = mymap['S'] = mymap['X'] = mymap['Z'] = 2;
  mymap['D'] = mymap['T'] = 3;
  mymap['L'] = 4;
  mymap['M'] = mymap['N'] = 5;
  mymap['R'] = 6;
  
  freopen("./sample.txt", "r", stdin);
  string str;
  while(cin >> str)
  {
    int sz = str.size();
    int i = 0;
    if(!is_vowel(str[i]))
      cout << mymap[str[i]];
    for(i = 1; i < sz; ++i)
    {
      if( str[i] == str[i-1]) 
          continue;
      else if ( !is_vowel(str[i]) && (mymap[str[i]] == mymap[str[i-1]]))
          continue;
      else
      {
        if( !is_vowel(str[i])) 
          cout << mymap[str[i]];
      }
    }
    cout << endl;
  }
  return 0;
}
