#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;
int main()
{
  freopen("./critical.txt", "r", stdin);
  string line;
  char ch;
  bool moe = false;
  while( !cin.eof())
  {
    getline(cin, line);
    if(line[0] == '_' )
    {
      if( moe == false)
      {
        moe = true;
        continue;
      }
      else
        break;
    }
    
    int sz = line.size();
    int j = 0, val = 0;
    for(int i = sz-1; i > 0; --i)
    {
      if ( line[i] == 'o')
          val += pow(2,j++);
      else if ( line[i] == ' ')
          j++;
    }
    if( val==13)
      cout << endl;
    else
      printf("%c", val);
    line.clear();
  }
  return 0;
}
