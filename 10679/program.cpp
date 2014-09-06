#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
  freopen("./critical.txt", "r", stdin);
  int test;
  cin >> test;
  cin.ignore();
  while(test--)
  {
    string txt;
    getline(cin, txt);
    int qery;
    cin >> qery;
    while(qery--)
    {
      bool matched = true;
      string q;
      cin >> q;
      cin.ignore();
      int sz = q.size();
      for(int i = 0; i < sz ; ++i)
      {
        if(q[i] != txt[i])
        {
          matched = false;
          break;
        }
      }
      if(matched)
        cout <<"y"<<endl;
      else
        cout <<"n"<<endl;
      q.clear();
    }
  }
  return 0;
}
