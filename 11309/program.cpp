#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int rev(int num)
{
  int i = 0;
  while(num)
  {
    i = (i*10)+num%10;
    num /= 10;
  }
  return i;
}

int get_next(int num)
{
  /* check max time */
  if( num == 2359) return 0;
  int hr = num/100;
  int mn = num%100;
  if(mn == 60) 
  {
    mn = 0;
    hr += 1;
  }
  else {
    mn += 1;
  }
  return (hr*100)+mn;
}

string to_str(int num)
{
  string h;
  if(!(num/10))
  {
    h = '0';
    h += (num+'0');
  }
  else {
    h = (num/10)+'0';
    h += (num%10)+'0';
  }
  return h;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--)
  {
    int hr, mn;
    scanf("%d:%d\n", &hr, &mn);
    bool found = true;
    while(found)
    {
      int time = (hr*100)+mn;
      time = get_next(time);
      hr = time/100; 
      mn = time%100;

      /* e.g : 00.12 or 00.44 */
      if(hr == 0) { 
        int x = mn/10;
        if(!x){
          found = true;
          break;
        }
        else {
          if(mn == rev(mn)) {
            found = true;
            break;
          }
        }
      }
      /* e.g: 01:11, 02:45 */
      if(time == rev(time))
      {
        found = true;
        break;
      }
    }
    cout << to_str(hr) << ':' << to_str(mn) << endl;
  }
  return 0;
}
