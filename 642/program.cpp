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
      char un[7];
      scanf("%s\n", un);
      string unscr(un); 
      if( unscr == "XXXXXX")
        break;
      sort(unscr.begin(), unscr.end());
      bool found = false;
      do
      {
        if(dict[unscr])
        {
          printf("%s\n", unscr.c_str());
          found = true;
        }
      }while(next_permutation(unscr.begin(), unscr.end()));
      if(!found)
        puts("NOT A VALID WORD");
      puts("******"); /* end of list for 1 word */
    }
    break;
  }
  return 0;
}
