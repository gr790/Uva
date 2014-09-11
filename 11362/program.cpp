#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
  freopen("./sample.txt", "r", stdin);
  map<string, int> dict;
  int t;
  scanf("%d\n", &t);
  while(t--) {
    int no;
    scanf("%d\n", &no);
    while(no--)
    {
      string number;
      cin >> number;
      if(!number.empty())
        dict[number]++;
    }
    map<string, int>::iterator it;
    bool found = false;
    for(it = dict.begin(); it != dict.end(); ++it)
    {
      string s = it->first;
      int sz = s.size();
      for(int i = 0; i < sz; ++i) {
        string a = s.substr(0, i);
        if( dict.find(a)!=dict.end())
        {
          cout << "NO" << endl; 
          found = true;
          break;
        }
      }
      if(found)
        break;
    }
    if(!found)
      cout << "YES" << endl;
    dict.clear();
  }
  return 0;
}
