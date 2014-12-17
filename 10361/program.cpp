#include <bits/stdc++.h>
using namespace std;
int main()
{
  freopen("./critical.txt", "r", stdin);
  int t;
  scanf("%d\n", &t);
  while(t--)
  {
    string l1 = "";
    getline(cin, l1);
    int sz = l1.size();
    for(int i = 0; i < sz; ++i)
    {
      if( l1[i] != '<' && l1[i] != '>')
        cout << l1[i];
    }
    cout << endl;
    string s2 = "", s3 = "", s4 = "", s5 = "";
    int i = 0;
    for(; i < sz; ++i)
    {
      if(l1[i] == '<')
        break;
    }
    for( i++; i < sz && l1[i]!='>'; ++i)
      s2 += l1[i];
    for( i++; i < sz && l1[i]!='<'; ++i)
      s3 += l1[i];
    for( i++; i < sz && l1[i]!='>'; ++i)
      s4 += l1[i];
    for( i++; i < sz; ++i)
      s5 += l1[i];
    
    string l2 = "";
    getline(cin, l2);
    size_t pos = l2.find("...");
    l2.replace(l2.begin()+pos, l2.end(), s4);
    l2 += s3 += s2 += s5;
    cout << l2 << endl;
  }
  return 0;
}
