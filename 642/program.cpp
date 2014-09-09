#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>
using namespace std;
int main()
{
  freopen("./sample.txt", "r", stdin);
  map<string, int> dict;
  while(!cin.eof()) {
    string word;
    while(true) {
      cin >> word;
      if( word == "XXXXXX")
        break;
      if(!dict[word])
        dict[word]++;
    } 
    while(true) {
      string unscr;
      cin >> unscr;
      if( unscr == "XXXXXX")
        break;
      sort(unscr.begin(), unscr.end());
      bool found = false;
      do
      {
        if(dict[unscr])
        {
          cout << unscr << endl;
          found = true;
        }
      }while(next_permutation(unscr.begin(), unscr.end()));
      if(!found)
        cout << "NOT A VALID WORD" <<endl;
      cout << "******" << endl; /* end of list for 1 word */
    }
    break;
  }
  return 0;
}
