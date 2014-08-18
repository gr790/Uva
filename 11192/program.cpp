#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void reverse(string &s, int t, int e)
{
  if(t < e)
  {
    char m = s[t];
    s[t] = s[e];
    s[e] = m;
    reverse(s, ++t, --e);
  }   
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int g;
  string s;
  while(cin >> g >> s)
  {
    if(!g) break;
    int sz = s.size();
    int gr = (int)sz/g;
    int st, en;
    st = 0;
    en = gr;
    while(g--)
    {
      reverse(s, st, en-1);
      st = en;
      en += gr;
    }
    cout << s << endl;
  }
  return 0;
}
