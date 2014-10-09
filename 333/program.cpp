#include <bits/stdc++.h>
using namespace std;
string reformat(string &line)
{
  string s;
  int sz = line.size();
  for(int i = 0; (i < sz); ++i)
  {
    if(isdigit(line[i]) || line[i] == 'X')
      s += line[i];
  }
  return s;
}
bool is_correct(string &s)
{
  int sz = s.size();
  if(sz != 10)
    return false;
  if( s[sz-1] != 'X' && !isdigit(s[sz-1]))
    return false;
  for(int i = 0; i < sz-1; ++i)
    if(!isdigit(s[i]))
      return false;
  
  int *s1 = new int[sz]; 
  s1[0] = s[0]-'0';
  for(int i = 1; i < sz; ++i)
  {
    if(isdigit(s[i]))
      s1[i] = (s[i]-'0') + s1[i-1];
    else if(s[i] == 'X')
      s1[i] = 10 + s1[i-1];
  }
  int sum = 0;
  for(int i = 0; i < sz; ++i)
    sum += s1[i];

  if(sum%11 == 0)
    return true;
  return false;
}

string trim_space(string &line)
{
  string s;
  string::const_iterator b = line.begin(), e = line.end();
  while(isblank(*b))
    ++b;
  if( b != e)
  {
    while(isblank(*(e-1)))
      --e;
  }
  s.assign(b, e);
  return s;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  string line;
  while(getline(cin, line))
  {
    string s = trim_space(line);
    string fmt = reformat(s);
    if(!is_correct(fmt))
      cout << s <<" is incorrect." << endl;
    else
      cout << s <<" is correct." << endl;
  }
  return 0;
}
