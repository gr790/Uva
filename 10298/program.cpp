#include <bits/stdc++.h>
using namespace std;
int main()
{
  freopen("./critical.txt", "r", stdin);
  string line;
  while( cin >> line)
  {
    if( line[0] == '.')
      break;
    string ins = line;
    int sz = line.size();
    int power = 0;
    for(int i = 1; i <= sz; ++i)
    {
      if( sz % i == 0) /* i is length of substring */ 
      {
        power = sz/i; /* How many such substring are there in string */ 
        bool match = true;
        for(int j = 0; j < i; ++j) /* that's my pattern */
        {
          for(int k = j+i; k < sz; k += i) /* That's my string, increment by pattern length */
          {
            if( line[k] != line[j])
            {            
              match = false;
              break;
            }
          }
        }
        if(match)
          break;
      }
    }
    cout << power << endl;
  }
  return 0;
}
