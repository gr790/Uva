#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  int t;
  scanf("%d\n", &t);
  while(t--)
  {
    /* read days from input */
    int days;
    cin >> days; 
    int *n = new int[days+1]; /* start count from 1 instead of 0 */

    /* Max value in terms of days */
    for(int i = 1; i <= days; ++i)
    {
      /* these days are holiday, ignore them */
      if( ((i%7) == 6) || (i%7 == 0))
        n[i] = 1; /* 1 seperats them from working days, count it as holiday */
      else
        n[i] = -1; /* working days */
    }
    /* read no of parties from input */
    int parties;
    cin >> parties;
    /* max of 100 parties are allowed */
    int p[100] = {0};
    for(int i = 0; i < parties; ++i)
    {
      /* read them from input */
      int val;
      cin >> val;
      p[i] = val;
    }
    for(int i = 0; i < parties; ++i)
    {
      for(int j = 1; j <= days; ++j)
      {
        /* -1 indicate this days is unused as of now */
        /* p[i] indicate hartals days for party p[i] */
        if(n[j] == -1 && j%p[i] == 0)
          n[j] = -2; /* set it to -2, indicate it used by party p[i] */
      }
    }
    int cnt = 0;
    for(int i = 1; i <= days; ++i)
    {
      if(n[i] == -2)
        cnt++;
    }
    cout << cnt << endl;
    delete []n;
  }
 
  return 0;
} 
