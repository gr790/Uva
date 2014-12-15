#include <bits/stdc++.h>
using namespace std;
/* This function return the count of pattern matches in the input string */
map<int, int> tbl;
int count_pattern(const char *test, const char *subStr)
{
  int cnt = 0;
  const char* pCurrent = strstr( test, subStr );
  while( pCurrent != NULL )
  {
    pCurrent+=strlen(subStr);
    cnt++;
    pCurrent = strstr( pCurrent, subStr );
  }
  return cnt;
}
int main()
{
  freopen("./sample.txt", "r", stdin);
  int t;
  scanf("%d\n", &t);
  while(t--)
  {
    string line;
    cin >> line;
    cin.ignore();
    string ins = line;
    int sz = line.size();
    int m = INT_MAX;
    int psize;
    for(int i = 0; i < sz; ++i)
    {
      string pattern = line.substr(0,i+1);
      psize = pattern.size();
      int cnt = count_pattern(ins.c_str(), pattern.c_str());
      if( (cnt * psize) == sz )
      {
        if( psize < m) 
          m = psize;
      }
    }
    cout << m << endl;
    if(t)
      cout << endl;
  }
  return 0;
}
