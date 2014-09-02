#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;
bool valueComp(const string &lhs, const string &rhs)
{
  string comb1 = lhs + rhs;
  string comb2 = rhs + lhs;
  if( strcmp(comb1.c_str(), comb2.c_str()) < 0)
    return false;
  else
    return true;
}
int main()
{
  freopen("./sample.txt", "r", stdin);
  int num;
  while(cin >> num)
  {
    cin.ignore();
    if(!num) break;
    string val;
    vector<string> vs;
    while(num--)
    {
      cin >> val;
      vs.push_back(val);
    }
    sort(vs.begin(), vs.end(), valueComp);
    vector<string>::iterator it;
    string str = "";
    for(it = vs.begin(); it != vs.end(); ++it)
      str += *it;
    cout << str << endl;
  }
  return 0;
}
