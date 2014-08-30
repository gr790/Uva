#include <iostream>
#include <map>
#include <string.h>
#include <fstream>
using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  map<char, int> table;
  map<char, int> dup;
  table['B'] = 1, table['U'] = 10, table['S'] = 100, table['P'] = 1000;
  table['F'] = 10000, table['T'] = 100000, table['M'] = 1000000;
  int t = 0;
  scanf("%d\n", &t);
  while(t--)
  {
    bool inc, dec, error;
    inc = dec = error = false;
    char line[501] = {0};
    scanf("%s\n", line);
    int sz = strlen(line); 
    unsigned long num  = 0;
    num += table[line[0]];
    dup[line[0]]++;
    for(int i = 1; i < sz; ++i)
    {
      if( table[line[i]] > table[line[i-1]])  
      {
        inc = true;
        num += table[line[i]];
      }
      else if (table[line[i]] == table[line[i-1]])
      {
        num += table[line[i]];
      }
      else
      {
        dec = true;
        num += table[line[i]];
      }
      dup[line[i]]++;
      if( (inc && dec) || dup[line[i]] > 9 )
      {
        error = true;
        break;
      }
    }
    if(!error)
      printf("%d\n", num);
    else
      printf("error\n");
    dup.clear();
  }
  return 0;
  
}
