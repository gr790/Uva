#include <iostream>
#include <fstream>
#include <string.h>
#include <map>
using namespace std;

map<char, char> mymap;

void create_map(string &plain, string &sub)
{
  int psz = plain.size();
  for(int i = 0; (i < psz); ++i)
  {
    mymap[plain[i]] = sub[i];
  }
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int test;
  scanf("%d\n", &test);

  while(test--)
  {
    char ch;
    string plain, sub;
    while( (ch=getchar())!='\n')
      plain += ch;
    
    while( (ch=getchar())!='\n')
      sub += ch;

    cout << sub << endl;
    cout << plain << endl;

    create_map(plain, sub);

    while((ch=getchar())!=EOF)
    {
      if(ch == '\n')
      {
        /* print newline */
        putchar(ch);
        /* check if next char is new line or not */
        ch = getchar();
        if(ch == '\n')
        {
          /* if new line, break, start with next test case */
          putchar(ch);
          break;
        }
        if(ch == EOF)
          break;
      }
      /* if it is not newline, check if it is alphabet */
      if(mymap[ch])
        putchar(mymap[ch]);
      else
        putchar(ch);
    }
    mymap.clear();
    plain.clear(); sub.clear();
  }
  return 0;
}
