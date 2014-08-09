#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  int a, b, c, d;
  while( cin >> a >> b >> c >> d)
  {
    if ( !a && !b && !c && !d )
    {
      break;
    }
    int tot = 0;
    tot += 720; /* 2 full turn */
  
    /* if dialing is increasing, nothing to do..*/
    if(a > b)
      tot += (a-b)*9; /* 9 is degree, 360/40 */
    else
      tot += (40-abs(a-b))*9; /* going clock wise, but dial number is decreasing.., count it as counter clockwise..same as other counter below. */
  
    tot += 360; /* another 1 full turn */

    if(c > b)
      tot += (c-b)*9;
    else  
      tot += (40-abs(c-b))*9;

    if(c > d)
      tot += (c-d)*9;
    else
      tot += (40-abs(c-d))*9;

    
    cout << tot << endl;
    
  }
  
  return 0;
}
