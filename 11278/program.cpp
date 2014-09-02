#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

string left_qt = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
string rht_qt = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
string left_dvo = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'";
string right_dvo = "~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";

map<char, char> tbl;

int main()
{
  freopen("./sample.txt", "r", stdin);
  char ch;

  int sz = left_qt.size();
  for(int i = 0; i < sz ; ++i)
    tbl[left_qt[i]] = left_dvo[i];
  sz = rht_qt.size();
  for(int i = 0; i < sz ; ++i)
    tbl[rht_qt[i]] = right_dvo[i];
  
  while( (ch=getchar())!=EOF)
  {
    if( tbl[ch])
      putchar(tbl[ch]);
    else
      putchar(ch);
  }
  return 0;
}
