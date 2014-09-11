#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
typedef long long int llint;

bool valueComp(const char &lhs, const char &rhs)
{
  return (lhs>rhs);
}

llint inc(llint num)
{
  string s = to_string(num);
  sort(s.begin(), s.end(), valueComp);
  return stoi(s, NULL, 10);
  
}

llint dec(llint num)
{
  string s = to_string(num);
  sort(s.begin(), s.end());
  return stoi(s, NULL, 10);
}

int main()
{
  freopen("./critical.txt", "r", stdin);
  string s;
  while(cin >> s)
  {
    if(s == "0") break;
    cout <<"Original number was " << s << endl;
    map<int, int> tbl;
    int cnt = 0;
    llint num = stoi(s,NULL,10);
    while(true)
    {
      llint i_num = inc(num);
      llint d_num = dec(num);
      llint diff = i_num - d_num; 
      cout << i_num <<" - "<< d_num <<" = " << diff << endl;
      tbl[diff]++;
      cnt++;
      if(tbl[diff] > 1)
        break;
      num = diff;
    }
    cout <<"Chain length "<< cnt << endl;
    putchar('\n');
    tbl.clear();
  }
  return 0;
}
