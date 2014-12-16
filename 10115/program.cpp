#include <bits/stdc++.h>
using namespace std;
vector<pair<string, string> > tbl;
void replace_all(string &line, const string &from, const string &to)
{
  if(from.empty())
    return;
  size_t pos = 0;
  while( (pos=line.find(from, pos))!=string::npos)
  {
    line.replace(pos, from.size(), to);
  }
}
int main()
{
  freopen("./sample.txt", "r", stdin);
  int num;
  while(cin >> num)
  {
    cin.ignore();
    if(!num)
      break;
    while(num--)
    {
      string org, rep;
      getline(cin, org); getline(cin, rep);
      tbl.push_back(make_pair(org, rep));
    }
    string line;
    getline(cin,line);
    vector<pair<string, string> >::iterator it;
    for(it=tbl.begin(); it!=tbl.end(); ++it)
    {
      replace_all(line, it->first, it->second);
    }
    cout << line << endl;
    tbl.clear();
  }
  return 0;
} 
